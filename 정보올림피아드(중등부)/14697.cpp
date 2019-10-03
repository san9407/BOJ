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

int dp[301];

int main()
{
	int arr[3], N;
	for (int i = 0; i < 3; i++)
		scanf("%d", arr + i);
	scanf("%d", &N);
	dp[0] = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = arr[i]; j <= N; j++)
		{
			dp[j] += dp[j - arr[i]];
		}
	}
	puts(dp[N] ? "1" : "0");
	return 0;
}
