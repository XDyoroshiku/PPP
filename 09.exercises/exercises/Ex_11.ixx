// 倒转一个txt文件里的字符。

export module Ex_11;

import functions;
import PPP;
using namespace std;

string reverse(const string& s)
// 从后往前，依次把字符串的每一个字符添加进另一个字符
{
	constexpr int first = 0;
	int last = static_cast<int>(s.size()) - 1;
	string reverse_string;
	for (int i = last; first <= i; --i)
		reverse_string.push_back(s[i]);
	return reverse_string;
}

export void Ex_11()
// 把文件里的每行读取进string数组
// 依次倒转每行字符串，把结果放进另一个字符串数组
// 输出
{
	const string fname = "exercises/Ex_06_08.txt";
	vector<string> lines;
	fill_from_file(lines, fname);
	vector<string> reversed;
	for (const string& each_line : lines)
	{
		string reverse_line = reverse(each_line);
		reversed.push_back(reverse_line);
	}
	for (const string& x : reversed)
		cout << x << '\n';
}