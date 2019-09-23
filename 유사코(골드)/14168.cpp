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

int H, G;
pair<int, int> a[1001];
pair<int, int> b[1001];
int dp[1001][1001][2];

int dist(pair<int, int> A, pair<int, int> B)
{
	return (A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second);
}

int go(int l, int h, int f)
{
	if (l >= H || h > G)
		return INF;
	if (l == H - 1 && h == G && f == 0)
		return 0;

	int& ret = dp[l][h][f];
	if (ret != -1)
		return ret;
	ret = INF;
	if (f == 0)
	{
		ret = min(go(l + 1, h, 0) + dist(a[l], a[l + 1]), go(l+1, h, 1) + dist(a[l], b[h]));
	}
	else
	{
		ret = min(go(l, h + 1, 1) + dist(b[h], b[h + 1]), go(l, h+1, 0) + dist(a[l], b[h]));
	}
	return ret;
}

int main()
{
	scanf("%d %d", &H, &G);
	for (int i = 0; i < H; i++)
		scanf("%d %d", &a[i].first, &a[i].second);
	for (int i = 0; i < G; i++)
		scanf("%d %d", &b[i].first, &b[i].second);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 0, 0));
	return 0;
}
