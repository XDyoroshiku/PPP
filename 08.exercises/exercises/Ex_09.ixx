// 创建图书馆类。
// 这个类有Book、Patron、Transaction成员。
// 结构Ttransaction有Book、Patron、Date成员。
// 创建一个Ttransaction数组记录借出的书。
// 增加函数：添加Book、Patron、到图书馆；借出书。
// 借出书时，确保用户和书都在图书馆；如果不在，报错。
//			 然后检查用户是否欠费。如果欠费，报错；
//			 如果不欠费，创建一条交易记录，把它添加到Transaction数组。
// 添加一个函数：返回包含所有欠费用户的数组。
export module Ex_09;

import Book;
import Library;
import Patron;
import PPP;
using namespace std;

export void Ex_09()
{
	Book b1("Programming:principles and practice using C++", "Bjarne Stroustrup", 2014, ISBN("0-321-99278-4"), Genre::nonfiction);
	Book b2("A Tour of C++", "Bjarne Stroustrup", 2023, ISBN("0-13-681648-7"), Genre::nonfiction);
	Book b3("Flatland", "Edwin A.Abbott", 2006, ISBN("0-19-280598-3"), Genre::fiction);
	Book b4("The Call of the Wild", "Jack London", 2006, ISBN("1-56254-888-3"), Genre::children);
	Book b5("Guide to Special Issues and Indexes of Periodicals", "Miriam Uhlan ", 1985, ISBN("0-87111-263-9"), Genre::periodical);
	Book b6("Caught in the Web of Words", "K.M.Elisabeth Murray", 2001, ISBN("0-300-08919-8"), Genre::biography);

	Patron p1("Huxley", 100001, 100);
	Patron p2("Orwell", 100002, -50);
	Patron p3("Stroustrup", 100003, 0);
	Patron p4("Follett", 100004, 80);
	Patron p5("Dawkins", 100005, -10);

	Library lib;
	lib.add_Book(b1);
	lib.add_Book(b2);
	lib.add_Book(b3);
	lib.add_Book(b4);
	lib.add_Book(b5);
	lib.add_Patron(p1);
	lib.add_Patron(p2);
	lib.add_Patron(p3);
	lib.add_Patron(p4);
	lib.add_Patron(p5);

	lib.check_book_out(p1 ,b1);
	//lib.check_book_out(p2, b1);
	lib.check_book_out(p1, b2);
	//lib.check_book_out(p2, b3);
	lib.check_book_out(p3, b3);
	lib.check_book_in(p1, b1);
	lib.check_book_out(p4, b1);
	lib.check_book_out(p1, b4);

	lib.print_transactions();
	lib.print_debtors();
}
