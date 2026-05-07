export module Book;

import PPP;
import functions;
using namespace std;

export class Book;
export class ISBN;
export enum class Genre;
export bool operator==(const Book& b1, const Book& b2);
export ostream& operator<<(ostream& os, const Book& book);
export ostream& operator<<(ostream& os, const ISBN& isbn);

class ISBN					// 成员不能为int类型，因为某部分可能为0开头：08919
{
public:
	ISBN(const string&);
	string get_group() const { return group; }
	string get_publisher() const { return publisher; }
	string get_title() const { return title; }
	char get_check() const { return check; }
	bool operator==(const ISBN& other) const
	{
		return group == other.group && publisher == other.publisher && title == other.title;
	}
	string string_ISBN() const;
private:
	string group;
	string publisher;
	string title;
	char check;

	bool valid_digits() const;
	bool valid_check() const;
};

enum class Genre{ fiction, nonfiction, periodical, biography, children };

class Book
{
public:
	Book(string, string, int, ISBN, Genre);
	string get_title() const { return title; }
	string get_author() const { return author; }
	int get_copyright_date() const { return copyright_date; }
	ISBN get_ISBN() const { return isbn; }
	Genre get_genre() const { return genre; }
	bool is_checked_out() const { return checked_out; }
	void check_in() { checked_out = false; }				// 还书
	void check_out() { checked_out = true; }				// 借书
private:
	string title;
	string author;
	int copyright_date;
	ISBN isbn;
	Genre genre;
	bool checked_out = false;				// 默认未借出
};

ISBN::ISBN(const string& s)
{
	istringstream is{ s };
	constexpr char hyphen = '-';
	char ch = '?';
	int count_hyphen = 0;
	while (is.get(ch)) {
		if (ch == hyphen)
			++count_hyphen;
		else {
			switch (count_hyphen) {
			case 0:
				group.push_back(ch);			// read in group
				break;
			case 1:
				publisher.push_back(ch);		// read in publisher
				break;
			case 2:
				title.push_back(ch);			// read in title
				break;
			case 3:
				check = ch;						// read in check
				++count_hyphen;
				break;
			default:
				PPP::error("ISBN format error: ", s);
				break;
			}
		}
	}
	if (count_hyphen != 4)
		PPP::error("ISBN format error: ", s);
	if (!valid_digits() || !valid_check())
		PPP::error("Invalid ISBN: " + s);
}

bool ISBN::valid_digits() const
// 检验ISBN各部分字段的有效性。
{
	constexpr int gmax = 5;				// group的最大有效位数。
	constexpr int pmin = 2;				// publisher的最小有效位数。
	constexpr int pmax = 7;				// publisher的最大有效位数。
	constexpr int tmax = 6;				// title的最大有效位数。
	constexpr int valid_digits = 10;	// ISBN的有效位数。
	const int group_digit = PPP::narrow_cast<int>(group.size());			// group的总位数。
	const int publisher_digit = PPP::narrow_cast<int>(publisher.size());	// publisher的总位数。
	const int title_digit = PPP::narrow_cast<int>(title.size());			// title的总位数。

	// 检验各部分的字符是否都是'0'到'9'的数字。
	if (!is_integer(group))
		return false;
	if (!is_integer(publisher))
		return false;
	if (!is_integer(title))
		return false;
	// 检验各部分位数是否在有效范围内。
	if (gmax < group_digit)
		return false;
	if (publisher_digit < pmin || pmax < publisher_digit)
		return false;
	if (tmax < title_digit)
		return false;
	// 检验前三部分的总位数是否是9。
	if ((group_digit + publisher_digit + title_digit) != valid_digits - 1)
		return false;
	// 检验校验位。
	if (!(('0' <= check && check <= '9') || check == 'X'))				//校验位为0到9的数字或X。
		return false;
	return true;
}

bool ISBN::valid_check() const
// 检验校验位是否正确。
{
	int multiplier = 10;
	int sum = 0;
	// 从高位到低位，每位乘以权重，加入sum。
	string gpt = group + publisher + title;
	for (char x : gpt)
	{
		sum += PPP::narrow_cast<int>(x - '0') * multiplier;
		--multiplier;
	}
	char check_digit;
	const int int_check = 11 - sum % 11;
	switch (int_check)
	{
	case 11:
		check_digit = '0';
		break;
	case 10:
		check_digit = 'X';
		break;
	default:
		check_digit = int_check + '0';
		break;
	}
	if (check_digit != check)
		return false;
	return true;
}

string ISBN::string_ISBN() const
// 以字符串的形式输出ISBN的所有信息
{
	return 	group + '-' +
		publisher + '-' +
		title + '-' +
		check;
}

Book::Book(string t, string a, int cd, ISBN isbn, Genre g) : title{ t }, author{ a }, copyright_date{ cd }, isbn{ isbn }, genre{ g }
{
	constexpr int max_copyright_date = 2026;				// 最大版权年份
	constexpr int min_copyright_date = 1000;				// 最小版权年份
	constexpr int max_title_size = 500;						// 最长标题长度
	constexpr int max_author_size = 50;						// 最长作者长度
	// 检查title的有效性
	if (t.size() == 0 || max_title_size < t.size())
		PPP::error("Invalid title");
	// 检查author的有效性
	if (a.size() == 0 || max_author_size < a.size())
		PPP::error("Invalid author");
	// 检查copyright_date的有效性
	if (copyright_date < min_copyright_date || max_copyright_date < copyright_date)
		PPP::error("Invalid copyright date");

	// ISBN的有效性在构造时就已经检查过了。
}

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
		<< "Book:" << "\n"
		<< "title: " << book.get_title() << '\n'
		<< "author: " << book.get_author() << '\n'
		<< "copuright_date: " << book.get_copyright_date() << '\t'
		<< "ISBN: " << book.get_ISBN() << '\n'
		<< "Genre: " << book.get_genre() << '\t' << '\t'
		<< "checked_out: " << (book.is_checked_out() ? "yes" : "no") << '\n';
}