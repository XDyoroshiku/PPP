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

import PPP;
import Ex_05;
import Ex_06;
import Ex_08;
import Date;
using namespace std;

export void Ex_09();

enum class Operation { check_out, check_in };
const vector<string> operation{ "check_out", "check_in" };

string operation_to_string(Operation o)
// 返回opration类型对应的字符串
{
	int int_operation = PPP::narrow_cast<int>(o);
	return operation[int_operation];
}

struct Transaction
{
	Book book;
	Patron patron;
	Date date;
	Operation operation;
	Transaction(Book b, Patron p, Date d, Operation o) : book{ b }, patron{ p }, date{ d }, operation{ o } {}
};

class Library
{
public:
	void add_Book(const Book&);
	void add_Patron(const Patron&);
	void check_book_out(const Patron&, const Book&);
	void check_book_in(const Patron&, const Book&);
	vector<Patron> users_owe_fees() const;
private:
	vector<Book> books;
	vector<Patron> patrons;
	vector<Transaction> transactions;

	bool registered_patron(const Patron& p) const;
	int search_book(const Book& b) const;
};

bool Library::registered_patron(const Patron& p) const
// 检验用户是否在图书馆注册
{
	int p_number = p.get_number();
	for (const Patron& x : patrons)
	{
		if (x.get_number() == p_number)
			return true;
	}
	return false;
}

int Library::search_book(const Book& b) const
// 查找书，找到返回数组下标；没找到返回-1。
{
	int size = PPP::narrow_cast<int>(books.size());
	for (int i = 0; i < size; ++i)
	{
		if (books[i] == b)
			return i;
	}
	return -1;
}

void Library::add_Book(const Book& b)
// 添加书到图书馆
{
	// 遍历books数组，查找是否有相同的书
	if(search_book(b) != -1)
		PPP::error("Book \"" + b.get_title() + "\" is already in the library.");
	books.push_back(b);
}

void Library::add_Patron(const Patron& p)
// 添加顾客到图书馆
{
	// 查询用户是否已经注册
	if(registered_patron(p))
		PPP::error("Patron \"" + p.get_name() + "\" is already in the library.");
	patrons.push_back(p);
}

void Library::check_book_out(const Patron& p, const Book& b)
{
	// 检验顾客是否在图书馆注册。
	if(!registered_patron(p))
		PPP::error("The patron \"" + p.get_name() + "\" is not in the library.");
	// 遍历所有的书
	const int sub = search_book(b);
	// 遍历数组后没找到相同的书
	if (sub == -1)
		PPP::error("The book \"" + b.get_title() + "\" is not in the library.");
	// 书已被借出
	if (books[sub].is_checked_out())
		PPP::error("The book \"" + b.get_title() + "\" has been checked out.");
	// 用户欠费
	if (p.owes_a_fee())
		PPP::error("The patron \"" + p.get_name() + "\" can't borrow the book because he owes a fee.");
	// 借出书
	books[sub].check_out();
	// 添加交易记录
	Transaction t{ b, p, get_today(), Operation::check_out };
	transactions.push_back(t);
}

void Library::check_book_in(const Patron& p, const Book& b)
{
	// 检验顾客是否在图书馆注册。
	if (!registered_patron(p))
		PPP::error("The patron \"" + p.get_name() + "\" is not in the library.");
	// 遍历所有的书
	const int sub = search_book(b);
	// 遍历数组后没找到相同的书
	if (sub == -1)
		PPP::error("The book \"" + b.get_title() + "\" is not in the library.");
	// 书未被借出
	if (!books[sub].is_checked_out())
		PPP::error("Error: The book \"" + b.get_title() + "\" has been not checked out.");
	// 还书
	books[sub].check_in();
	// 添加交易记录
	Transaction t{ b, p, get_today(), Operation::check_in };
	transactions.push_back(t);
}

vector<Patron> Library::users_owe_fees() const
// 返回所有欠费的顾客。
{
	vector<Patron> debtor;
	for (const Patron& x : patrons)
	{
		if (x.owes_a_fee())
			debtor.push_back(x);
	}
	return debtor;
}

void Ex_09()
{
	Book b1("Programming:principles and practice using C++", "Bjarne Stroustrup", 2014, ISBN("0-321-99278-4"), Genre::nonfiction);
	Book b2("A Tour of C++", "Bjarne Stroustrup", 2023, ISBN("0-13-681648-7"), Genre::nonfiction);
	Book b3("Flatland", "Edwin A.Abbott", 2006, ISBN("0-19-280598-3"), Genre::fiction);
	Book b4("The Call of the Wild", "Jack London", 2006, ISBN("1-56254-888-3"), Genre::children);
	Book b5("Guide to Special Issues and Indexes of Periodicals", "Miriam Uhlan ", 1985, ISBN("0-87111-263-9"), Genre::periodical);
	Book b6("Caught in the Web of Words", "K.M.Elisabeth Murray", 2001, ISBN("0-300-08919-8"), Genre::biography);

	Library lib;
	//lib.add_Book();

}
