// 实现8.7.5的leapyear(int)

export module Ex_10;

import PPP;
import Date;
using namespace std;

export void Ex_10();

void Ex_10()
{
	Date d1{ 2006, Month(1), 30 };
	Date d2{ 2004, Month(2), 29 };
	Date d3{ 2000, Month(3), 01 };
	Date d4{ 1900, Month(3), 31 };
	cout << "is " << d1.year() << " a leapyer? " << ((leapyear(d1.year()) == 1) ? "yes" : "no") << '\n';
	cout << "is " << d2.year() << " a leapyer? " << ((leapyear(d2.year()) == 1) ? "yes" : "no") << '\n';
	cout << "is " << d3.year() << " a leapyer? " << ((leapyear(d3.year()) == 1) ? "yes" : "no") << '\n';
	cout << "is " << d4.year() << " a leapyer? " << ((leapyear(d4.year()) == 1) ? "yes" : "no") << '\n';
}
