// 改变Date类的实现方式
// Date类使用long int类型，存储以1970年1月1日到现在的天数（这一天是day0）。
// 重新实现8.4.2中Date类的成员函数。
// 不接受day0以前的日期。

export module Ex_12;

import std;
import Date;
using namespace std;

export void Ex_12()
{
	Date d1{ Year{2026}, Month::May, 06 };
	cout << d1 << '\n';
	d1.add_day(10);
	cout << d1 << '\n';
	d1.add_day(31);
	cout << d1 << '\n';
	d1.add_day(365);
	cout << d1 << '\n';
	d1.add_day(1000);
	cout << d1 << '\n';
}
