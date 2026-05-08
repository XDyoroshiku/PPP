// 设计和实现Money类，用于包含美元和美分的精确到美分的最后一位的算术（四舍五入）
// 用long int类型的美分数表示金钱总额
// 但类的输入和输出要同时使用美元和美分（e.g.,$123.45）

export module Ex_14;

import Money;
import PPP;
using namespace std;

export void Ex_14()
{
	using enum Currency;
	Money m1(-1.055);
	Money m2(2.333);
	cout << "m1 = " << m1 << '\n'
		<< "m2 = " << m2 << '\n'
		<< "(m1 == m2)? " << (m1 == m2 ? "yes" : "no") << '\n'
		<< "m1 + m2 = " << m1 + m2 << '\n'
		<< "m1 - m2 = " << m1 - m2 << '\n';
}