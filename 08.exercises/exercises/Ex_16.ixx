// 定义输入操作，读取货币面额(e.g., USD1.23 and DKK5.00)进入Money变量。
// 定义同样的输出操作。

export module Ex_16;

import Money;
import PPP;
using namespace std;

export void Ex_16()
{
	Money m1{ 2 };
	if (!(cin >> m1))
		PPP::error("failed to input m1");
	cout << m1;
}