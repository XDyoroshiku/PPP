// 23
// 写一个把两个文件的内容连在一起的程序
// 输入两个文件名，创建一个新文件，里面的内容包括第一个文件的内容，再接着第二个文件的内容。

// 24
// 写一个程序，它把两个包含排序过的、由空格分隔的单词合并在一起。

export module Ex_23;

import functions;
import PPP;
using namespace std;

export void Ex_23()
{
	const string iname1 = "exercises/Ex_23_file1.txt";
	const string iname2 = "exercises/Ex_23_file2.txt";
	vector<char> file1;
	vector<char> file2;
	fill_from_file(file1, iname1);
	fill_from_file(file2, iname2);

	vector<char> concatenated;
	for (char x : file1)
		concatenated.push_back(x);
	for (char x : file2)
		concatenated.push_back(x);

	const string oname = "exercises/Ex_23_output.txt";
	output_to_file(concatenated, oname);
}