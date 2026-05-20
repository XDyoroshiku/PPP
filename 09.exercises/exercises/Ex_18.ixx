// 写一个程序，从前一个练习的生成的raw_temps.txt读取数据
// 把读取的数据存入数组
// 计算平均温度和温度读数的中位数

export module Ex_18;

import functions;
import PPP;
using namespace std;

export void Ex_18();

double get_sum(const vector<Reading>& readings)
{
	double sum = 0;
	for (Reading x : readings)
		sum += x.temperature;
	return sum;
}

double get_mean(const vector<Reading>& readings)
{
	const int nums = static_cast<int>(readings.size());
	const double sum = get_sum(readings);
	const double mean = sum / nums;
	return mean;
}

double get_median(const vector<Reading>& readings)
{
	const int nums = static_cast<int>(readings.size());
	if (nums % 2 == 1)
		return readings[(nums - 1)/ 2].temperature;
	else
		return (readings[nums / 2 - 1].temperature + readings[nums / 2].temperature) / 2;
}

void Ex_18()
{
	const string iname = "exercises/Ex_17_raw_temps.txt";
	vector<Reading> readings;
	fill_from_file(readings, iname);
	cout << "mean temperature: " << get_mean(readings) << '\n'
		<< "median temperature: " << get_median(readings) << '\n';
}