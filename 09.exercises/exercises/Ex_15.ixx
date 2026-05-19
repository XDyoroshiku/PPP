// 写一个读取包含由空白分隔的数字的文件
// 按从小到大的顺序输出这些数字
// 每个数字只输出依次，在后面输出重复的次数
// For example, 7 5 5 7 3 117 5 should give
// 3
// 5     3
// 7     2
// 117

export module Ex_15;

import functions;
import PPP;
using namespace std;

export void Ex_15();

struct number
{
	int value;
	int count = 1;
};

vector<number> count(vector<int> integers)
// 排序int数组
// 先读取数组第一个元素进入number数组
// 依次读取剩下所有元素，检查当前读取元素值是否等于前一个
// 如果相等，number数组中最后一个元素的count+1；
// 不相等，则创建新的number对象，存入数组
{
	const int size = static_cast<int>(integers.size());
	if (size == 0)
		PPP::error("empty vector");
	sort(integers.begin(), integers.end());
	vector<number> numbers;
	int last = 0;
	int previous = integers[last];
	number num{ previous };
	numbers.push_back(num);
	for (int i = 1; i < size; ++i)		// 从第二个开始
	{
		int value = integers[i];
		if (value == previous)
			++(numbers[last].count);
		else
		{
			number new_num{ value };
			numbers.push_back(new_num);
			previous = integers[i];
			++last;
		}
	}
	return numbers;
}

ostream& operator<<(ostream& os, number num)
{
	os << num.value;
	if (num.count != 1)
		os << '\t' << num.count;
	return os;
}

void Ex_15()
// 从文件读取数字到数组
// 排序数组，记录重复项个数
// 输出
{
	vector<int> integers;
	const string fname = "exercises/Ex_15.txt";
	fill_from_file(integers, fname);

	vector<number> numbers = count(integers);

	for (number x : numbers)
		cout << x << '\n';
}