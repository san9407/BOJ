#include<iostream>
#include<string>
using namespace std;

int arr[41];
int dp[41];

int main()
{
	string str;
	cin >> str;
	for (int i = 1; i <= str.size(); i++)
	{
		arr[i] = str[i-1] - '0';
	}
	dp[0] = 1;
	for (int i = 1; i <= str.size(); i++)
	{
		if (1 <= arr[i] && arr[i] <= 9)
		{
			dp[i] += dp[i - 1];
		}
		if (arr[i - 1] == 0)
		{
			continue;
		}
		int tmp = arr[i - 1] * 10 + arr[i];
		if (10 <= tmp && tmp <= 34)
		{
			dp[i] += dp[i - 2];
		}
	}
	cout << dp[str.size()] << "\n";
	return 0;
}
