// 写一个处理由空格分隔的字符串的函数：
// vector<string> split(const string& s, const string& w)，
// 返回一个包含其子字符串的数组
// “空格”是普通的空格加上参数w里的字符

export module Ex_10;

import Ex_09;
import PPP;
using namespace std;

string replace(const string& s, const string& w)
// 检查每一位，如果是w里的字符，把它替换成空格
{
	string replaced;
	for (char x : s)
	{
		for (char ch : w)
		{
			if (x == ch)
			{
				replaced.push_back(' ');
			}
		}
		replaced.push_back(x);
	}
	return replaced;
}

export void Ex_10()
{
	const string s = "Write a function vector<string> split(const string& s, const string& w) "
		"that returns a vector of whitespace - separated substrings from the argument s, "
		"where whitespace is defined as “ordinary whitespace” plus the characters in w.";

	string replaced = replace(s, "aeiou");
	vector<string>splited = split(replaced);

	for (const string& x : splited)
		cout << x << '\n';
}


//vector<string> split(const string& s, const string& w)
//// 依次把每一位存入字符串
//// 读取到空格后，依次检查后面的位，如果符合空格＋w，则把这个字符串存入数组（分割）
//// 返回分割后的数组
//{
//	const string spt = " " + w;
//	int spt_size = static_cast<int>(spt.size());
//	vector<string> splited;
//	istringstream iss{ s };
//	int repeat = 0;
//	string x;
//	for (char ch; iss.get(ch);)
//	{
//		x.push_back(ch);
//		if (ch == spt[repeat])
//			++repeat;
//		else
//			repeat = 0;
//		if (repeat == spt_size)
//		{
//			splited.push_back(x);
//			x = "";						// 初始化字符串
//			repeat = 0;
//		}
//	}
//	splited.push_back(x);				// 加上因为读到末尾而没有添加的最后一句
//	return splited;
//}