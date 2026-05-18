// 写一个程序，它除去文件中所有的元音字母。

export module Ex_03;

import functions;
import PPP;
using namespace std;

bool is_vowels(char c)
// 判断字符是否是元音字母。
{
	static const vector<char>vowels = { 'a', 'e', 'i', 'o', 'u' };
	for (char x : vowels)
		if (x == c)
			return true;
	return false;
}

export void Ex_03()
{
	string iname = "exercises/Ex_03.txt";
	ifstream ifs{ iname };

	vector<char> content;
	fill_from_file(content, iname);

	// 从后往前读取。
	for (int i = PPP::narrow_cast<int>(content.size()) - 1; -1 < i; --i)
	{
		if (is_vowels(content[i]))
			content.erase(content.begin() + i);
	}
	output_to_file(content, iname);
}

/*
'What happens to you here is forever,' O'Brien had said.
That was a true word.
There were things, your own acts, from which you could never recover.
Something was killed in your breast : burned out, cauterized out.
*/