module exercises;

void error(std::string s)
{
	throw runtime_error(s);
}

//exercise 2 and 3 have been merged into solution 5.

//class for exercise4
class Name_value
{
public:
	string name;
	int grade;
	Name_value(string n) :name{n}, grade{-1}
	{}
	Name_value(string n, int g) :name{ n }, grade{ g }
	{}
};

//function for exercise4 and exercise8
//处理数字前的正号'+'
void deal_with_plus_sign(string &s)
{
	if (s[0] == '+')
		s.erase(0, 1);
}

//function for exercise4 and exercise8
//判断字符串是不是正整数和0
bool is_integer(string &s)
{
	deal_with_plus_sign(s);
	for (char x : s)
	{
		if (x < '0' || x > '9')
			return false;
	}
	return true;
}

//function for exercise4 and exercise8
//输入字符串转换为正整数和0
int string_to_positive_integer(string s)
{
	if (is_integer(s))
	{
		int num = 0;
		int digit = 1;
		size_t size = s.size();
		int add = -1;
		for (size_t i = size - 1; i > -1; --i)
		{
			add = (s[i] - '0') * digit;
			//边界检查
			if (num > numeric_limits<int>::max() - add)
				return -1;
			num += add;
			digit *= 10;
		}
		return num;
	}
	else
		return -1;
}

//function for exercise4
//找同名位置，把位置存入数组
std::vector<int> search_name(vector<Name_value>& Nvs, string name)
{
	vector<int> names;
	for (int i = 0; i < Nvs.size(); ++i)
	{
		if (Nvs[i].name == name)
			names.push_back(i);
	}
	return names;
}

//function for exercise4
//找成绩，把位置存入数组
vector<int> search_grade(vector<Name_value>& Nvs, int grade)
{
	vector<int> grades;
	for (int i = 0; i < Nvs.size(); ++i)
	{
		if (Nvs[i].grade == grade)
			grades.push_back(i);
	}
	return grades;
}

//function for exercise4
//输入(名字_成绩)
void input_pairs(vector<Name_value> &Nvs)
{
	string input_name = " ";
	string input_grade = " ";
	int grade;
	vector<int> positions;
	while (true)
	{
		positions.clear();
		cin >> input_name >> input_grade;
		//输入字符串转换为正整数
		grade = string_to_positive_integer(input_grade);
		if (grade < 0 || grade > 100)
		{
			cout << "grade should be between 0 and 100" << '\n';
			continue;
		}
		//结束输入
		if (input_name == "NoName" && grade == 0)
			break;
		//检查输入名字是否已存在
		positions = search_name(Nvs, input_name);
		
		if (positions.size()>0)
			cout << "It's a duplicate name, you have entered it before." << '\n';
		else
		{
			Name_value nv(input_name, grade);
			Nvs.push_back(nv);
		}
	}
}


//rework exercise20 of Chapter3
void exercise4()
{
	cout << "Please enter a set of name-and-value pairs.(Input 'NoName 0' to terminate)" << '\n';
	vector<Name_value> Nvs;

	input_pairs(Nvs);

	cout << "You have completed entering!" << "\n"
		<< "Pairs you have entered: " << '\n';
	//打印所有输入(名字_成绩)
	for (Name_value x : Nvs)
		cout << "name: " << x.name << '\t' << "grade:" << x.grade << '\n';

	char input;
	while (cin)
	{
		cout << '\n' << "Input 1 to search by name." << "\n"
			<< "Input 2 to search by value" << "\n"
			<< "Input e to exit." << "\n";
		cin >> input;
		switch (input)
		{
		case '1':
		{
			cout << "Please enter the name you want to search:" << '\n';
			string input_name;
			cin >> input_name;
			vector<int> names = search_name(Nvs, input_name);
			if (names.size() > 0)
			{
				int position = -1;
				for (int i = 0; i < names.size(); ++i)
				{
					position = names[i];
					cout << Nvs[position].name << " 的成绩是 " << Nvs [position].grade << '\n';
				}
			}
			else
				cout << "name not foud" << '\n';
			break;
		}
		case '2':
		{
			cout << "Please enter the value you want to search:" << '\n';
			string input_value;
			cin >> input_value;
			int s_grade = -1;
			if (is_integer(input_value))
			{
				s_grade = string_to_positive_integer(input_value);
				if (s_grade < 0 || s_grade > 100)
					cerr << "Your integer should be between 0 and 100" << '\n';
			}
			else
				cerr << "You should enter an integer" << '\n';
			vector<int> names = search_grade(Nvs, s_grade);
	
			if (names.size() < 1)
				cout << "score not found" << '\n';
			else
			{
				cout << "成绩为 " << s_grade << " 的人有：" << '\n';
				for(int i = 0; i < names.size(); ++i)
					cout << Nvs[names[i]].name << "\n";
			}
			break;
		}
		case 'e':
			return;
		default:
			cout << "Sorry I don't understand that." << '\n';
			break;
		}
	}
}

