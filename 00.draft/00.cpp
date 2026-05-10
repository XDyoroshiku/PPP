import <climits>;
import PPP;
using namespace std;

int main()
{
	const int not_a_reading = -7777;
	vector<double> temp = vector<double>(24, not_a_reading);
	for (double x : temp)
		cout << x << '\n';
}