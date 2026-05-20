import <climits>;
import PPP;
using namespace std;
const string fname = "00.txt";

void ist_state(ifstream& ist)
// 依次判断ist处于哪种状态，做出相应处理
{
	if (ist.bad())						// stream corrupted;
		PPP::error("ist is bad");		// let’s get out of here!
	if (ist.fail() && !ist.eof())		// clean up the mess as best we can and report the problem
		PPP::error("ist is fail");
	if (ist.eof())						// fine: we found the end of file
		return;
}

int main()
{
	ifstream ifs{ fname };
	for (int x; ifs >> x; )
		cout << x << '\n';
	ist_state(ifs);
}
