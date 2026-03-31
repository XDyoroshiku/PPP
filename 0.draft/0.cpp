module PPP;

using namespace std;
using namespace PPP;

int main()
{
    string previous;
    string current;
    while (cin >> current)
    {
        if (previous == current)
            cout << "repeated word: " << current << "\n";
        previous = current;
    }
}