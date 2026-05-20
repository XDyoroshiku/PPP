import <climits>;
import PPP;
using namespace std;
const string fname = "00.txt";

enum class suffix
{
	c, f		// c代表Celsius；f代表Fahrenheit。
};

suffix int_to_suffix(int i)
{
	constexpr int celsius = 0;
	constexpr int fahrenheit = 1;
	if (i != celsius || i != fahrenheit)
		PPP::error("bad suffix");
	return suffix(i);
}

int main()
{
	suffix x = int_to_suffix(3);
	cout << int(x);
}
