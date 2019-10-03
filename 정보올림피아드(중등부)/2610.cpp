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
const int MOD = 998244353;
const int MAX = 10000;
const long long LINF = 1e18;

int par[100];
int board[100][100];
int sz[100];

int find(int x)
{
	if (par[x] < 0)
		return x;
	else
		return par[x] = find(par[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (par[x] < par[y])
	{
		par[x] += par[y];
		par[y] = x;
	}
	else
	{
		par[y] += par[x];
		par[x] = y;
	}
}

int main()
{
	int N, M,K=0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < 100; i++)
	{
		par[i] = -1;
		for (int j = 0; j < 100; j++)
			board[i][j] = (i == j ? 0 : INF);	
	}
	for (int i = 0; i < M; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		board[x][y] = 1;
		board[y][x] = 1;
		merge(x, y);
	}
	int result[100];
	for (int i = 0; i < N; i++)
		if (par[i] < 0)
			par[i] = -(++K);
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
	
	for (int i = 0; i < K; i++)
		sz[i] = INF;
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] != INF)
				temp = max(temp, board[i][j]);
		}
		int group = -par[find(i)]-1;
		if (sz[group] > temp)
		{
			sz[group] = temp;
			result[group] = i + 1;
		}
	}
	sort(result, result + K);
	printf("%d\n", K);
	for (int i = 0; i < K; i++)
		printf("%d\n", result[i]);
	return 0;
}
