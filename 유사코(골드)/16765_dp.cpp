#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const long long LINF = 1e18 + 1;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> P;

int N, K;
int arr[10000];
ll dp[10000];

ll go(int pos)
{
	if (pos > N)
		return -LINF;
	if (pos == N)
		return 0;
	ll& ret = dp[pos];
	if (ret != -1)
		return ret;
	ret = 0;
	ll maxx = arr[pos];
	for (int i = 0; i < K; i++)
	{
		maxx = max(maxx, (ll)arr[pos + i]);
		ret = max(ret, go(pos + i + 1) +1LL*maxx*(i+1));
	}
	return ret;
}

int main() 
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(0));
	return 0;
}
