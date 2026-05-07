// 设计和实现一个有理数类(rational number class)，Rational
// 有理数有两部分：一个分子(numerator)，一个分母(denominator)(e.g., 5/6)
// 提供 '=', '+', '-', '*', '/', '==' 操作符
// 提供向double类型的转换

export module Ex_13;

import Rational;
import PPP;
using namespace std;

export void Ex_13();

void Ex_13()
{
	Rational r1{ 6, 8 };
	Rational r2 = r1;
	cout << "r1 = " << r1 << '\t' << "r2 = " << r2 << '\n';
	cout << "double(r1) == " << r1.to_double() << '\t' << "double(r2) == " << r2.to_double() << '\n';
	cout << "r1 + r2 = " << r1 + r2 << '\n'
		<< "r1 - r2 = " << r1 - r2 << '\n'
		<< "r1 * r2 = " << r1 * r2 << '\n'
		<< "r1 / r2 = " << r1 / r2 << '\n'
		<< "r1 == r2 ?: " << ((r1 == r2) ? "yes" : "no") << '\n';
}