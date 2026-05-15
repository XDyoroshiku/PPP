// 写一个读取txt文件，把其输入全部转换为小写， 创建一个新文件。

export module Ex_01;

import functions;
import PPP;
using namespace std;

export void Ex_01()
{
	const string iname = "exercises/Ex_01_input.txt";

	vector<char> s;
	fill_from_file(s, iname);

	for (char& x : s)
		x = tolower(x);

	const string oname = "exercises/Ex_01_output.txt";
	output_to_file(s, oname);
}