#include<iostream>
#include<vector>
using namespace std;

vector<int> a(101);
int check[101];
void dfs(int start)
{
	if (check[start] == 2)
	{
		return;
	}
	check[start] += 1;
	dfs(a[start]);
}


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int u;
		cin >> u;
		a[i] = u;
	}
	int cycle = 0;
	for (int i = 1; i <= n; i++)
	{
		dfs(i);
		for (int j = 1; j <= n; j++)
		{
			if (check[j] != 2)
			{
				check[j] = 0;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == 2)
		{
			ans++;
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == 2)
		{
			cout << i << '\n';
		}
	}
}
