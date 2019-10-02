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
const int INF = 1000000000;

int N;
int arr[2000];
int brr[2000];
int dp[2000][2000];

int go(int l, int r)
{
	if (l == N || r == N)
		return 0;
	int& ret = dp[l][r];
	if (ret != -1)
		return ret;
	ret = max(go(l + 1, r), go(l + 1, r + 1));
	if (arr[l] > brr[r])
		ret = max(ret, go(l, r + 1) + brr[r]);
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	for (int i = 0; i < N; i++)
		scanf("%d", brr + i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 0));
	return 0;
}