//class for exercise5
class Token
{
public:
	char kind;
	int value;
	Token(char k) :kind{k}, value{0}
	{}
	Token(char k, int v) :kind{k}, value{v}
	{}
};

//class for exercise5
class Token_stream
{
public: 
	Token get();
	void putback(Token t);
private:
	bool full = false;
	Token buffer {'0'};
};

//fuction for exercise5
void Token_stream::putback(Token t)
{
	if (full)
		cerr << "putback() into a full buffer" << '\n';
	buffer = t;
	full = true;
}

//fuction for exercise5
Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch = 0;
	if (!(cin >> ch))
		cerr << "no input" << '\n';

	switch (ch)
	{
	case ';':
	case 'q':
	case '(': case ')': case '{': case '}': 
	case '&': case '|': case '^': case'~':
		return Token{ ch };
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);	//将一个字符放回输入流中，然后在缓冲区中持续读取数字，直到cin >> val;(double类型)失败。
		int val = 0;
		cin >> val;
		return Token{ '8', val };
	}
	default:
		cerr << "Bad Token" << '\n';
		return -100;
	}
}

//global variable for exercise5
Token_stream ts;
int expression();

//fuction for exercise5
//处理‘（’，‘{’，‘~’，整数
int primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		int d = expression();
		t = ts.get();
		if (t.kind != ')')
			cerr << "'(' expected" << '\n';
		return d;
	}
	case '{':
	{
		int d = expression();
		t = ts.get();
		if (t.kind != '}')
			cerr << "'{' expected" << '\n';
		return d;
	}
	case '~':
	{
		int d = expression();
		d = ~d;
		return d;
	}
	case '8':
		return t.value;
	default:
		error("primary expected");
		return -100;
	}
}

//fuction for exercise5
int expression()
{
	int left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '&':
			left &= primary();
			t = ts.get();
			break;
		case '|':
			left |= primary();
			t = ts.get();
			break;
		case '^':
			left ^= primary();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

//整数按位运算计算器
//能处理‘~’，‘&’，‘|’，‘^’，运算。
//根据第五章的计算器改的。
void exercise5()
{
	int val = 0;
	while (cin)
	{
		Token t = ts.get();
		if (t.kind == 'q')
			break;
		if (t.kind == ';')
			cout << "=" << val << '\n';
		else
			ts.putback(t);
		val = expression();
	}
}

//function for exercise6
//生成不重复的随机字母组合
void spawn_random_num(vector<char> &target)
{
	unsigned int seconds = unsigned int(time(0));
	default_random_engine engine(seconds);
	uniform_int_distribution<int> dist(97, 122);
	int random_num = '#';
	bool different = true;
	for (int i = 0; i < 4; ++i)
	{
		//检查是否和已插入字母重复
		random_num = char(dist(engine));
		for (char& x : target)
		{
			if (random_num == x)
			{
				different = false;
				break;
			}
		}
		if (different)
			target.push_back(random_num);
		else
		{
			--i;
			different = true;
		}
	}
}

//function for exercise6
bool check_input(string s)
{
	if (s.size() != 4)
	{
		cout << "Invalid input. Your number should have exactly 4 letters." << '\n';
		return false;
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			//检查每位输入是否是a到z
			if (s[i] < 'a' || s[i] > 'z')
			{
				cout << s[i] << " is not a lowercase letter." << '\n';
				return false;
			}
			//检查每位输入是否重复
			for (int j = i + 1; j < 4; ++j)
			{
				if (s[i] == s[j])
				{
					cout << "Invalid input. All letters must be different." << '\n';
					return false;
				}
			}
		}
		return true;
	}
}

//function for exercise6
void print_introduction()
{
	cout << "Bulls and Cows! Have a try to guess my letters." << '\n'
		<< "You get a 'Bull' for each lowercase letter that is correct and in the correct position." << '\n'
		<< "You get a 'Cow' for each lowercase letter that is correct but in the wrong position." << '\n'
		<< "Please enter 4 different lowercase letters." << '\n';
}

