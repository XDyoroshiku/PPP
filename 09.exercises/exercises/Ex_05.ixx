// 编写一个程序，读取字符串，并为每个字符串输出每个字符的字符分类，
// 如§9.10.3中给出的字符分类函数所定义。
// 请注意，一个字符可以有多种分类（例如，x既是字母又是字母数字）。

export module Ex_05;

import PPP;
using namespace std;

struct classification
{
	char ch;
	bool space = false;
	bool alpha = false;
	bool digit = false;
	bool xdigit = false;
	bool upper = false;
	bool lower = false;
	bool alnum = false;
	bool cntrl = false;
	bool punct = false;
	bool print = false;
	bool graph = false;
};

classification classify(const char ch)
{
	classification cf{ ch };
	if (isspace(ch))	cf.space = true;
	if (isalpha(ch))	cf.alpha = true;
	if (isdigit(ch))	cf.digit = true;
	if (isxdigit(ch))	cf.xdigit = true;
	if (isupper(ch))	cf.upper = true;
	if (islower(ch))	cf.lower = true;
	if (isalnum(ch))	cf.alnum = true;
	if (iscntrl(ch))	cf.cntrl = true;
	if (ispunct(ch))	cf.punct = true;
	if (isprint(ch))	cf.print = true;
	if (isgraph(ch))	cf.graph = true;
	return cf;
}

ostream& operator<<(ostream& os, classification cf)
{
	static const string space = "whitespace";
	static const string alpha = "letter";
	static const string digit = "decimal digit";
	static const string xdigit = "hexadecimal digit";
	static const string upper = "uppercase letter";
	static const string lower = "lowercase letter";
	static const string alnum = "alphanumeric";
	static const string cntrl = "control character";
	static const string punct = "punctuation";
	static const string print = "printable";
	static const string graph = "alphanumpunct";

	os << cf.ch << '\t';
	if(cf.space) os << space << '\t';
	if(cf.alpha) os << alpha  << '\t';
	if(cf.digit) os << digit  << '\t';
	if(cf.xdigit) os << xdigit << '\t';
	if(cf.upper) os << upper  << '\t';
	if(cf.lower) os << lower  << '\t';
	if(cf.alnum) os << alnum  << '\t';
	if(cf.cntrl) os << cntrl  << '\t';
	if(cf.punct) os << punct  << '\t';
	if(cf.print) os << print  << '\t';
	if(cf.graph) os << graph  << '\t';
	
	return os;
}

export void Ex_05()
// 输入字符串
// 创建classification对象，依次检验每个字符，是对应的分类则设置字段为true
// 对象存入classification数组，下标和字符串一一对应
// 打印输出
{
	string s;
	getline(cin, s);

	vector<classification> cfs;
	for (char x : s)
	{
		classification cf = classify(x);
		cfs.push_back(cf);
	}

	for (classification x : cfs)
		cout << x << '\n';
}