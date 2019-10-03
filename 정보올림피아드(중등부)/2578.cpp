#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 100000;
const long long LINF = 1e18;

int board[5][5];
bool check[5][5];
map<int, pair<int, int> > mp;

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &board[i][j]);
			mp[board[i][j]] = { i,j };
		}
	}
	for (int i = 0; i < 25; i++)
	{
		int num;
		scanf("%d", &num);
		check[mp[num].first][mp[num].second] = true;
		int cnt = 0;
		for (int i = 0; i < 5; i++)
		{
			bool flag = false;
			for (int j = 0; j < 5; j++)
			{
				if (!check[i][j])
				{
					flag = true;
					break;
				}
			}
			if (!flag)
				cnt++;
		}
		for (int i = 0; i < 5; i++)
		{
			bool flag = false;
			for (int j = 0; j < 5; j++)
			{
				if (!check[j][i])
				{
					flag = true;
					break;
				}
			}
			if (!flag)
				cnt++;
		}
		bool flag = false;
		for (int i = 0; i < 5; i++)
		{
			if (!check[i][i])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			cnt++;
		flag = false;
		for (int i = 0; i < 5; i++)
		{
			if (!check[i][4-i])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			cnt++;
		if (cnt >= 3)
		{
			printf("%d\n", i + 1);
			break;
		}
	}
	return 0;
}
