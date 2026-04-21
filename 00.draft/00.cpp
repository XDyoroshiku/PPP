import PPP;
using namespace std;



int main()
{
	int r = 150;
	const double sin_30 = sin(3.14159 / 6);
	const double cos_30 = cos(3.14159 / 6);
	int man = PPP::narrow_cast<int>(r * cos_30);
	cout << man;
}