//function for exercise6
void leak_answer(vector<char> target)
{
	cout << "The target is:";
	for (int i = 0; i < target.size(); ++i)
		cout << target[i];
	cout << '!' << '\n';
}

//redo exercise12 in Chapter 4
//这次是生成4个不重复字母
void exercise6()
{
	//生成4位不重复数字组合
	vector<char> target;
	spawn_random_num(target);
	//cout << "Random letters is ready!" << '\n';

	//leak_answer(target);

	print_introduction();

	int count = 1;
	bool valid_input = false;
	int Bull = 0;
	int Cow = 0;
	string s = " ";
	while (true)
	{
		std::cin >> s;
		if (s == "+-*/" && count > 20)
			break;
		valid_input = check_input(s);
		//核对答案
		if (valid_input)
		{
			for (int i = 0; i < 4; ++i)
			{
				//因为4位各不相同，所以直接找是否有相同的。
				for (char& x : target)
				{
					if (s[i] == x)
						++Cow;
				}
				if (s[i] == target[i])
				{
					++Bull;
					--Cow;
				}
			}
			cout << Bull << " Bull and " << Cow << " Cow" << '\n';
			if (Bull == 4)
				break;
		}
		//恢复默认值
		valid_input = false;
		Cow = 0;
		Bull = 0;
		cin.clear();		//单独输入ctrl+z会使cin为错误状态，程序进入死循环。
		s.clear();
		++count;
		if (count > 20)
		{
			cout << "In case you want to give up, enter '+-*/'." << '\n';
		}
	}
	if (s != "+-*/")
		cout << "Bravo! You guessed it! ";
	for (char& c : target)
		cout << c;
	cout << " is the right answer!\n" << "Rounds you have spent: " << count << '\n';
}

//exercise7 has been implemented in some of my previous exercises


//fuction for exercise8
//计算排列
//如果用 P(a,b) = (a!)/((a-b)!)和阶乘的话，a最大只能为12.
int permutation(int a, int b)
{
	int permutation = 1;
	for (int i = 0; i < b; ++i)
	{
		if (permutation > numeric_limits<int>::max()/(a-i))
			return -1;
		permutation *= (a - i);
	}
	return permutation;
}

//function for exercise8
//计算组合
int combination(int a, int b)
{
	int num = permutation(a, b);
	if (num == -1)
		return -1;
	for (int i = b; i > 1; --i)
		num /= i;
	return num;
}

//fuction for exercise8
//输入两个字符串，转换成非负整数，存入数组。
bool input_two_integer(vector<int> &input)
{
	string a ,b;
	cin >> a >> b;
	int num1 = string_to_positive_integer(a);
	int num2 = string_to_positive_integer(b);
	//没有在num1 = -1时马上退出，是为了让缓冲区的数据存入num2。
	if (num1 == -1 ||num2 == -1)
		return false;
	input[0] = num1;
	input[1] = num2;
	return true;
}

//计算排列组合
//输入两个数，计算排列数或组合数。
//排列 P(a,b) = (a!)/((a-b)!); 组合C(a,b) = (P(a,b))/(b!)
void exercise8()
{
	char func = '#';
	vector<int> input(2);
	int result = 0;
	int a = 0, b = 0;
	while (true)
	{
		cin.clear();
		cout << '\n' << "Please enter two non-negative integers." << '\n';
		if (input_two_integer(input))
		{
			a = input[0];
			b = input[1];
			if (a < b)
			{
				cout << a << " should be greater than " << b << '\n';
				continue;
			}
			cout << "Enter 'p' for permutation, 'c' for combination, 'q' to exit." << '\n';
			cin >> func;
			switch (func)
			{
			case 'p':
			{
				result = permutation(a, b);
				if (result == -1)
					cout << "Sorry, I can't solve that." << '\n';
				else
					cout << "P(" << a << " ," << b << ") = " << result << '\n';
				break;
			}
			case 'c':
			{
				result = combination(a, b);
				if (result == -1)
					cout << "Sorry, I can't solve that." << '\n';
				else
					cout << "C(" << a << " ," << b << ") = " << result << '\n';
				break;
			}
			case 'q':
			{
				return;
			}
			default:
			{
				cout << "Sorry I don't understand that." << '\n';
				break;
			}
			}
		}
		else
			cout << "Invalid input, please enter non-negative integers within range(0, 2147483647)." << '\n';
	}
}