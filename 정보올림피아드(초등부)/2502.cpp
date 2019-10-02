#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 100000;
const long long LINF = 1e18;

int dp1[31];
int dp2[31];

int main()
{
	int D, K;
	scanf("%d %d", &D, &K);
	dp1[1] = 1;
	dp1[3] = 1;
	dp2[2] = 1;
	dp2[3] = 1;
	for (int i = 3; i <= D; i++)
	{
		dp1[i] = dp1[i - 1] + dp1[i - 2];
		dp2[i] = dp2[i - 1] + dp2[i - 2];
	}
	int a = dp1[D];
	int b = dp2[D];
	int ans1, ans2;
	for (int i = 1; i <= K; i++)
	{
		int t = K - i * a;
		if (t%b == 0)
		{
			ans1 = i;
			ans2 = t / b;
			break;
		}
	}
	printf("%d\n%d\n", ans1, ans2);
	return 0;
}
