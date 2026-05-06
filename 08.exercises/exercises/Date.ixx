// Edit of Date classes from Chapter 8, 08.drill, 08.exercises-12.

export module Date;

import <ctime>;
import PPP;
using namespace std;

export class Date;
export struct r_date;
export class Year;
export enum class Month;
export Date get_today();
export bool leapyear(int);
export ostream& operator<<(ostream& os, const Date& d);


// 天
class Day
{
public:
	Day(int dd) : day{ dd } {};
	int return_day() const { return day; }
private:
	int day;
};

// 周
enum class Week{ Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

// 月
enum class Month{ January = 1, February, March, April, May, June, July, August, September, October, November, December };

// 年
class Year
{
public:
	Year(int yy) : year{ yy } {}
	int return_year() const { return year; }
private:
	int year;
};

int Month_to_int(Month m)
// Month类型转换为int类型（都是数字，只是类型不同）
{
	return static_cast<int>(m);
}

Month int_to_Month(int int_m)
// check conversion
{
	if (int_m < Month_to_int(Month::January) || Month_to_int(Month::December) < int_m)
		PPP::error("bad month");
	return Month{ int_m };
}

int days_of_month(int int_m, int y)
// 大月返回31，小月返回30，2月返回28或29
{
	Month m = int_to_Month(int_m);
	using enum Month;
	if (m == February)
	{
		if (leapyear(y))
			return 29;
		else
			return 28;
	}
	else if ((m == April) || (m == June) || (m == September) || (m == November))
		return 30;
	else
		return 31;
}

int days_of_year(int y)
// 闰年返回366；平常年份返回365
{
	if (leapyear(y))
		return 366;
	else
		return 365;
}

// 判断年份是否是闰年(能被4整除；能被400整除；只被100整除不行)
bool leapyear(int y){ return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }

struct r_date
{
	int year;
	int month;
	int day;
};

class Date
{
public:
	Date(Year, Month, int);
	r_date get_date() const;
	void add_day(int n);
private:
	long days;

	static constexpr int year_zero = 1970;			// Day 0: 1970.1.1
	static constexpr int month_zero = 1;
	static constexpr int day_zero = 1;
	long days_before_day0(Year y, Month m, int d) const;	
	bool is_valid(Year y, Month m, int d) const;
};

Date::Date(Year y, Month m, int d)
// Date的构造函数
{
	if (!is_valid(y, m, d))
		PPP::error("Invalid Date");
	days = days_before_day0(y, m, d);
}

bool Date::is_valid(Year y, Month m, int d) const
// 检验Date是否有效
{
	int int_m = Month_to_int(m);
	return (year_zero < y.return_year()) 
		&& (0 < int_m) && (int_m < 13) 
		&& (0 < d) && (d <= days_of_month(int_m, y.return_year()));
}

long Date::days_before_day0(Year y, Month m, int d) const
// 计算传入日期距1970.1.1有多少天
{
	long days = 0;
	// 加上这个月已经过去的天数
	days += d - day_zero;

	// 加上这一年已经过去的月份的天数
	for (int int_m = Month_to_int(m); month_zero < int_m; --int_m)
		days += days_of_month(int_m - 1, y.return_year());			// 加上过去一个月的天数

	// 依次加上1970年以后到今年，每年的天数
	for (int int_y = y.return_year(); year_zero < int_y; --int_y)
		days += days_of_year(int_y - 1);					// 加上过去一年的天数
	return days;
}

r_date Date::get_date() const
// 根据距day0的天数，返回对应的年份、月份、日期
{
	r_date rd;
	// 计算年份
	int current_year = year_zero;
	long left_days = days;
	int days_of_current_year = days_of_year(current_year);
	while (days_of_current_year <= left_days)				// 剩下天数大于等于今年总天数，年份加一，剩下天数减去今年总天数
	{
		left_days -= days_of_current_year;
		++current_year;
		days_of_current_year = days_of_year(current_year);
	}
	rd.year = current_year;
	// 计算月份
	int current_month = month_zero;
	int days_of_current_month = days_of_month(current_month, current_year);
	while (days_of_current_month <= left_days)				// 剩下天数大于等于当月总天数，月份加一，剩下天数减去当月总天数
	{
		left_days -= days_of_current_month;
		++current_month;
		days_of_current_month = days_of_month(current_month, current_year);
	}
	rd.month = current_month;
	// 计算日期
	const int current_day = day_zero + left_days;			// 一号加上剩下天数
	rd.day = current_day;
	return rd;
}

void Date::add_day(int n){ days += n; }

ostream& operator<<(ostream& os, const Date& d)
{
	r_date rd = d.get_date();
	return os << rd.year << '/' << rd.month << '/' << rd.day;
}

Date get_today()
// 返回Date类型的今天
{
	//// 1. 获取当前时间的时间戳
	//time_t now = std::time(nullptr);

	//// 2. 将时间戳转换为本地时间的 tm 结构体
	//tm local_time;
	//::localtime_s(&local_time, &now);

	//// 3. 从 tm 结构体中提取年、月、日
	//// 注意：年份是从1900年开始计算的，月份范围是 0-11
	//const int year = local_time.tm_year + 1900;
	//const int month = local_time.tm_mon + 1;
	//const int day = local_time.tm_mday;

	//return Date{ Year{year}, int_to_Month(month), day };

	return Date{ Year{2026}, Month::May, 06 };
}