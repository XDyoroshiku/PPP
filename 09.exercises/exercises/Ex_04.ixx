// 写一个程序，它提示用户输入几个整数。
// 它们可以是十进制，八进制（以0为前缀），十六进制（以0x为基本前缀）。
// 正确识别这些数字，把它们转换为10进制。
// 按所给格式输出。

export module Ex_04;

import PPP;
using namespace std;

export void Ex_04();

enum class base {decimal, octal, hexadecimal, not_a_base};

const vector<string> s_base{ "decimal", "octal", "hexadecimal", "not_a_base" };

struct base_num
{
	base b = base::not_a_base;
	string num;
	int value = -9999;
};

int base_to_int(base b)
{
	return static_cast<int>(b);
}

string base_to_string(base b)
{
	return s_base[base_to_int(b)];
}

base int_to_base(int b)
{
	return base{ b };
}

static constexpr int hexadecimal = 2;
static constexpr int octal = 1;
static constexpr int decimal = 0;

int determine_prefix(const string& s)
// 根据字符串的进制前缀返回不同的值。
// 无前缀返回0；
// 0前缀返回1；
// 0x或0X前缀返回2；
{
	static constexpr char prefix_0 = '0';
	static constexpr char prefix_x = 'x';
	static constexpr char prefix_X = 'X';
	istringstream is{ s };
	if (s[0] == prefix_0 && 1 < s.size())
	{
		if (s[1] == prefix_X || s[1] == prefix_x)
			return hexadecimal;
		else
			return octal;
	}
	else
		return decimal;
}

base_num get_base_num(const string& s)
// 返回base_num类型
{
	int int_base = determine_prefix(s);

	const string num = s.substr(int_base);		// 获取字符串不包括进制前缀的数字部分
	istringstream is{ num };
	int value;
	switch (int_base)							// 根据进制给value输入对应的十进制值
	{
	case hexadecimal:
		is >> hex >> value;
		break;
	case octal:
		is >> oct >> value;
		break;
	case decimal:
		is >> dec >> value;
		break;
	default:
		PPP::error("something's wrong when trying to input value");
	}
	if (!is)
		return base_num{ base::not_a_base };
	return base_num{ base{int_base}, s, value };
}

ostream& operator<<(ostream& os, const base_num& bn)
{
	return os << bn.num << '\t' << base_to_string(bn.b) << '\t' << "converts to" << '\t' << bn.value << '\t' << "decimal";
}

void Ex_04()
// 输入字符串
// 判断是否是前缀+数字的形式
// 是：转换成自定义类型存入数组（进制+字符串+值）；不是：重新输入
// 输出自定义类型数组
{
	cout << "Please enter a few integers in any combination of octal(using prefix 0), decimal, or hexadecimal(using prefix 0x)." << '\n'
		<< "Type 'finished' to end input" << '\n';
	const string finished = "finished";
	vector<base_num> inputs;
	string input;
	while (cin >> input)
	{
		if (input == finished)
			break;
		base_num bn = get_base_num(input);
		if (bn.b == base::not_a_base)
			cout << input << " is not in correct form, please try again." << '\n';
		else
			inputs.push_back(bn);
	}

	for (const base_num& x : inputs)
		cout << x << '\n';
}