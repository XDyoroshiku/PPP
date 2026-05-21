// 定义Roman_int类，保存罗马数字且定义<<和>>操作符
// 为这个类提供as_int()成员函数。它返回对象的int值。

export module Ex_21;

import PPP;
using namespace std;

export void Ex_21();
export string get_Roman_numerals(istream& is);
export class Roman_int;
export string int_to_Roman(int r);

class Roman_int
{
public:
	Roman_int(const string& s) : numerals{ s } {};
	int as_int() const;
	void set_numerals(const string& s) { numerals = s; }
	string get_numerals() const { return numerals; }
private:
	string numerals;
};

int numeral_to_int(char ch)
// 返回单个罗马符号对应的整数值
{
	static constexpr char I = 'I';
	static constexpr char V = 'V';
	static constexpr char X = 'X';
	static constexpr char L = 'L';
	static constexpr char C = 'C';
	static constexpr char D = 'D';
	static constexpr char M = 'M';
	switch (ch)
	{
	case I:
		return 1;
	case V:
		return 5;
	case X:
		return 10;
	case L:
		return 50;
	case C:
		return 100;
	case D:
		return 500;
	case M:
		return 1000;
	default:
		PPP::error("invalid numeral");
		return -1;
	}
}

bool valid_numeral(char ch)
// 检查字符是否是罗马符号
{
	static const vector<char> Roman_numerals{ 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	for (char x : Roman_numerals)
		if (ch == x)
			return true;
	return false;
}

int Roman_int::as_int() const
// 左边的符号 < 右边的符号 -> 减法
// 左边的符号 >= 右边的符号 -> 加法
// 也就是每一位和后一位比较，比它小，这一位就是负数；反之则是正数。最后一位总是正数。
{
	int sum = 0;
	const int length = static_cast<int>(numerals.size());
	if (length == 0)
		PPP::error("empty numerals");
	for (int i = 0; i < length - 1; ++i)
	{
		const int current = numeral_to_int(numerals[i]);
		const int next = numeral_to_int(numerals[i + 1]);
		if (current < next)
			sum -= current;
		else
			sum += current;
	}
	sum += numeral_to_int(numerals[length - 1]);				// 加上最后一位。
	return sum;
}

istream& operator>>(istream& is, Roman_int& r)
{
	string s;
	is >> s;
	if (!is)
		PPP::error("something went wrong when input to a Roman_int");
	for (char x : s)
		if (!valid_numeral(x))
			PPP::error("invalid character for Roman_int");
	r.set_numerals(s);
	return is;
}

ostream& operator<<(ostream& os, const Roman_int& r)
{
	return os << r.get_numerals() << '\t' << r.as_int();
}

void Ex_21()
{
	string s;
	cin >> s;
	Roman_int r{s};
	cout << r;
}

string get_Roman_numerals(istream& is)
{
	string s;
	for (char ch; is.get(ch); )
	{
		if (!valid_numeral(ch))
		{
			is.putback(ch);
			return s;			// 返回所有是罗马符号的字符
		}
		s.push_back(ch);
	}
	return s;
}

string int_to_Roman(int r)
{
	static constexpr int M = 1000;
	static constexpr int D = 500;
	static constexpr int C = 100;
	static constexpr int L = 50;
	static constexpr int X = 10;
	static constexpr int V = 5;
	static constexpr int I = 1;
	string numerals;

	const int m = r / M;
	for (int i = 0; i < m; ++i)
		numerals.push_back('M');
	r %= M;

	const int d = r / D;
	for (int i = 0; i < d; ++i)
		numerals.push_back('D');
	r %= D;

	const int c = r / C;
	for (int i = 0; i < c; ++i)
		numerals.push_back('C');
	r %= C;

	const int l = r / L;
	for (int i = 0; i < l; ++i)
		numerals.push_back('L');
	r %= L;

	const int x = r / X;
	for (int i = 0; i < x; ++i)
		numerals.push_back('X');
	r %= X;

	const int v = r / V;
	for (int i = 0; i < v; ++i)
		numerals.push_back('V');
	r %= V;

	const int ii = r / I;
	for (int i = 0; i < ii; ++i)
		numerals.push_back('I');
	r %= I;

	return numerals;
}

// This couldn't return "IX", but would return "XIIII".
// Tired to make more improvements.