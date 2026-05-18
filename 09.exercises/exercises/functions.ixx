export module functions;

import PPP;
using namespace std;

export void fill_from_file(vector<char>& chars, const string& fname);
export void fill_from_file(vector<string>& strings, const string& fname);
export void output_to_file(const vector<char>& chars, const string& fname);
export bool find_word(const string& word, const string& s);

void ist_state(ifstream& ist)
// 依次判断ist处于哪种状态，做出相应处理
{
	if (ist.eof())						// fine: we found the end of file
		return;
	if (ist.bad())						// stream corrupted;
		PPP::error("ist is bad");		// let’s get out of here!
	if (ist.fail())						// clean up the mess as best we can and report the problem
		PPP::error("ist is fail");
}

void fill_from_file(vector<char>& chars, const string& fname)
// 挨个字符读取，存入数组
{
	ifstream ist{ fname };
	if (!ist)
		PPP::error("can't open file " + fname);
	
	for (char c; ist.get(c);)
		chars.push_back(c);

	ist_state(ist);
}

void fill_from_file(vector<string>& strings, const string& fname)
// 依次读取每行，存入数组
{
	ifstream ist{ fname };
	if (!ist)
		PPP::error("can't open file " + fname);

	for (string x; getline(ist, x);)
		strings.push_back(x);

	ist_state(ist);
}

void output_to_file(const vector<char>& chars, const string& fname)
// 把数组的内容输出到文件
{
	ofstream ost{ fname };
	if (!ost)
		PPP::error("can't open file: " + fname);
	for (char x : chars)
		ost << x;
}

string ignore_marks(const string& s)
// 返回字符串，其内容为省略了输入字符串末尾的句号和逗号。
{
	string filtered = s;
	constexpr char full_stop = '.';
	constexpr char comma = ',';
	int last = PPP::narrow_cast<int>(s.size()) - 1;
	if (s[last] == full_stop || s[last] == comma)
		filtered.erase(last);
	return filtered;
}

bool find_word(const string& word, const string& s)
//	判断一个字符串是否出现在另一个字符串中
{
	istringstream is{ s };
	for (string x; is >> x;)
	{
		if (ignore_marks(x) == word)
			return true;
	}
	return false;
}
