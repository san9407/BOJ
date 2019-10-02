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
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000001;
const long long LINF = 1e18 + 1;
typedef long long ll;

int N, K;
pair<int, int> arr[100];
pair<int, int> brr[100];
int dp[100][100001];

int go(int pos, int time)
{
	if (pos>N || time > K)
		return -INF;
	if (pos == N)
		return 0;
	int& ret = dp[pos][time];
	if (ret != -1)
		return ret;
	ret = go(pos + 1, time);
	ret = max(go(pos + 1, time + arr[pos].first) + arr[pos].second, go(pos + 1, time+brr[pos].first) + brr[pos].second);
	//ret = max(ret, go(pos + 1, time));
	return ret;
}

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i].first, &arr[i].second);
		scanf("%d %d", &brr[i].first, &brr[i].second);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 0));
	return 0;
}
