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

ll dp[81];
ll dp2[81];

int main()
{
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= 80; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	dp2[1] = 4;
	dp2[2] = 6;
	dp2[3] = 10;
	for (int i = 4; i <= 80; i++)
	{
		dp2[i] = dp2[i - 1] + 2 * dp[i];
	}
	int N;
	scanf("%d", &N);
	printf("%lld\n", dp2[N]);
	return 0;
}
