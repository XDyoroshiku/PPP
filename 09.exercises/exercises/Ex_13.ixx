// 写一个统计txt文件里各类字符有多少的程序

export module Ex_13;

import functions;
import PPP;
using namespace std;

struct counts
{
	int space = 0;
	int alpha = 0;
	int digit = 0;
	int xdigit = 0;
	int upper = 0;
	int lower = 0;
	int alnum = 0;
	int cntrl = 0;
	int punct = 0;
	int print = 0;
	int graph = 0;
};

ostream& operator<<(ostream& os, counts cts)
{
	return os << "counts of each character classification: " << '\n'
		<< "space:" << '\t' << cts.space << '\n'
		<< "alpha:" << '\t' << cts.alpha << '\n'
		<< "digit:" << '\t' << cts.digit << '\n'
		<< "xdigit:" << '\t' << cts.xdigit << '\n'
		<< "upper:" << '\t' << cts.upper << '\n'
		<< "lower:" << '\t' << cts.lower << '\n'
		<< "alnum:" << '\t' << cts.alnum << '\n'
		<< "cntrl:" << '\t' << cts.cntrl << '\n'
		<< "punct:" << '\t' << cts.punct << '\n'
		<< "print:" << '\t' << cts.print << '\n'
		<< "graph:" << '\t' << cts.graph << '\n'
		<< '\n';
}

export void Ex_13()
{
	string fname = "exercises/Ex_12.txt";
	vector<char> chars;
	fill_from_file(chars, fname);
	counts cts;
	for (char ch : chars)
	{
		if (isspace(ch))	++cts.space;
		if (isalpha(ch))	++cts.alpha;
		if (isdigit(ch))	++cts.digit;
		if (isxdigit(ch))	++cts.xdigit;
		if (isupper(ch))	++cts.upper;
		if (islower(ch))	++cts.lower;
		if (isalnum(ch))	++cts.alnum;
		if (iscntrl(ch))	++cts.cntrl;
		if (ispunct(ch))	++cts.punct;
		if (isprint(ch))	++cts.print;
		if (isgraph(ch))	++cts.graph;
	}

	cout << cts << '\n';
}