export module Rational;

import PPP;
using namespace std;

export class Rational;
export Rational operator+(const Rational& left, const Rational& right);
export Rational operator-(const Rational& left, const Rational& right);
export Rational operator*(const Rational& left, const Rational& right);
export Rational operator/(const Rational& left, const Rational& right);
export bool operator==(const Rational& left, const Rational& right);
export ostream& operator<<(ostream& os, const Rational& r);

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

ostream& operator<<(ostream& os, const Rational& r) { return os << r.get_p() << '/' << r.get_q(); }