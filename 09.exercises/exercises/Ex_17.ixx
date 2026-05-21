// 写一个程序
// 它创建一个文件，里面的数据使用9.3.2定义的Reading的格式
// 输入至少50个Reading进入raw_temps.txt

export module Ex_17;

import PPP;
using namespace std;

enum class suffix;

export void Ex_17();
export double c_to_f(double celsius);
export suffix char_to_suffix(char ch);
export struct Reading;

export enum class suffix
{
	c, f		// c代表Celsius；f代表Fahrenheit。
};

vector<char> s_suffix{ 'c', 'f'};

export struct Reading
{
	int hour;
	double temperature;
	suffix ts;
};

double c_to_f(double celsius)
// 把摄氏度转换为华氏摄氏度
{
	return celsius * 1.8 + 32.0;
}

suffix int_to_suffix(int i)
{
	constexpr int celsius = 0;
	constexpr int fahrenheit = 1;
	if (i != celsius && i != fahrenheit)
		PPP::error("bad suffix");
	return suffix(i);
}

char suffix_to_char(suffix s)
{
	return s_suffix[static_cast<int>(s)];
}

suffix char_to_suffix(char ch)
{
	constexpr char celsius = 'c';
	constexpr char fahrenheit = 'f';
	if (ch == celsius)
		return suffix(suffix::c);
	else if (ch == fahrenheit)
		return suffix(suffix::f);
	else
	{
		PPP::error("bad char for suffix");
		return suffix{};
	}
	
}

double get_random_temperature(const double min, const double max)
// 生成100倍的整数随机数，再除以100，得到两位小数
{
	static default_random_engine temperature_engine(1);
	constexpr double multiplier = 100.0;
	const int int_min = PPP::narrow_cast<int>(min * multiplier);
	const int int_max = PPP::narrow_cast<int>(max * multiplier);
	uniform_int_distribution<int> dist(int_min, int_max);
	double temperature = PPP::narrow_cast<double>(dist(temperature_engine)) / multiplier;
	return temperature;
}

Reading get_random_reading(const double celsius_min, const double celsius_max)

{
	constexpr int multiplier = 100;
	static const double fahrenheit_min = c_to_f(celsius_min);
	static const double fahrenheit_max = c_to_f(celsius_max);
	static default_random_engine suffix_engine(1);
	uniform_int_distribution<int> dist(0, 1);
	int c_or_f = dist(suffix_engine);
	double temperature;
	if (c_or_f == 0)
		temperature = get_random_temperature(celsius_min, celsius_max);
	else
		temperature = get_random_temperature(fahrenheit_min, fahrenheit_max);
	Reading r{ 0, temperature, suffix{ c_or_f } };
	return r;
}

vector<Reading> generate(const int nums, const double celsius_min, const double celsius_max)
{
	constexpr int hours = 24;
	vector<Reading> readings;
	for (int i = 0; i < nums; ++i)
	{
		int hour = i % hours;
		Reading r = get_random_reading(celsius_min, celsius_max);
		r.hour = i % hours;
		readings.push_back(r);
	}
	return readings;
}

ostream& operator<<(ostream& os, Reading r)
{
	return os << r.hour << ' ' << r.temperature << ' ' << suffix_to_char(r.ts);
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
	constexpr double temperature_min = 5.0;
	constexpr double temperature_max = 40.0;
	const string fname = "exercises/Ex_17_raw_temps.txt";
	vector<Reading> random_readings = generate(num_of_readings, temperature_min, temperature_max);
	input_Readings(random_readings, fname);
}