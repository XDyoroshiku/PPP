// 修改Money类，添加货币作为构造函数的参数。

export module Ex_15;

import Money;
import PPP;
using namespace std;

export void Ex_15()
{
	using enum Currency;
	Money m1{ CNY, 648.6486 };
	Money m2{ USD, 1.233 };
	Money m3{ DKK, 5.00 };
	cout << m1 << '\n'
		<< m2 << '\n'
		<< m3 << '\n'
		<< m1 + m2 << '\n';
}