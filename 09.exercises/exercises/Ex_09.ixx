// 写一个处理由空格分隔的字符串的函数，返回一个包含其子字符串的数组

export module Ex_09;

import PPP;
using namespace std;

vector<string> split(const string& s)
{
	vector<string> substrings;
	istringstream iss{ s };
	for (string x; iss >> x;)
		substrings.push_back(x);
	return substrings;
}

export void Ex_09()
{
	const string s = "Write a function vector<string> split(const string& s) that returns a vector of whitespace-separated substrings from the argument s.";
	vector<string> splited = split(s);
	for (const string x : splited)
		cout << x << '\n';
}