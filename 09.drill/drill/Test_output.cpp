export module Test_output;

import PPP;
using namespace std;

export void Test_output()
{
	constexpr int birth_year = 2003;
	cout << "deciml: " << birth_year << '\t'
		<< "heximal: " << hex << birth_year << '\t'
		<< "octal: " << oct << birth_year << '\n';
	cout << "age: " << 23 << '\n';
}