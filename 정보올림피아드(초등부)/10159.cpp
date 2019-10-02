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

int a[101][101];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
	}
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (a[i][k] && a[k][j])
					a[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		int ans = -1;
		for (int j = 1; j <= N; j++)
		{
			if (!a[i][j] && !a[j][i])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
