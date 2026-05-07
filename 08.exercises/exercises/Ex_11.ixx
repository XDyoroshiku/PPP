// 为Date类设计和实现辅助函数：next_workday()，week_of_year()。
// 工作日：星期一——星期五
// 第一周：第一周的第一天是星期天；一月一日需要在这周内（第一周的第一天可能在上一年）；

export module Ex_11;

import Date;
import PPP;
using namespace std;

export void Ex_11();

void Ex_11()
{
	using enum Month;
	Date d1{ Year{2026}, May, 01 };
	Date d2{ Year{2026}, May, 02 };
	Date d3{ Year{2026}, May, 03 };
	Date d4{ Year{2026}, May, 04 };

	cout << d1 << '\t' << d1.day_of_week() << '\t' << "next workday: " << next_workday(d1) << '\n'
		<< d2 << '\t' << d2.day_of_week() << '\t' << "next workday: " << next_workday(d2) << '\n'
		<< d3 << '\t' << d3.day_of_week() << '\t' << "next workday: " << next_workday(d3) << '\n'
		<< d4 << '\t' << d4.day_of_week() << '\t' << "next workday: " << next_workday(d4) << '\n';

	Date d5{ Year{2026}, January, 1 };
	Date d6{ Year{2026}, January, 5 };
	Date d7{ Year{2025}, December, 28 };
	Date d8{ Year{2025}, December, 25 };
	cout << d5 << '\t' << "week of year: " << week_of_year(d5) << '\n'
		<< d6 << '\t' << "week of year: " << week_of_year(d6) << '\n'
		<< d7 << '\t' << "week of year: " << week_of_year(d7) << '\n'
		<< d8 << '\t' << "week of year: " << week_of_year(d8) << '\n';
}