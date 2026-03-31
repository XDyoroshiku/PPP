module _7;

int f(int i)
{
	cout << "Hello~, " << i << '\n';
	return 0;
}

int e_abs(int a)
{
	return (a >= 0) ? a : -a;
}

void e7_2()
{
	int i = 1;
	std::cout << "f(i) == " << f(i) << '\n';
	const int x2{ 9 };
	cout << "x2 == " << x2 << '\n';
	cout << "e_abs(8) == " << e_abs(8) << '\n'
		<< "e_abs(-8) == " << e_abs(-8) << '\n'
		<< "abs(8) == " << abs(8) << '\n'		//abs(), absolute value;
		<< "abs(-8) == " << abs(-8) << '\n';
}

double ff();
double ff();
//int ff();

int x = 0;                               // a global variable – avoid those where you can
int y = 0;

int f()
{
	int x = 0;                      // a local variable, hides the global x
	x = 7;                           // the local x
	{
		int x = y;             // local x initialized by global y, hides the previous local x
		++x;                    // the x from the previous line
	}
	++x;                             // the x from the first line of f()
	return x;
}

struct X 
{
	void f(int x) 
	{
		struct Y 
		{
			int f() 
			{ 
				return 1; 
			} 
			int m;
		};
		int m;
		m = x; 
		Y m2;
		return f(m2.f());
	}
	int m; 
	void g(int m) 
	{
		if (0 < m) 
			f(m + 2); 
		else 
		{
			g(m + 2.3);
		}
	}
	X() {} 
	//int m3() {}

	void main() 
	{
		X a; a.f(2);
	}
};

int my_find(vector<string>, string, int);                    // not naming arguments

void e7_4()
{
	vector<string> vs;
	string s;
	cout << my_find(vs, s, 3) << '\n';
}

int my_find(vector<string> vs, string s, int hint)
// search for s in vs starting at hint
{
	if (hint < 0 || vs.size() <= hint)
		hint = 0;
	for (int i = hint; i < vs.size(); ++i)        // search starting from hint
		if (vs[i] == s)
			return i;
	for (int i = 0; i < hint; ++i)                    // if we didn’t find s, so search before hint
		if (vs[i] == s)
			return i;
	return -1;
}

double my_abs(int x)      // warning: buggy code
{
	if (x < 3)
		return -x;
	else if (x > 3)
		return x;
}        // error: no value returned if x is 0


//改进第六章的计算器，不使用全局变量ts，使用函数的参数传递ts。
const char number = '8';
const char quit = 'Q';
const string quitkey = "exit";
const char print1 = '\n';
const string prompt = ">";
//const string result = "= ";
const char variable = 'v';
const char let = 'L';
const string letkey = "let";
//const string declkey = "#";
const char square_root = 'S';
const string sqrtkey = "sqrt";
const char power = 'P';
const string powkey = "pow";
const char underscores = '_';
const char help = 'H';
const string helpkey = "help";

//void error(std::string s)
//{
//    throw runtime_error(s);
//}
//
//void error(string s1, string s2)
//{
//    throw runtime_error{ s1 + s2 };
//}

class Token {
public:
    char kind;
    double value;
    string name;

    Token() : kind{ 0 }
    {}
    Token(char ch) : kind{ ch }, value{ 0 }
    {}
    Token(char ch, double val) : kind{ ch }, value{ val }
    {}
    Token(char ch, string n) : kind{ ch }, name{ n }
    {}
};

class Token_stream {
public:
    Token get();                // get a Token
    void putback(Token t);      // put a token back
    void ignore(char c);
private:
    bool full{ false };        // is there a Token in the buffer?
    Token buffer{ '0' };         // here is where putback() stores a Token
};

class Variable
{
public:
    string name;
    double value;
};

class Symbol_table
{
public:
    double get_value(string s);
    void set_value(string s, double d);
    bool is_declared(string var);
    double define_name(string var, double val);
    //double handle_variable(Token& t);
    //Symbol_table(string s, double n) : name{ name }, value{ n } {};
private:
    vector<Variable> var_table;
};

//定义需要用的全局变量。
//vector<Variable> var_table;
Symbol_table st;

void Token_stream::putback(Token t)
{
    buffer = t;                 // copy t to buffer
    full = true;                // buffer is now full
};

