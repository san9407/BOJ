#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1000000000;

int N,M;
int arr[30];
int dp[31][30 * 500 + 1];

void go(int pos, int cur)
{
	if (pos > N)
		return;
	int& ret = dp[pos][cur];
	if (ret != -1)
		return;
	dp[pos][cur] = 0;
	go(pos + 1, cur + arr[pos]);
	go(pos + 1, cur);
	go(pos + 1, abs(cur - arr[pos]));
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	scanf("%d", &M);
	memset(dp, -1, sizeof(dp));
	go(0,0);
	for (int i = 0; i < M; i++)
	{
		int num;
		scanf("%d", &num);
		if (num > 30 * 500)
			printf("N ");
		else if (dp[N][num] == 0)
			printf("Y ");
		else
			printf("N ");
	}
	puts("");
	return 0;
}
