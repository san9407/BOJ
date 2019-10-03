#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;

long long dp[16][16];

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M,&K);
	K--;
	int r = K / M;
	int c = K % M;
	for (int i = 0; i < 16; i++)
	{
		dp[0][i] = 1;
		dp[i][0] = 1;
	}
	for (int i = 1; i < 16; i++)
	{
		for (int j = 1; j < 16; j++)
		{
			if (i == 0)
				dp[i][j] = dp[i][j - 1];
			else if (j == 0)
				dp[i][j] = dp[i - 1][j];
			else if(i>0&&j>0)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	if (K == -1)
		printf("%lld\n", dp[N - 1][M - 1]);
	else
		printf("%lld\n", dp[r][c] * dp[N - r-1][M - c-1]);
	return 0;
}
