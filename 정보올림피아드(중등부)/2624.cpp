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
#include <tuple>
#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000001;
const long long LINF = 1e18 + 1;
typedef long long ll;

int T, K;
pair<int,int> coin[100];
int dp[10001][100];

int go(int money, int pos)
{
	if (money == 0)
		return 1;
	if (money < 0)
		return 0;
	if (pos == K)
		return 0;
	int& ret = dp[money][pos];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i <= coin[pos].second; i++)
	{
		ret += go(money - coin[pos].first * i, pos + 1);
	}
	return ret;
}

int main()
{
	scanf("%d", &T);
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int p, n;
		scanf("%d %d", &p, &n);
		coin[i] = make_pair(p, n);
	}
	memset(dp, -1, sizeof dp);
	printf("%d\n", go(T, 0));
	return 0;
}
