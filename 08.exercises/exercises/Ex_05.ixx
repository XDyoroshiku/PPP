// 实现图书类
// 成员有：ISBN、title、author、copyright date、checked out（书是否已被借出）。

export module Ex_05;

import PPP;
import Book;
using namespace std;

export void Ex_05()
{
	Book b1("Programming:principles and practice using C++", "Bjarne Stroustrup", 2014, ISBN("0-321-99278-4"), Genre::nonfiction);
	cout << b1.is_checked_out() << '\n';
	b1.check_out();
	cout << b1.is_checked_out() << '\n';
	//Book b2("A Tour of C++", "Bjarne Stroustrup", 2023, ISBN("0-13-681648-8"), Genre::nonfiction);				// The correct check digit should be '7'.
	Book b3("Flatland", "Edwin A.Abbott", 2006, ISBN("0-19-280598-3"), Genre::fiction);
}