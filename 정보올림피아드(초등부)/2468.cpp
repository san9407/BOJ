#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

int N;
int dx[6] = { -1,0,0,1 };
int dy[6] = { 0,-1,1,0 };
int arr[100][100];
bool check[100][100];

void bfs(int x,int y)
{
	queue<pair<int,int>> q;
	q.push({ x, y });
	while (!q.empty())
	{
		int rx = q.front().first;
		int ry = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = rx + dx[i];
			int ty = ry + dy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= N || check[tx][ty] == true)
			{
				continue;
			}
			else
			{
				check[tx][ty] = true;
				q.push({ tx,ty });
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num;
			scanf("%d", &num);
			arr[i][j] = num;
			if (max < num)
			{
				max = num;
			}
		}
	}

	int maxRes = 0;
	for (int i = 1; i <= max; i++)
	{
		int res = 0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				check[j][k] = false;
			}
		}
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (i > arr[j][k])
				{
					check[j][k] = true;
				}
			}
		}
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (check[j][k]==false)
				{
					res++;
					bfs(j,k);
				}
			}
		}
		if (res > maxRes)
		{
			maxRes = res;
		}
	}
	printf("%d\n", maxRes);
	return 0;
}
