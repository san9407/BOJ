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
int tree[32768];
ll dp[10005];

void init(int node, int start, int end)
{
	if (start == end)
		tree[node] = arr[start];
	else
	{
		int mid = (start + end) >> 1;
		init(node * 2, start, mid);
		init(node * 2 + 1, mid + 1, end);
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}
}

int find(int node, int start, int end, int left, int right)
{
	if (right<start || left>end)
		return -1;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) >> 1;
	int m1 = find(node * 2, start, mid, left, right);
	int m2 = find(node * 2 + 1, mid + 1, end, left, right);
	if (m1 == -1)
		return m2;
	else if (m2 == -1)
		return m1;
	else
		return max(m1, m2);
}

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
	for (int i = 0; i < K; i++)
	{
		ret = max(ret, go(pos + i + 1) + 1LL * (i+1) * find(1, 0, N - 1, pos, pos + i));
	}
	return ret;
}

int main() 
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	init(1,0,N-1);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(0));
	return 0;
}
