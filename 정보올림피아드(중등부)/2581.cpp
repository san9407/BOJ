#include<iostream>
using namespace std;

bool prime[10001];

int main()
{
	int M, N;
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i*i < 10001; i++)
	{
		if (prime[i] == false)
		{
			for (int j = i * 2; j <= 10001; j += i)
			{
				prime[j] = true;
			}
		}
	}
	cin >> M >> N;
	int sum = 0;
	for (int i = M; i <= N; i++)
	{
		if (prime[i] == false)
		{
			sum += i;
		}
	}

	if (sum == 0)
	{
		cout << "-1\n";
	}
	else
	{
		cout << sum << '\n';
		for (int i = M; i <= N; i++)
		{
			if (prime[i] == false)
			{
				cout << i << '\n';
				return 0;
			}
		}
	}

	return 0;
}
