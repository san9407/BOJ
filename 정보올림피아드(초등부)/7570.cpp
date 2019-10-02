#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1000000000;

int dp[1000001];

int main()
{
	int N;
	scanf("%d", &N);
	int maxx = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		dp[num] = dp[num - 1] + 1;
		maxx = max(maxx, dp[num]);
	}
	printf("%d\n", N - maxx);
	return 0;
}
