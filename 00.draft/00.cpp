import <climits>;
import PPP;
using namespace std;
const string fname = "00.txt";

int main()
{
	ifstream ifs{ fname };
	int x;
	ifs >> x;
	if (!ifs)
		cout << "Error!" << '\n';
	else
		cout << x;
}
