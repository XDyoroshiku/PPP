export module Ex_07;

export void Ex_07();

import PPP;
import Ex_05;
import Ex_06;
using namespace std;

void Ex_07()
{
	Book b1("Programming:principles and practice using C++", "Bjarne Stroustrup", 2014, ISBN("0-321-99278-4"), Genre::nonfiction);
	Book b3("Flatland", "Edwin A.Abbott", 2006, ISBN("0-19-280598-3"), Genre::fiction);
	Book b4("The Call of the Wild", "Jack London", 2006, ISBN("1-56254-888-3"), Genre::children);

	cout << b1 << '\n'
		<< b3 << '\n'
		<< b4 << '\n';
}