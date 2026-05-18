// 编写一个用空格替换标点符号的程序。
// Consider
// . (dot), ; (semicolon), , (comma), ? (question mark),
// − (dash), ’ (single quote) punctuation characters.
// 不要修改双引号（“）内的字符。
// 例如，"- don't use the as-if rule." becomes "don t use the as if rule "。

// 修改前一个程序，使它把don't替换为do not, can't替换为can not。
// 使单词间的连字符保持不变，
// 例如，"- don't use the as-if rule." becomes "do not use the as-if rule "。

// 使用上一练习中的程序制作一个排序的单词列表。
// 在多页文本文件上运行结果，查看结果，看看是否可以改进程序以制作更好的列表。
export module Ex_06_08;

import PPP;
using namespace std;

void edit_string(string& s)
// 替换字符串里的标点符号
{
	const int size = static_cast<int>(s.size());
	for (int i = 0; i < size; ++i)
	{
		if (ispunct(s[i]) && s[i] != '\"' && s[i] != '\'')
			// 替换除 ' 和 " 外的标点符号
			if (s[i] == '-' && i != 0 && i != size - 1)
				continue;			// 忽略在字符串中间的连字符
			else
				s[i] = ' ';
	}
}

string edit_sentence(const string& s)
// 替换句子中的don't和can't
{
	istringstream is{ s };
	string sentence;
	for (string x; is >> x;)
	{
		if (x == "don't")
			x = "do not";
		if (x == "Don't")
			x = "Do not";
		if (x == "can't")
			x = "can not";
		if (x == "Can't")
			x = "Can not";
		edit_string(x);
		sentence.append(x);
		sentence.append(" ");
	}
	sentence.erase(sentence.end());
	return sentence;
}

export void Ex_06_08()
// 输入一行字符
// 依次检验每个字符串
// 使用ispunct(ch) && (ch != '"') && (ch != ''')检验字符串末尾元素，替换标点符号为空格
// 输出
{
	string iname = "exercises/Ex_06_08.txt";
	ifstream ifs{ iname };
	vector<string> article;
	for (string line; getline(ifs, line);)
	{
		string new_line = edit_sentence(line);
		article.push_back(new_line);
	}

	for (const string& x : article)
		cout << x << '\n';
}