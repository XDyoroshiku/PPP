export module _9_9;

export void _9_9();

import PPP;
using namespace std;

const int not_a_reading = -7777;
const int not_a_month = -1;
constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

// reading示例：
// { year 1990 }
// { year 1991 { month jun } }
// { year 1992 { month jan(1 0 61.5) } { month feb(1 1 64) (2 2 65.2) } }
// {
//	 year 2000
//	 { month feb(1 1 68) (2 3 66.66) (1 0 67.2)}
//	 { month dec(15 15 −9.2) (15 14 −8.8) (14 0 −2) }
// }


struct Reading
{
	int day;
	int hour;
	double temperature;
};

struct Day
{
	vector<double> hour = vector<double>(24, not_a_reading);		//24个元素，每个都是not_a_reading
};

struct Month
{
	int month = not_a_month;
	vector<Day> day = vector<Day>(32);		//"We 'waste' day[0] to keep the code simple."
};

struct Year
{
	int year;
	vector<Month> month = vector<Month>(13);
};

istream& operator>>(istream& is, Reading& r)
// read a temperature reading from is into r. format:( 3 4 9.7 )
// check format, but don’t bother with data validity
// 读取的最小单元。Month和Year的读取都建立在这之上
{
	char ch1;
	if (is >> ch1 && ch1 != '(')
	{
		is.unget();
		is.clear(ios::failbit);
		return is;
	}
	char ch2;
	if ((is >> r.day >> r.hour >> r.temperature >> ch2) && ch2 != ')')
		PPP::error("bad reading");
	return is;
}

int month_to_int(string);
bool is_valid(const Reading&);
void end_of_loop(istream&, char, const string&);

istream& operator>>(istream& is, Month& m)
// read a month from is into m. format: { month feb . . . }
{
	char ch = 0;
	if (is >> ch && ch != '{')
	{
		is.unget();
		is.clear(ios::failbit);
		return is;
	}

	string month_marker;
	string mm;
	is >> month_marker >> mm;
	if (!is || month_marker != "month")
		PPP::error("bad start of month");
	m.month = month_to_int(mm);

	int duplicates = 0;
	int invalids = 0;
	for (Reading r; is >> r;)
	{
		if (is_valid(r))
		{
			if (m.day[r.day].hour[r.hour] != not_a_reading)			
				// 根据reading的day和hour在m的days数组里查找
				// 如果值不是not_a_reading，说明已经往这个元素输入过reading了，这说明有重复项
				++duplicates;
			m.day[r.day].hour[r.hour] = r.temperature;			
			// 这里只存了reading结构的temperature，
			// 因为其day和hour项已经分别通过temperature存在数组month和day中的位置体现出来了。
		}
		else
			++invalids;
	}
	if (invalids)
		PPP::error("invalid readings in month", invalids);
	if (duplicates)
		PPP::error("duplicate readings in month", duplicates);
	end_of_loop(is, '}', "bad end of month");
	return is;
}

istream& operator>>(istream& is, Year& y)
// read a year from is into y. format: { year 1972 ... }
{
	char ch = 0;
	is >> ch;
	if (ch != '{')
	{
		is.unget();
		is.clear(ios::failbit);
		return is;
	}

	string year_marker;
	int yy = -1;
	is >> year_marker >> yy;
	if (!is || year_marker != "year")
		PPP::error("bad start of year");
	y.year = yy;
	
	while (true)
	{
		Month m;		// get a clean m each time around
		if (!(is >> m))
			break;
		y.month[m.month] = m;
	}
	
	end_of_loop(is, '}', "bad end of year");
	return is;
}

void end_of_loop(istream& ist, char term, const string& message)
{
	if (ist.fail())
	{
		ist.clear();
		char ch = 0;
		if (ist >> ch && ch == term)
			return;
		PPP::error(message);
	}
}

bool is_valid(const Reading& r)
{
	if (r.day < 1 || 31 < r.day)
		return false;
	if (r.hour < 0 || 23 < r.hour)
		return false;
	if (r.temperature < implausible_min || implausible_max < r.temperature)
		return false;
	return true;
}

vector<string> month_input_tbl =
{
	"-not a month-",
	"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"
};

int month_to_int(string s)
// is s the name of a month? If so return its index [1:12] otherwise -1
{
	for (int i = 1; i < 13; ++i)
		if (month_input_tbl[i] == s)
			return i;
	return 0;
}

vector<string> month_print_tbl = 
{
		 "−not a month−",
		 "January", "February", "March", "April", "May", "June", "July",
		 "August", "September", "October", "November", "December"
};

string int_to_month(int i)
// months [1:12]
{
	if (i < 1 || 12 < i)
		PPP::error("bad month index");
	return month_print_tbl[i];
}


void read_format()
{
	//open an input file:
	cout << "Please enter input file name" << '\n';
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
		PPP::error("can't open input file", iname);

	ifs.exceptions(ifs.exceptions() | ios::badbit);		// throw for bad()

	// open an output file:
	cout << "Please enter output file name" << '\n';
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs)
		PPP::error("can't open output file", oname);

	// read an arbitrary number of years:
	vector<Year> ys;
	while (true)
	{
		Year y;		// get a freshly initialized Year each time around
		if (!(ifs >> y))
			break;
		ys.push_back(y);
	}
	cout << "read " << ys.size() << " years of readings" << "\n";

	//for (Year& y : ys)
	//	print_year(ofs, y);			//	We leave print_year() as an exercise.
}

void _9_9()
{
	read_format();
}