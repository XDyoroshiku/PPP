// 写一个程序，它接受文件名和词，输出文件中带有这个词的那一整行和行数。
// 使用getline()。

export module Ex_02;

import functions;
import PPP;
using namespace std;

export void Ex_02()
{
	const string iname = "exercises/Ex_02_input.txt";
	ifstream ist;
	if (!ist)
		PPP::error("can't open file " + iname);

	vector<string> ss;
	fill_from_file(ss, iname);

	const string word = "dear";
	//const string word = "Watson";
	//const string word = "Holmes";
	int ss_size = PPP::narrow_cast<int>(ss.size());
	int line = 0;
	for (int i = 0; i <  ss_size; ++i)
	{
		if (find_word(word, ss[i]))
		{
			line = i + 1;
			cout << "Line " << line << ": " << ss[i] << '\n';
		}
	}
}