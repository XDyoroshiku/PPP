export module Money;

import <climits>;
import PPP;
using namespace std;

export class Money;
export ostream& operator<<(ostream& os, const Money m);

class Money
{
public:
	Money(double);										// 参数单位为美元
	Money(const string&, double);						// 参数：货币，美元
	long get_cents() const { return cents; }
	string get_currency() const{ return currency; }
private:
	long cents;											// 存储美分
	string currency = "$";								// 默认货币为USD

	bool valid_money(double) const;
	long exchange(double) const;
};

Money::Money(double dollars)
{
	if (!valid_money(dollars))
		PPP::error("invalid money");
	cents = exchange(dollars);
}

Money::Money(const string& c, double dollars)
{
	if (!valid_money(dollars))
		PPP::error("invalid money");
	currency = c;
	cents = exchange(dollars);
}

bool Money::valid_money(double money) const
// 检验money是否小于LONG_MAX。若大于，在转换时会溢出
{
	constexpr double max_dollars = LONG_MAX / 100.0;				// 比较时，LONG_MAX被隐式转换为double类型
	return -max_dollars < money && money < max_dollars;
}

long Money::exchange(double dollars)const
// 美元转换成美分，并四舍五入
{
	constexpr double round = 0.5;									// 用于配合浮点数向整数的转换，实现四舍五入
	constexpr double exchange_rate = 100.0;							// 美元换成美分的兑换率
	const int multiplier = (dollars < 0) ? -1 : 1;					// 用于配合实现四舍五入。如果是正数，转换时要+0.5；是负数，转换时-0.5
	return static_cast<long>(dollars * exchange_rate + round * multiplier);
}

ostream& operator<<(ostream& os, Money m)
{
	const long cent = abs(m.get_cents() % 100);						// m可能为负数。对负数取模，结果带有负号
	const long dollar = m.get_cents() / 100;
	return os << m.get_currency() << dollar << '.' << (cent < 10 ? "0" : "") << cent;
}
