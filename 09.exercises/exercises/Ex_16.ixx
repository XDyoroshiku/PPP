// 写一个程序，得出文件中由空白分隔的所有数字之和

export module Ex_16;

import <climits>;
import functions;
import PPP;
using namespace std;

int get_sum(vector<int> ints)
{
	int sum = 0;
	for (int x : ints)
	{
		if (INT_MAX - x < sum)
			PPP::error("sum out of range");
		sum += x;
	}
	return sum;
}

export void Ex_16()
{
	vector<int> ints;
	const string fname = "exercises/Ex_15.txt";
	fill_from_file(ints, fname);

	int sum = get_sum(ints);
	cout << "The sum of all numbers in file \"" << fname << "\" is: " << sum << '\n';
}