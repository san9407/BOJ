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
const int INF = 1000000000;

int cnt[101];
int board[101][101];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int x, y, w, h;
		scanf("%d %d %d %d", &x, &y, &w, &h);
		for (int j = 0; j < h; j++)
		{
			for (int k = 0; k < w; k++)
			{
				board[y + j][x+k] = i;
			}
		}
	}
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			cnt[board[i][j]]++;
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d\n", cnt[i]);
	return 0;
}
