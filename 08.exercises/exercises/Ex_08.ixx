// 创建一个Patron类。
// 这个类有用户名、图书馆卡号、费用，三个成员。
// 创建三个函数，获取三个成员的值。
// 创建一个函数，设置用户的费用。
// 创建辅助函数，根据用户是否欠费返回bool类型的值。

export module Ex_08;

import PPP;
using namespace std;

export void Ex_08();
export class Patron;
export ostream& operator<<(ostream& os, const Patron& p);

class Patron
{
public:
	Patron(string, int, double);
	string get_name() const { return name; }
	int get_number() const { return number; }
	double get_fees() const { return fees; }
	void set_fees(int f) { fees = f; }
	bool owes_a_fee() const { return fees < 0; }
private:
	string name;
	int number;
	double fees;
};

Patron::Patron(string s, int num, double f = 0) : name{ s }, number{ num }, fees{f}
{
	if (s.size() == 0)
		PPP::error("Empty name");
	if (20 < s.size())
		PPP::error("Name being too long");
	if (num < 100000 || 1000000 < num)
		PPP::error("Bad number");
}

ostream& operator<<(ostream& os, const Patron& p)
{
	return os << "Patron: " 
		<< "name: " << p.get_name() << '\t'
		<< "card number: " << p.get_number() << '\t'
		<< "fees: " << p.get_fees() << '\n';
}

void Ex_08()
{
	Patron p1{ "Huxley", 100001 };
	p1.set_fees(100);
	cout << p1;
	Patron p2{ "Orwell", 100002 };
	p2.set_fees(-100);
	cout << p2;
}
