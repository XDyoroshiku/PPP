export module Test_output;

import PPP;
using namespace std;

export void Test_output()
{
	constexpr int birth_year = 2003;
	cout << showbase << "deciml: "  << birth_year << '\t'
		<< "heximal: " << hex << birth_year << '\t'
		<< "octal: " << oct << birth_year << '\n';
	cout << "age: " << dec << 23 << '\n';
}