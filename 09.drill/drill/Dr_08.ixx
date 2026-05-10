export module Dr_08;

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
	cin >> p1;
	cout << p1;
}