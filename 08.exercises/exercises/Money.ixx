export module Money;

import <climits>;
import PPP;
using namespace std;

export enum class Currency;
export class Money;
export ostream& operator<<(ostream& os, Money m);
export ostream& operator<<(ostream& os, Currency c);
export bool operator==(Money m1, Money m2);
export bool operator!=(Money m1, Money m2);
export Money operator-(Money m);
export Money operator+(Money m1, Money m2);
export Money operator-(Money m1, Money m2);
export istream& operator>>(istream& is, Money& m);


enum class Currency{ CNY=1, USD, EUR, GBP, AUD, CAD, DKK };

const vector<string> currencies{ "not a currency", "CNY", "USD", "EUR", "GBP", "AUD", "CAD", "DKK"};

constexpr double exchange_rate = 100.0;		// 注意！一些货币的辅币兑换率不是100。比如"JPY"。

int currency_to_int(Currency c) { return static_cast<int>(c); }

class Money
{
public:
	explicit Money(double);										// 参数单位为美元
	Money(Currency, double);							// 参数：货币，美元
	long get_cents() const { return cents; }
	Currency get_currency() const{ return c; }
private:
	long cents = 0;										// 存储美分
	Currency c = Currency::USD;							// 默认货币为USD

	bool valid_money(double) const;
	long exchange(double) const;
};

Money::Money(double dollars)
{
	if (!valid_money(dollars))
		PPP::error("invalid money");
	cents = exchange(dollars);
}

Money::Money(Currency currency, double dollars) : c{currency}
{
	if (!valid_money(dollars))
		PPP::error("invalid money");
	cents = exchange(dollars);
}

bool Money::valid_money(double money) const
// 检验money是否小于LONG_MAX。若大于，在转换时会溢出
{
	constexpr double max_dollars = LONG_MAX / exchange_rate;		// 比较时，LONG_MAX被隐式转换为double类型
	return -max_dollars < money && money < max_dollars;
}

long Money::exchange(double dollars)const
// 美元转换成美分，并四舍五入
{
	constexpr double round = 0.5;									// 用于配合浮点数向整数的转换，实现四舍五入
	const int multiplier = (dollars < 0) ? -1 : 1;					// 用于配合实现四舍五入。如果是正数，转换时要+0.5；是负数，转换时-0.5
	return static_cast<long>(dollars * exchange_rate + round * multiplier);
}

ostream& operator<<(ostream& os, Money m)
{
	const long cent = abs(m.get_cents() % static_cast<long>(exchange_rate));						// m可能为负数。对负数取模，结果带有负号
	const long dollar = m.get_cents() / static_cast<long>(exchange_rate);
	return os << m.get_currency() << dollar << '.' << (cent < 10 ? "0" : "") << cent;
}

ostream& operator<<(ostream& os, Currency c) 
{ 
	return os << currencies[currency_to_int(c)]; 
}

bool operator==(Currency c1, Currency c2)
{
	return currency_to_int(c1) == currency_to_int(c2);
}

bool operator!=(Currency c1, Currency c2) { return !(c1 == c2); }

bool operator==(Money m1, Money m2)
{
	return (m1.get_currency() == m2.get_currency()) && (m1.get_cents() == m2.get_cents());
}

bool operator!=(Money m1, Money m2) { return !(m1 == m2); }

Money operator-(Money m)
{
	return Money(m.get_currency(), -m.get_cents());
}

Money operator+(Money m1, Money m2)
{
	if (m1.get_currency() != m2.get_currency())
		PPP::error("add different currencies");
	const long sum = m1.get_cents() + m2.get_cents();					// cents都是整数，相加后仍是整数，不需要四舍五入
	const double d_sum = sum / exchange_rate;
	return Money(m1.get_currency(), d_sum);
}

Money operator-(Money m1, Money m2)
{
	if (m1.get_currency() != m2.get_currency())
		PPP::error("subtract different currencies");
	return m1 + (-m2);
}

Currency string_to_Currency(const string& s)
{
	const int size = static_cast<int>(currencies.size());
	for (int i = 0; i < size; ++i)
	{
		if (s == currencies[i])
			return Currency{i};
	}
	PPP::error("currency not supported");
	return Currency{ 0 };
}

istream& operator>>(istream& is, Money& m)
{
	is >> ws;								// 跳过开头的空白
	constexpr int sign_length = 3;			// 货币单位的符号都是三个字符
	string s;
	for (int i = 0; i < sign_length; ++i)
	{
		s.push_back(is.get());
	}
	Currency c = string_to_Currency(s);
	double dollars;
	is >> dollars;
	if (!is)
		return is;
	m = Money{ c, dollars };
	return is;
}
