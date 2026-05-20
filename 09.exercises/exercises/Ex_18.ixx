// 写一个程序，从前一个练习的生成的raw_temps.txt读取数据
// 把读取的数据存入数组
// 计算平均温度和温度读数的中位数

// Ex_19
// 修改Ex_17，温度读数后添加后缀c，代表摄氏度；后缀f，代表华氏摄氏度。
// 修改Ex_18，测试每个读数，在把读数存入数组前，把摄氏度转换为华氏摄氏度。

export module Ex_18;

import functions;
import Ex_17;
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
	vector<double> temperatures;
	for (Reading x : readings)
		temperatures.push_back(x.temperature);
	sort(temperatures.begin(), temperatures.end());
	const int nums = static_cast<int>(temperatures.size());
	if (nums % 2 == 1)
		return temperatures[(nums - 1)/ 2];
	else
		return (temperatures[nums / 2 - 1] + temperatures[nums / 2]) / 2;
}

void Ex_18()
{
	const string iname = "exercises/Ex_17_raw_temps.txt";
	vector<Reading> readings;
	fill_from_file(readings, iname);
	cout << "mean temperature: " << get_mean(readings) << '\n'
		<< "median temperature: " << get_median(readings) << '\n';
}