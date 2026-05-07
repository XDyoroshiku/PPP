// 设计和实现一个有理数类(rational number class)，Rational
// 有理数有两部分：一个分子(numerator)，一个分母(denominator)(e.g., 5/6)
// 提供 '=', '+', '-', '*', '/', '==' 操作符
// 提供向double类型的转换

export module Ex_13;

import PPP;
using namespace std;

export void Ex_13();

class Rational
{
public:
	Rational(int pp, int qq);
	double to_double() const { return double(p) / double(q); }
	Rational& operator=(const Rational& r_value);
	int get_p() const { return p; }
	int get_q() const { return q; }
private:
	int p;				// numerator
	int q;				// denominator

	int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }		// 约分
};



Rational::Rational(int pp, int qq) : p{ pp }, q{ qq }
{
	if (q == 0)
		PPP::error("Rational construct: divide by zero");
	int g = gcd(abs(p), abs(q));
	p /= g;
	q /= g;
	if (q < 0) { p = -p; q = -q; }
}

Rational& Rational::operator=(const Rational& r_value)
{
	p = r_value.p;
	q = r_value.q;
	return *this;
}

Rational operator+(const Rational& left, const Rational& right)
{
	int left_q = left.get_q();
	int right_q = right.get_q();
	return Rational{ left.get_p() * right_q + right.get_p() * left_q, left_q * right_q };
}

Rational operator-(const Rational& left, const Rational& right)
{
	int left_q = left.get_q();
	int right_q = right.get_q();
	return Rational{ left.get_p() * right_q - right.get_p() * left_q, left_q * right_q };
}

Rational operator*(const Rational& left, const Rational& right) { return Rational{ left.get_p() * right.get_p(), left.get_q() * right.get_q() }; }

Rational operator/(const Rational& left, const Rational& right)
{
	if (right.get_p() == 0)
		PPP::error("Rational num divide: divede by 0");
	return Rational{ left.get_p() * right.get_q(), left.get_q() * right.get_p() };
}

bool operator==(const Rational& left, const Rational& right) { return left.get_p() * right.get_q() == left.get_q() * right.get_p(); }

ostream& operator<<(ostream& os, const Rational& r){ return os << r.get_p() << '/' << r.get_q(); }

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