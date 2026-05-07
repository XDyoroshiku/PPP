export module Ex_06;

import PPP;
import Book;
using namespace std;

export void Ex_06()
{
	Book b1("Programming:principles and practice using C++", "Bjarne Stroustrup", 2014, ISBN("0-321-99278-4"), Genre::nonfiction);
	cout << b1 << '\n';
	Book b2("A Tour of C++", "Bjarne Stroustrup", 2023, ISBN("0-13-681648-7"), Genre::nonfiction);
	b2.check_out();
	cout << b2 << '\n';
}