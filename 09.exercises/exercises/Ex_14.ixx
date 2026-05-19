// 写一个从文件中读取由空白分隔的数字的程序
// 用科学计数法，精度为8的输出到文件
// 每行输出4个数字，每个数字占20个字符的宽度。

export module Ex_14;

import functions;
import PPP;
using namespace std;

export void Ex_14()
{
	vector<double> input;
	const string iname = "exercises/Ex_14_input.txt";
	const string oname = "exercises/Ex_14_output.txt";
	fill_from_file(input, iname);

	ofstream ost{ oname };
	if (!ost)
		PPP::error("can't open file: " + oname);
	int size = static_cast<int>(input.size());
	constexpr int num_per_line = 4;
	for (int i = 0; i < size; ++i)
	{
		if (i % num_per_line == 0)
			ost << '\n';
		ost << setw(20) << scientific << setprecision(8) << input[i];
	}
}