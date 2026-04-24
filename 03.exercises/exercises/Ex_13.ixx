export module Ex_13;

export void Ex_13();

import std;
using namespace std;

vector<int> sieve(const int& n)
{
	vector<int> primes{ 2 };
	if (n < 2)
	{
		cerr << "n should be greater than 2." << '\n';
		return primes;
	}

	int sqrt_n = int(sqrt(n)) + 1;
	for (int i = 3; i < n; i += 2)
	{
		int size = (int)primes.size();
		bool is_prime = true;
		for (int j = 0; j < min(size, sqrt_n); ++j)
		{
			if (i % primes[j] == 0)
			{
				is_prime = false;
				break;
			}
		}
		if (is_prime)
			primes.push_back(i);
	}
	return primes;
}

void Ex_13()
{
	vector<int> primes = sieve(100);

	for (size_t i = 0; i < primes.size(); ++i)
		cout << primes[i] << '\n';
}