export module functions;

import PPP;
using namespace std;

export double get_double();
export int get_digit(int num);
export int string_to_int(string);
export bool is_integer(const string&);

// 跳过输入中不是数的部分。
void skip_to_double()
{
	if (cin.fail())
	{                                                   // we found something that wasn’t an integer
		cin.clear();                                             // we’d like to look at the characters
		for (char ch; cin >> ch; )
		{                      // throw away non-digits
			if (isdigit(ch) || ch == '.' || ch == '-')
			{
				cin.unget();                          // put the digit back, so that we can read the number
				return;
			}
		}
	}
	PPP::error("no input");                                           // eof or bad: give up
}

// 从cin获取double类型的数，如果不是数则需要重新输入。
double get_double()
{
	double num = 0;
	while (true)
	{
		if (cin >> num)
			return num;
		cout << "Sorry, that was not a number; please try again " << '\n';
		skip_to_double();
	}
}

int get_digit(int num)
// 获取整数的位数。正负数都可以。
{
	if (num == 0)
		return 1;
	int digit = 0;
	for (; num != 0; ++digit)
		num /= 10;
	return digit;
}

int deal_with_sign(string &s)
// 处理字符串的一个字符。
// 正号返回1；负号返回-1；其他返回0；
{
	switch (s[0])
	{
	case '+' :
		s.erase(0, 1);				// 删除字符串中起始位置为0，长度为1的字符串。
		return 1;
	case '-' :
		s.erase(0, 1);
		return -1;
	default:
		return 0;
	}
}

bool is_integer(const string& s)
// 判断字符串的每个字符拼起来是否是整数。
{
	for (char x : s)
	{
		if (x < '0' || x > '9')
			return false;
	}
	return true;
}

int calculate_string(const string& s)
// 根据十进制数字的定义，从高位到低位，计算字符串的每个字符乘以位权，返回它们的和。
{
	int num = 0;
	const size_t size = s.size();
	int add = 0;
	// 从低位到高位计算。反过来，最高位可以能一开始就导致整数溢出。
	for (size_t i = 0; i < size; ++i)
	{
		add = PPP::narrow_cast<int>(s[i] - '0');
		if ((numeric_limits<int>::max() - add)/10 < num)				// num * 10 + add 可能溢出。
			PPP::error("The string_integer \"" + s + "\" is out of conversion range.");
		num = num * 10 + add;
	}
	return num;
}

int string_to_int(string s)
// 计算string类型的数字，返回其int类型的值。
// conversion range[-2147483647, 2147483647]，can't conver -2147483648.
{
	if (s.empty())
		PPP::error("Can't convert an empty string.");
	// 处理正负号。如果第一个字符为正负号，“把它从s里去除”，存到sign；如果不是，sign为0。
	const int sign = deal_with_sign(s);
	// 检查剩下所有字符是否是'0'到'9'的字符。
	if (!is_integer(s))
		PPP::error("String \"" + s + "\" is not an integer.");
	// 处理剩下的字符串，把其整数值存入num。
	const int num = calculate_string(s);
	// 如果原始字符串没有正负号，直接返回。
	if (sign == 0)
		return num;
	// 如果原始字符串第一个为正负号，返回num*sign。
	else
		return num * sign;
}


