export module Patron;

import Money;
import PPP;
using namespace std;

export class Patron;
export ostream& operator<<(ostream& os, const Patron& p);

class Patron
{
public:
	Patron(string, int, double);
	string get_name() const { return name; }
	int get_number() const { return number; }
	Money get_fees() const { return fees; }
	void set_fees(Money f) { fees = f; }
	bool owes_a_fee() const { return fees.get_cents() < 0; }
private:
	string name;
	int number;
	Money fees;
};

Patron::Patron(string s, int num, double f = 0) : name{ s }, number{ num }, fees{ f }
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