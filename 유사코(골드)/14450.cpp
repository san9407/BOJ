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

int N, K;
int a[100000];
int dp[100000][21][3];

int go(int pos, int cnt, int cur)
{
	if (cnt > K)
		return 0;
	if (pos == N)
		return 0;
	int& ret = dp[pos][cnt][cur];
	if (ret != -1)
		return ret;
	ret = 0;
	if (cur == 0)
	{
		ret = max({ go(pos + 1, cnt, 0), go(pos + 1, cnt + 1, 1), go(pos + 1, cnt + 1, 2) }) + (a[pos] == cur);
	}
	else if (cur == 1)
	{
		ret = max({ go(pos + 1, cnt, 1), go(pos + 1, cnt + 1, 0), go(pos + 1, cnt + 1, 2) }) + (a[pos] == cur);
	}
	else
	{
		ret = max({ go(pos + 1, cnt, 2), go(pos + 1, cnt + 1, 0), go(pos + 1, cnt + 1, 1) }) + (a[pos] == cur);
	}
	return ret;
}

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		char c;
		scanf(" %c", &c);
		if (c == 'P')
			a[i] = 0;
		else if (c == 'H')
			a[i] = 1;
		else
			a[i] = 2;
	}
	int ans = 0;
	memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 3; i++)
	{
		ans = max(ans, go(0, 0, i));
	}
	printf("%d\n", ans);
	return 0;
}
