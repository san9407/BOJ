#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <map>
#include <set>
#include <stack>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const int MOD = 1000000007;
const long long LINF = 1e18 + 1;
typedef long long ll;

int N, K, S, R[100];
ll dp[100][101][7];

long long barn(int s, int e, int k)
{
	long long& ret = dp[s][e][k];
	if (ret != -1)
		return ret;
	if (e == N)
	{
		ret = 0;
		for (int i = 0; i < S; i++)
			ret += R[i] * (N - s + i);
		return ret;
	}
	ret = barn(s, e + 1, k) + R[e] * (e - s);
	if (k < K - 1)
		ret = min(ret, barn(e, e + 1, k + 1));
	return ret;
}

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%lld", R + i);
	ll result = LINF;
	for (int i = 0; i < N; i++)
	{
		memset(dp, -1, sizeof(dp));
		S = i;
		result = min(result, barn(S, S, 0));
	}
	printf("%lld\n", result);
	return 0;
}