Token Token_stream::get()
{
    if (full)
    {
        full = false;
        return buffer;
    }
    char ch = ' ';
    while (ch != '\n' && isspace(ch))
        cin.get(ch);

    switch (ch) {
    case '\n':
        return Token{ print1 };
    case help:
    case '(':
    case ')':
    case '{':
    case '}':
    case '!':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '=':
    case ',':
        return Token{ ch };
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{ number, val };
    }
    default:
        if (isalpha(ch))     //标准库函数，检查字符是不是字母。有效范围为[-1,255]输入中文字符会报错。
        {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || (ch == underscores)))
                //isdigit(), 字符串中的所有字符都是数字字符，则返回 True，否则返回 False。
                s += ch;
            cin.putback(ch);
            if (s == letkey)
                //如果s == "let", 创建一个kind等于let的Token。
                return Token{ let };
            if (s == sqrtkey)
                //如果s == "sqrt", 创建一个kind等于square_root的Token。
                return Token{ square_root };
            if (s == powkey)
                //如果s == "pow", 创建一个kind等于pow的Token。
                return Token{ power };
            if (s == quitkey)
                //如果s == "quit", 创建一个kind等于quit的Token。
                return Token{ quit };
            if (s == helpkey)
                //如果s == "help", 创建一个kind等于quit的Token。
                return Token{ help };
            //否则，创建一个kind为variable, name为s的Token。
            return Token{ variable, s };
        }
        error("Bad token");
    }
};

// This code first looks at the buffer. 
// If there is a c there, we are finished after discarding that c; 
// otherwise, we need to read characters from cin until we find a c.
void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while (cin.get(ch))
        if (ch == c)
            return;
}

void clean_up_mess(Token_stream& ts)
{
    ts.ignore('\n');
}

double Symbol_table::get_value(std::string s)
{
    for (const Variable& v : var_table)
        if (v.name == s)
            return v.value;
    PPP::error("trying to read undefined variable ", s);
    return -100;
}

void Symbol_table::set_value(string s, double d)
{
    for (Variable& v : var_table)
        if (v.name == s)
        {
            v.value = d;
            return;
        }
    error("tring to write undefined variable ", s);
}

// 检查变量名字是否已定义
// var_table存放用户自定义变量的名字和数值。
bool Symbol_table::is_declared(string var)
{
    for (const Variable& v : var_table)
        if (v.name == var)
            return true;
    return false;
}

// 自定义变量
// 根据传入字符串和数值，创建Variable类型，存入var_table数组。
double Symbol_table::define_name(string var, double val)
{
    if (is_declared(var))
        error(var, " declared twice");
    var_table.push_back(Variable{ var, val });
    return val;
}

double expression(Token_stream& ts);        // forward declaration for primary to call


// This function is adapted from Chrinkus/stroustrup-ppp
// Original source: https://github.com/Chrinkus/stroustrup-ppp
// 这个函数处理表达式中的变量
// 如果变量后跟 “=”，就是给变量赋值。
// 如果没有，则返回变量的值。
double handle_variable(Token& t, Token_stream& ts)
{
    Token t2 = ts.get();
    if (t2.kind == '=')
        st.set_value(t.name, expression(ts));
    else
        ts.putback(t2);
    return st.get_value(t.name);
}

// 处理表达式的括号，数字，数字前的正负号，自定义变量。
//      如果是括号，返回里面的表达式的值。
//      如果是正负号，根据正负号返回后面的表达式的值或其相反数。
//      如果是数字，直接返回数字的值。
//      如果是变量，根据变量后是否是‘=’，决定是否更改变量的值，然后返回变量的值。
double primary(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
    {
        double d = expression(ts);
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '{':
    {
        double d = expression(ts);
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
        return d;
    }
    case number:
        return t.value;
    case '-':
        return -primary(ts);
    case '+':
        return primary(ts);
    case variable:
        return handle_variable(t, ts);
    default:
        if (t.kind == print1)
            ts.putback(t);
        error("primary expected");
    }
}

// This function is adapted from Chrinkus/stroustrup-ppp
// Original source: https://github.com/Chrinkus/stroustrup-ppp
// 处理阶乘
double secondary(Token_stream& ts)
{
    double left = primary(ts);
    Token t = ts.get();
    while (true)
    {
        if (t.kind == '!')
        {
            if (left == 0)
                return 1;
            for (int i = left - 1; i > 0; --i)
                left *= i;
            t = ts.get();
        }
        else {
            ts.putback(t);
            return left;
        }
    }
}

