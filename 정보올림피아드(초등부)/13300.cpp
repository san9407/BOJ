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

int cnt[2][6];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		int S, Y;
		scanf("%d %d", &S, &Y);
		cnt[S][Y-1]++;
	}
	int ans = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			ans += cnt[i][j] / K;
			ans += (cnt[i][j] % K != 0);
		}
	}
	printf("%d\n", ans);
	return 0;
}
