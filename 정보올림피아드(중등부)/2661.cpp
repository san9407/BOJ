#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
#define long long ll;
const int INF = 1000000000;
const int MAX = 10000;

int N, ans[80];
bool flag;

bool dfs(int pos)
{
	if (pos == N)
	{
		flag = true;
		return true;
	}
	for (int i = 1; i <= 3; i++)
	{
		ans[pos] = i;
		bool fail = false;
		for (int j = 1; j <= (pos + 1) / 2; j++)
		{
			bool same = true;
			for (int k = 0; k < j; k++)
			{
				if (ans[pos - k] != ans[pos - j - k])
				{
					same = false;
					break;
				}
			}
			if (same)
			{
				fail = true;
				break;
			}
		}
		if (!fail && dfs(pos + 1))
			return true;
		if (flag)
			return true;
	}
	return false;
}

int main()
{
	scanf("%d", &N);
	dfs(0);
	for (int i = 0; i < N; i++)
		printf("%d", ans[i]);
	puts("");
	return 0;
}
