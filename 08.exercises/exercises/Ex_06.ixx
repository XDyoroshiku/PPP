export module Ex_06;

import PPP;
import Ex_05;
using namespace std;

export void Ex_06();
export bool operator==(const Book& b1, const Book& b2);
export ostream& operator<<(ostream& os, const Book& book);

bool operator==(const Book& b1, const Book& b2)
{
	return b1.get_ISBN() == b2.get_ISBN();
}

bool operator!=(const Book& b1, const Book& b2)
{
	return !(b1 == b2);
}

ostream& operator<<(ostream& os, const ISBN& isbn)
{
	return os << isbn.string_ISBN();
}

const vector<string> genre{ "fiction", "nonfiction", "periodical", "biography", "children" };

string genre_to_string(const Genre& g)
// 返回Genre类型值对应的字符串。
{
	int int_genre = PPP::narrow_cast<int>(g);
	return genre[int_genre];
}

ostream& operator<<(ostream& os, const Genre& g)
{
	return os << genre_to_string(g);
}

ostream& operator<<(ostream& os, const Book& book)
{
	return os
		<< "title: " << book.get_title() << '\n'
		<< "author: " << book.get_author() << '\n'
		<< "copuright_date: " << book.get_copyright_date() << '\n'
		<< "ISBN: " << book.get_ISBN() << '\n'
		<< "Genre: " << book.get_genre() << '\n'
		<< "checked_out: " << (book.is_checked_out() ? "yes" : "no") << '\n';
}

void Ex_06()
{
	Book b1("Programming:principles and practice using C++", "Bjarne Stroustrup", 2014, ISBN("0-321-99278-4"), Genre::nonfiction);
	cout << b1 << '\n';
	Book b2("A Tour of C++", "Bjarne Stroustrup", 2023, ISBN("0-13-681648-7"), Genre::nonfiction);
	b2.check_out();
	cout << b2 << '\n';
}