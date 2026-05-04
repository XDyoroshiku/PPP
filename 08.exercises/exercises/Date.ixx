export module Date;

import PPP;
using namespace std;

export class Date;
export Date get_today();

// Date class in 8.drill
class Day
{
public:
	Day(int dd) : day{ dd } {}
	int return_day() const { return day; }
private:
	int day;
};

enum class Month
{
	January = 1, February, March, April, May, June, July, August, September, October, November, December
};

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
	Date(int, Month, int);
	int year() const { return y.return_year(); }
	int month() const { return static_cast<int>(m); }
	int day() const { return d.return_day(); }
	bool is_valid();
	Date add_day();
private:
	Year y;
	Month m;
	Day d;
};

Date::Date(int yy, Month mm, int dd) : y{ Year(yy) }, m{ mm }, d{ Day(dd) }
{
	if (!is_valid())
		PPP::error("Invalid initialization");
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
	std::time_t now = std::time(nullptr);

	// 2. 将时间戳转换为本地时间的 tm 结构体
	std::tm* local_time = std::localtime(&now);

	// 3. 从 tm 结构体中提取年、月、日
	// 注意：年份是从1900年开始计算的，月份范围是 0-11
	const int year = local_time->tm_year + 1900;
	const int month = local_time->tm_mon + 1;
	const int day = local_time->tm_mday;

	return Date{year, Month(month), day };
}