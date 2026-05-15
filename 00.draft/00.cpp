import <climits>;
import PPP;
using namespace std;

bool find_word(const string& word, const string& s)
//	判断一个字符串是否出现在另一个字符串中
{
	istringstream is{ s };
	for (string x; is >> x;)
	{
		if (x == word)
			return true;
	}
	return false;
}

int main()
{
	string ss = "hahaha ha haha ha hh";
	string s = "ha";

	if (find_word(s, ss))
		cout << "ok" << '\n';
}