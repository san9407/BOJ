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

int N, M;
int dp[101][40];
bool check[101];

int go(int pos, int c)
{
	if (pos > N || c > 40)
		return INF;
	if (pos == N)
		return 0;
	int& ret = dp[pos][c];
	if (ret != -1)
		return ret;
	ret = INF;
	if (check[pos])
		ret=min(ret,go(pos + 1, c));
	else
	{
		ret = min({ go(pos + 5, c + 2) + 37000,go(pos + 3, c + 1) + 25000, go(pos + 1, c) + 10000 });
		if (c >= 3)
		{
			ret = min(ret, go(pos + 1, c - 3));
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int day;
		scanf("%d", &day);
		day--;
		check[day] = true;
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n",go(0, 0));
	return 0;
}
