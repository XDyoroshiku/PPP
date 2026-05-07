// 创建一个Patron类。
// 这个类有用户名、图书馆卡号、费用，三个成员。
// 创建三个函数，获取三个成员的值。
// 创建一个函数，设置用户的费用。
// 创建辅助函数，根据用户是否欠费返回bool类型的值。

export module Ex_08;

import PPP;
import Patron;
using namespace std;

export void Ex_08()
{
	Patron p1{ "Huxley", 100001 };
	p1.set_fees(100);
	cout << p1;
	Patron p2{ "Orwell", 100002 };
	p2.set_fees(-100);
	cout << p2;
}
