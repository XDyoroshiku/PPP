// 倒转一个文件里的单词
// For example, Norwegian Blue parrot becomes parrot Blue Norwegian.

export module Ex_12;

import PPP;
using namespace std;

string vector_to_string(const vector<string>& v)
// 把数组里的字符串拼接为一个字符串
{
	string s;
	for (const string& x : v)
	{
		s.append(x);
		s.append(" ");
	}
	if (!s.empty())
		s.pop_back();		// 除去多添加在末尾的空格
	return s;
}

vector<string> reverse_vector(const vector<string>& v)
// 倒转数组
{
	vector<string>reversed;
	constexpr int first = 0;
	int last = static_cast<int>(v.size()) - 1;
	for (int i = last; first <= i; --i)
		reversed.push_back(v[i]);
	return reversed;
}

string reverse_sentence(const string& s)
// 倒转一行里的单词：
// 先把一行的每个单词存入数组
// 再倒转数组，使单词逆序排列
// 最后把逆序排列的单词拼接成一个字符串
{
	vector<string> sentence;
	istringstream iss{ s };
	for (string word; iss >> word;)
		sentence.push_back(word);		// 把单词存入数组
	vector<string> reversed = reverse_vector(sentence);
	return vector_to_string(reversed);
}

vector<string> reverse_file(const string fname)
// 倒转文件的所有单词：
// 依次读取文件的每一行，倒转这行，存入数组
// 倒转数组——倒转所有行
{
	ifstream ifs{ fname };
	vector<string> sentences;
	for (string sentence; getline(ifs, sentence);)
		sentences.push_back(reverse_sentence(sentence));
	vector<string> reversed = reverse_vector(sentences);
	return reversed;
}

export void Ex_12()
{
	const string fname = "exercises/Ex_12.txt";
	vector<string> reversed = reverse_file(fname);

	for (const string& x : reversed)
		cout << x << '\n';
}