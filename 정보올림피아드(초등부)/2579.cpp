#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int MAX = 300000;
const int MOD = 10007;

int N;
int arr[301];
int dp[301][3];

int go(int pos, int step)
{
	if (pos > N)
		return -INF;
	if (pos == N)
		return arr[pos];
	int& ret = dp[pos][step];
	if (ret != -1)
		return ret;
	ret = 0;
	if (step <= 1)
	{
		int m1 = go(pos + 1, step + 1);
		int m2 = go(pos + 2, 1);
		if (m1 == -INF)
			ret = max(ret, m2 + arr[pos]);
		else if (m2 == -INF)
			ret = max(ret, m1 + arr[pos]);
		else
			ret = max(m1, m2) + arr[pos];
	}
	else
	{
		int m1 = go(pos + 2, 1);
		if (m1 != -INF)
			ret = max(ret, m1 + arr[pos]);
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", arr + i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 0));
	return 0;
}
