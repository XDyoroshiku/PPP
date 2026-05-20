// 写一个程序
// 它创建一个文件，里面的数据使用9.3.2定义的Reading的格式
// 输入至少50个Reading进入raw_temps.txt

export module Ex_17;

import PPP;
using namespace std;

export void Ex_17();

struct Reading
{
	int hour;
	double temperature;
};

double get_random_temperature(const int min, const int max)
// 生成100倍的整数随机数，再除以100，得到两位小数
{
	constexpr int multiplier = 100;		
	static default_random_engine engine(1);
	uniform_int_distribution<int> dist(min * multiplier, max * multiplier);
	double temperature = PPP::narrow_cast<double>(dist(engine)) / multiplier;
	return temperature;
}

vector<Reading> generate(const int nums, const int min, const int max)
{
	constexpr int hours = 24;
	vector<Reading> readings;
	for (int i = 0; i < nums; ++i)
	{
		int hour = i % hours;
		Reading r{ hour, get_random_temperature(min, max) };
		readings.push_back(r);
	}
	return readings;
}

ostream& operator<<(ostream& os, Reading r)
{
	return os << r.hour << ' ' << r.temperature;
}

void input_Readings(const vector<Reading>& readings, const string& fname)
{
	ofstream ofs(fname);
	for (Reading r : readings)
		ofs << r << '\n';
	if (!ofs)
		PPP::error("something went wrong when input to file: " + fname);
}

void Ex_17()
{
	constexpr int num_of_readings = 55;
	constexpr int temperature_min = 50;
	constexpr int temperature_max = 70;
	const string fname = "exercises/Ex_17_raw_temps.txt";
	vector<Reading> random_readings = generate(num_of_readings, temperature_min, temperature_max);
	input_Readings(random_readings, fname);
}