export module Dr_08_17;

import PPP;
using namespace std;

// drill_08
export void Dr_08()
// oct和hex是流操作符，永久改变输入流的进制解析方式
{
	int a, b, c, d;
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
}

// drill_09
export void Dr_09()
{
	constexpr double d = 1234567.89;
	cout << "defaultfloat: " << '\t' << defaultfloat << d << '\n'
		<< "fixed: " << '\t' << fixed << d << '\n'
		<< "scientific" << '\t' << scientific << d << '\n';
}

struct table_message
{
	string last_name;
	string first_name;
	string telephone_number;
	string emailaddress;
};

ostream& operator<<(ostream& os, table_message tm)
{
	return os << tm.first_name << ' ' << tm.last_name << '\t' << '\t' << tm.telephone_number << '\t' << '\t' << tm.emailaddress;
}

export void Dr_10()
{
	table_message me{ "What", "Guess", "11011912000", "123456@qq.com" };
	table_message Orwell{ "Orwell", "George", "01234567890", "741852@qq.com" };
	table_message Aldous{ "Huxley", "Aldous", "55678998332", "654123@qq.com" };
	table_message Crick{ "Crick", "Francis", "45612852493", "953157@qq.com" };
	table_message Dickens{ "Dickens", "Charles", "75395145655", "486248@qq.com" };
	table_message Follet{ "Follet", "Ken", "73914682501", "943167@qq.com" };

	vector<table_message> tm;
	tm.push_back(me);
	tm.push_back(Orwell);
	tm.push_back(Aldous);
	tm.push_back(Crick);
	tm.push_back(Dickens);
	tm.push_back(Follet);

	for (const table_message& x : tm)
		cout << x << '\n';
}

struct Point
{
	int x;
	int y;
};

istream& operator>>(istream& is, Point& p)
{
	int x, y;
	char ch1, ch2, ch3;
	is >> ch1 >> x >> ch2 >> y >> ch3;
	if (!is)
		return is;
	if (ch1 != '(' || ch2 != ',' || ch3 != ')')
	{
		is.clear(ios::failbit);
		return is;
	}
	p.x = x;
	p.y = y;
	return is;
}

ostream& operator<<(ostream& os, Point p)
{
	return os << p.x << "," << p.y;
}

export void Dr_11()
{
	Point p1;
	if(cin >> p1)
		cout << p1;
}

bool operator==(Point p1, Point p2)
{
	if (p1.x != p2.x || p1.y != p2.y)
		return false;
	return true;
}

bool operator!=(Point p1, Point p2)
{
	return !(p1 == p2);
}

void fill_from_file(vector<Point>& points, string& name)
{
	ifstream ist{ name };                  // open file for reading
	if (!ist)
		PPP::error("can't open input file ", name);

	for (Point p; ist >> p;)
		points.push_back(p);
}

export void Dr_12_17()
{
	cout << "Please enter input file name with seven (x, y) pairs." << '\n';
	string iname;
	cin >> iname;				// drill/Dr_12_input.txt
	ifstream ist{ iname };
	if (!ist)
		PPP::error("can't opern input file ", iname);
	
	vector<Point> original_points;
	fill_from_file(original_points, iname);

	for (Point x : original_points)
		cout << x << '\n';

	cout << "Please enter name of output file: " << '\n';
	string oname;
	cin >> oname;				// drill/mydata.txt
	ofstream ost{ oname };
	if (!ost)
		PPP::error("can't open output file ", oname);

	for (Point p : original_points)
		ost << '(' << p.x << ',' << p.y << ")\n";
	cout << "data were put in file: " << oname << '\n';
	//ost.close();

	ifstream ist2{ oname };
	if (!ist2)
		PPP::error("can't open input file ", oname);

	vector<Point> processed_points;
	fill_from_file(processed_points, oname);

	cout << "data elements in vector original_points: " << '\n';
	for (Point x : original_points)
		cout << x << '\n';
	cout << "data elements in vector processed_points: " << '\n';
	for (Point x : processed_points)
		cout << x << '\n';
	
	if (original_points.size() != processed_points.size())
		PPP::error("Something's wrong!");
	else
	{
		for (size_t i = 0; i < original_points.size(); ++i)
		{
			if (original_points[i] != processed_points[i])
				PPP::error("Something's wrong!");
		}
	}
}
