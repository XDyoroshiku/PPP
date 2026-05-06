// 改变Date类的实现方式
// Date类使用long int类型，存储以1970年1月1日到现在的天数（这一天是day0）。
// 重新实现8.4.2中Date类的成员函数。
// 不接受day0以前的日期。

export module Ex_12;

import PPP;
using namespace std;

class Year
{
public:
	Year(int yy) :year{ yy } {}
private:
	int year;
};

class Date
{
public:
	//Date(Year, Month, Day);
private:
	long days;
};

export void Ex_12();

