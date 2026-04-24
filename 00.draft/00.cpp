import PPP;
using namespace std;

int main()
{
    cout << "Please enter two integer values." << endl;
    int val1, val2;
    cin >> val1 >> val2;
    if (val1 < val2)
        cout << val1 << " is smaller than " << val2;
    else if (val1 > val2)
        cout << val1 << " is larger than " << val2;
    else
        cout << val1 << " equals " << val2;
    cout << endl;
    int sum = val1 + val2;
    int difference = val1 - val2;
    int product = val1 * val2;
    int ratio = val1 / val2;

    cout << val1 << " + " << val2 << " == " << sum << endl
        << val1 << " - " << val2 << " == " << difference << endl
        << val1 << " * " << val2 << " == " << product << endl
        << val1 << " / " << val2 << " == " << ratio << endl;
}