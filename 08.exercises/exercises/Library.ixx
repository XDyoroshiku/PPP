export module Library;

import Book;
import Date;
import Patron;
import PPP;
using namespace std;

export class Library;

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

ostream& operator<<(ostream& os, const Transaction& t)
{
	return os << t.date << '\n'
		<< t.patron.get_name() << '\t' << operation_to_string(t.operation) << '\n'
		<< "Book: " << t.book.get_ISBN() << '\t' << t.book.get_title() << '\n';
}

class Library
{
public:
	void add_Book(const Book&);
	void add_Patron(const Patron&);
	void check_book_out(const Patron&, const Book&);			// 订阅制图书馆，借书不扣钱XD
	void check_book_in(const Patron&, const Book&);
	vector<Patron> users_owe_fees() const;
	void print_transactions() const;
	void print_debtors() const;
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
	if (search_book(b) != -1)
		PPP::error("Book \"" + b.get_title() + "\" is already in the library.");
	books.push_back(b);
}

void Library::add_Patron(const Patron& p)
// 添加顾客到图书馆
{
	// 查询用户是否已经注册
	if (registered_patron(p))
		PPP::error("Patron \"" + p.get_name() + "\" is already in the library.");
	patrons.push_back(p);
}

void Library::check_book_out(const Patron& p, const Book& b)
{
	// 检验顾客是否在图书馆注册。
	if (!registered_patron(p))
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
	// 扣费
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

void Library::print_transactions() const
{
	cout << "Library transactions: " << '\n';
	for (Transaction x : transactions)
		cout << x << '\n';
}

void Library::print_debtors() const
{
	vector<Patron> debtors = users_owe_fees();
	if (debtors.size() == 0)
		cout << "No one owes a fee. That's good." << '\n';
	else
	{
		cout << "Users who owe a fee to the library: " << '\n';
		for (Patron x : debtors)
			cout << x.get_name() << '\t' << x.get_fees() << '\n';
	}
}