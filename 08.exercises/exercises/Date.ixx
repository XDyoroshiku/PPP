// Edit of Date classes from Chapter 8, 08.drill, 08.exercises-12.

export module Date;

import <ctime>;
import PPP;
import functions;
using namespace std;

export class Date;
export struct r_date;
export class Year;
export enum class Month;
export enum class Week;
export Date get_today();
export Date next_workday(const Date&);
export int week_of_year(const Date&);
export bool leapyear(int);
export ostream& operator<<(ostream& os, const Date& d);
export ostream& operator<<(ostream& os, const Week w);


// 周
enum class Week{ Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

const vector<string> week{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

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

// Date的返回日期结构
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
	void add_day(int n) { days += n; }
	Week day_of_week() const { return Week{ (days % 7 + week_zero) % 7 }; }
	long get_days() const { return days; }
private:
	long int days;

	static constexpr int year_zero = 1970;			// Day 0: 1970.1.1
	static constexpr int month_zero = 1;
	static constexpr int week_zero = 4;				// This day is Thursday.
	static constexpr int day_zero = 1;
	long days_before_day0(Year y, Month m, int d) const;
	bool is_valid(Year y, Month m, int d) const;
};

// declare
int Month_to_int(Month m);
int days_of_month(int int_m, int y);
int days_of_year(int y);

Date::Date(Year y, Month m, int d)
// Date的构造函数
{
	if (!is_valid(y, m, d))
	{
		string rs = int_to_string(y.return_year()) + '/'
				+ int_to_string(Month_to_int(m)) + '/'
				+ int_to_string(d);					// return message.
		PPP::error("Invalid Date: " + rs);
	}
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

int Week_to_int(Week w)
// Week类型转换为int类型
{
	return static_cast<int>(w);
}

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

ostream& operator<<(ostream& os, const Week w)
{
	return os << week[Week_to_int(w)];
}

ostream& operator<<(ostream& os, const r_date& rd)
{
	return os << rd.year << '/' << rd.month << '/' << rd.day;
}

ostream& operator<<(ostream& os, const Date& d)
{
	r_date rd = d.get_date();
	return os << rd;
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

	return Date{ Year{2026}, Month::May, 06 };				// 使用固定日期；使用Windows系统，可以通过上面注释的代码获取当前日期。
}

Date next_workday(const Date& d)
// 返回下一个工作日
{
	Date return_d = d;
	Week current_week = d.day_of_week();
	using enum Week;
	if (current_week == Friday)
		return_d.add_day(3);		// Friday + 3 Days == Monday
	else if (current_week == Saturday)
		return_d.add_day(2);		// Saturday + 2 Days == Monday
	else
		return_d.add_day(1);		// (any other day + 1 Day) is still a workday.
	return return_d;
}

int week_of_year(const Date& d)
// 返回：输入日期是当年的第几周
{
	constexpr int days_of_a_week = 7;
	constexpr int weeks_of_a_year = 52;
	r_date current = d.get_date();
	Date fdy = { Year{current.year}, Month::January, 01 };		// first day of current year
	Week w = fdy.day_of_week();									// get what day the first day of current year is
	int int_w = Week_to_int(w);
	long days_of_fdfw = fdy.get_days() - int_w;					// get the days of the day of the first week.
	long past_days = d.get_days() - days_of_fdfw;				// caluculate how many days have passed since the first day of the first week.
	int week_num = PPP::narrow_cast<int>(past_days / days_of_a_week + 1);		// divide by 7; might return 53.
	return week_num;
}