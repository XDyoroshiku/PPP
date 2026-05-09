export module _9_5;

export void _9_5();

import PPP;
using namespace std;

void skip_to_int()
// 持续读取，直到碰到数字
{
    if (cin.fail())
    {
        cin.clear();
        for (char ch; cin >> ch;)               // 持续从缓冲区读取，直到读到数字
        {
            if (isdigit(ch) || ch == '-')       // 如果读到数字，把它放回原位，退出函数
            {
                cin.unget();
                return;
            }
        }                                       // 读完缓冲区都没有碰到数字，进入下一行
    }
    PPP::error("no input");                     // 如果是cin为bad状态或者缓冲区没有数字，抛出异常
}

int get_int()
{
    int n = 0;
    while (true)
    {
        if (cin >> n)
            return n;
        cout << "Sorry, that was not a number; please try again" << '\n';
        skip_to_int();
    }
}

int get_int(int low, int high, const string& greeting, const string& sorry)
{
    cout << greeting << ": [" << low << ':' << high << "]" << '\n';

    while (true)
    {
        int n = get_int();
        if (low <= n && n <= high)
            return n;
        cout << sorry << ": [" << low << ':' << high << "]" << '\n';
    }
}

void _9_5()
{
    int strength = get_int(1, 10, "enter strength", "Not in range, try again");
    cout << "strength: " << strength << "\n";
}