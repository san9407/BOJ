#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000001;
const long long LINF = 1e18 + 1;
typedef long long ll;

int a[249];
int dp[249][249];

int go(int s, int e)
{
	int& ret = dp[s][e];
	if (ret != -1)
		return ret;
	if (s == e)
		return ret = a[s];
	ret = 0;
	for (int i = s; i < e; i++)
	{
		int t1 = go(s, i);
		int t2 = go(i + 1, e);
		if (t1 == t2)
			ret = max(ret, t1 + 1);
	}
	return ret;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", a + i);
	}
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			ans = max(ans, go(i, j));
		}
	}
	printf("%d\n", ans);
	return 0;
}
