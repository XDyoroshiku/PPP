export module Date;

import <ctime>;
import PPP;
using namespace std;

export class Date;
export Date get_today();
export enum class Month;
export ostream& operator<<(ostream& os, const Date& d);
export bool leapyear(int);

// Edit of Date classes from Chapter 8 and 08.drill
class Day
{
public:
	Day(int dd) : day{ dd } {};
	int return_day() const { return day; }
private:
	int day;
};

enum class Month{ January = 1, February, March, April, May, June, July, August, September, October, November, December };

class Year
{
public:
	Year(int yy) : year{ yy } {}
	int return_year() const { return year; }
private:
	int year;
};

class Date
{
public:
	Date(Year, Month, int);
	int year() const { return y.return_year(); }
	int month() const { return static_cast<int>(m); }
	int day() const { return d.return_day(); }
	Date add_day();
private:
	Year y;
	Month m;
	Day d;

	bool is_valid();
};

Date::Date(Year yy, Month mm, int dd) : y{ yy }, m{ mm }, d{ Day(dd) }
{
	if (!is_valid())
		PPP::error("Invalid Date");
}

bool Date::is_valid()
{
	int mm = static_cast<int>(m);
	return ((day() > 0) && (day() < 32)) && ((mm > 0) && (mm < 13));
}

Date Date::add_day()
{
	Date new_d(year(), m, day());
	if (day() == 31)
	{
		new_d.d = 1;
		if (month() == 12)
		{
			new_d.m = Month::January;
			new_d.y = year() + 1;
		}
		else
			new_d.m = Month(month() + 1);
	}
	else
		new_d.d = day() + 1;
	return new_d;
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << d.year() << '/' << d.month() << '/' << d.day();
}

Date get_today()
{
	// 1. 获取当前时间的时间戳
	time_t now = std::time(nullptr);

	// 2. 将时间戳转换为本地时间的 tm 结构体
	tm local_time;
	::localtime_s(&local_time, &now);

	// 3. 从 tm 结构体中提取年、月、日
	// 注意：年份是从1900年开始计算的，月份范围是 0-11
	const int year = local_time.tm_year + 1900;
	const int month = local_time.tm_mon + 1;
	const int day = local_time.tm_mday;

	return Date{year, Month(month), day };
}

bool leapyear(int y)
// 判断年份是否是闰年(能被4整除；能被400整除；只被100整除不行)。
{
	return ((y % 4 == 0) && !(y % 100 == 0)) || (y % 400 == 0);
}