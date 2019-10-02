#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning(disable:4996)

int N, M;
int arr[50001];
int psum[50001];
int dp[3][50001];

int go(int pos, int idx)
{
	if (pos == 3 || idx > N)
		return 0;
	int& ret = dp[pos][idx];
	if (ret != -1)
		return ret;
	ret = 0;
	
	ret = max(ret, go(pos, idx + 1));
	if (idx - M >= 0)
		ret = max(ret, go(pos + 1, idx + M) + psum[idx] - psum[idx - M]);	
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", arr + i);
		psum[i] = psum[i - 1] + arr[i];
	}
	scanf("%d", &M);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 1));
	return 0;
}
