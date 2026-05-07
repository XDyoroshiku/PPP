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
	//Date d4{ 1900, Month(3), 31 };		// invalid Date, but welcome to try running it.
	Date d5{ 2100, Month(3), 31 };
	r_date rd1 = d1.get_date();
	r_date rd2 = d2.get_date();
	r_date rd3 = d3.get_date();
	//r_date rd4 = d4.get_date();
	r_date rd5 = d5.get_date();
	cout << "is " << rd1.year << " a leapyer? " << ((leapyear(rd1.year) == 1) ? "yes" : "no") << '\n';
	cout << "is " << rd2.year << " a leapyer? " << ((leapyear(rd2.year) == 1) ? "yes" : "no") << '\n';
	cout << "is " << rd3.year << " a leapyer? " << ((leapyear(rd3.year) == 1) ? "yes" : "no") << '\n';
	//cout << "is " << rd4.year << " a leapyer? " << ((leapyear(rd4.year) == 1) ? "yes" : "no") << '\n';
	cout << "is " << rd5.year << " a leapyer? " << ((leapyear(rd5.year) == 1) ? "yes" : "no") << '\n';
}