// deal with * and / and %
double term(Token_stream& ts)
{
    double left = secondary(ts);
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '*':
            left *= secondary(ts);
            t = ts.get();
            break;
        case '/':
        {
            double d = secondary(ts);
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = secondary(ts);
            if (d == 0)
                error("%: divide by zero");
            left = fmod(left, d);       //fmod()，标准库函数 floating-point modulo
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);      // put t back into the Token_stream
            return left;
        }
    }
}

double expression(Token_stream& ts)         // deal with + and -
{
    double left = term(ts);           // read and evaluate a term
    Token t = ts.get();             // get next token from Token_stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term(ts);     // evaluate term and add
            t = ts.get();
            break;
        case '-':
            left -= term(ts);     // evaluate term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);      // put t back into the token stream
            return left;
        }
    }
}

//定义变量。
//      变量名 = 表达式;
double declaration(Token_stream& ts)
{
    Token t = ts.get();
    if (t.kind != variable)
        PPP::error("variable expected in declaration");

    Token t2 = ts.get();
    if (t2.kind != '=')
        error("= missing in declaration of ", t.name);
    double d = expression(ts);
    st.define_name(t.name, d);
    return d;
}

//算平方根
double square_root_func(Token_stream& ts)
{
    Token t = ts.get();
    if (t.kind != '(')
        error("'(' expected after sqrt");
    ts.putback(t);
    double d = expression(ts);
    if (d < 0)
        error("argument of sqrt() should be greater than 0");
    return sqrt(d);
}

//幂
double power_func(Token_stream& ts)
{
    Token t = ts.get();
    if (t.kind != '(')
        error("'(' expected after pow");
    //ts.putback(t);    //这里不把括号放回去，因为expression()不能处理逗号
    double d1 = expression(ts);        //获取第一个参数
    t = ts.get();        //调用expression()后，ts的buffer里应该是‘,’。
    if (t.kind != ',')
        error("',' expected after the first argument of pow()");
    double d2 = expression(ts);       //获取第二个参数
    int index = int(d2);
    if (index != d2)
        error("index of pow() should be an integer");
    t = ts.get();
    if (t.kind != ')')
        error("')' expected after pow");
    return pow(d1, d2);
}

//对定义变量或计算算式的表达式进行不同的处理。
double statement(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind)
    {
    case let:
        //在进入定义之前，“let”放在这个函数的局部变量t里，进入定义后直接不用处理“let”。
        //return后，t被销毁，“let”被吃掉。
        return declaration(ts);
    case square_root:
        return square_root_func(ts);
    case power:
        return power_func(ts);
    default:
        //因为没有“let”，所以要把Token放回去，不然expression()从ts获取的是不完整的表达式。
        ts.putback(t);
        return expression(ts);
    }
}

void print_help()
{
    cout << "This calculator supports '+', '-', '*', '/', '%', '!' operations." << '\n'
        << "    To calculate, type expressions like '1+2', '8/4', '(11%(1+2)!)' and I'll return their answers." << '\n'
        << "Functions of sqrt() for square root and pow() for exponentiation are available too." << '\n'
        << "    To use sqrt(), type sqrt(9) and I'll return the square root of 9 (3)." << '\n'
        << "    To use pow(), type pow(5, 2) and I'll return x to the power of i (25)." << '\n'
        << "You can use 'let' to define a variable, as 'let x = {2 * (3 + 4) - 5 / 6};'." << '\n'
        << "    You can use the variable you have defined in later expressions." << '\n'
        << "    Examples: 'x', 'x+1', 'x%5', 'sqrt(x-2)', and 'pow(2*x, x)'" << '\n'
        << "    Special variables like pi = 3.1415926535, e = 2.7182818284 and k = 1000 are already defined in the calculator." << '\n'
        << "Type a newline (Enter key) to end an expression." << '\n';
}

void calculate()
{
    st.define_name("pi", 3.1415926535);
    st.define_name("e", 2.7182818284);
    st.define_name("k", 1000);
    cout << "Simple Calculator (type 'help' for manual)" << '\n';
    Token_stream ts;
    while (cin)
    {
        try
        {
            std::cout << prompt;
            Token t = ts.get();
            while (t.kind == print1)
                t = ts.get();               //处理连续的“;”，把最后一个“;”存入ts的buffer。
            if (t.kind == quit)
                return;
            if (t.kind == help)
            {
                print_help();
                continue;
            }
            ts.putback(t);
            cout << "= " << statement(ts) << '\n';
        }
        catch (exception& e)
        {
            cerr << e.what() << '\n';
            clean_up_mess(ts);
        }
    }
}






