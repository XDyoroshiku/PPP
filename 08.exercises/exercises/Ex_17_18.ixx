// 给出Rational类在数学计算上比Money类表现更好的例子
// 给出Rational类在数学计算上比double表现更好的例子

export module Ex_17_18;

import Money;
import Rational;
import PPP;
using namespace std;

double ten_times(double d)
{
	double num = 0.0;
	for (int i = 0; i < 10; ++i)
		num += d;
	return num;
}

Rational ten_times(Rational r)
{
	Rational num = { 0, 1 };
	for (int i = 0; i < 10; ++i)
		num = num + r;
	return num;
}

export void Ex_17_18()
{
	Money m1{ 0.375 };
	Money m2{ 0.625 };
	Rational r1{ 3, 8 };
	Rational r2{ 5, 8 };
	cout << "m1 + m2 = " << m1 + m2 << '\n'
		<< "r1 + r2 = " << r1 + r2 << '\n';

	double d1 = 0.1;
	Rational r3 = { 1, 10 };
	cout << "ten times of d1 = " << setprecision(16) << ten_times(d1) << '\n'
		<< "ten times of r3 = " << setprecision(16) << ten_times(r3) << '\n';
}