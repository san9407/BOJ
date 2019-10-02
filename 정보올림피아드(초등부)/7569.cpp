#include<cstdio>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

int N, M, H;

int arr[101][101][101];
int map[101][101][101];
bool check[101][101][101];
int dx[6] = { -1,0,0,1,0,0 };
int dy[6] = { 0,-1,1,0 ,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
int cnt = 0;

queue<pair<pair<int, int>, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int rx = q.front().first.first;
		int ry = q.front().first.second;
		int rz = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int tx = rx + dx[i];
			int ty = ry + dy[i];
			int tz = rz + dz[i];
			if (tx < 1 || ty<1 || tz<1 || tx>M || ty>N || tz>H || check[tx][ty][tz] == true || arr[tx][ty][tz] == -1)
			{
				continue;
			}
			else
			{
				check[tx][ty][tz] = true;
				map[tx][ty][tz] = map[rx][ry][rz] + 1;
				q.push({ {tx,ty},tz });
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &H);
	for (int z = 1; z <= H; z++)
	{
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{

				int k;
				scanf("%d", &k);
				arr[i][j][z] = k;
				if (k == -1)
				{
					map[i][j][z] = -1;
				}
			}
		}
	}
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int z = 1; z <= H; z++)
			{
				if (check[i][j][z] == false && arr[i][j][z] == 1)
				{
					q.push({ { i,j },z });
					check[i][j][z] = true;
					map[i][j][z] = 1;
				}
			}
		}
	}
	bfs();
	int max = 0;
	bool flag = false;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int z = 1; z <= H; z++)
			{
				if (map[i][j][z] > max)
				{
					max = map[i][j][z];
				}
				if (map[i][j][z] == 0)
				{
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	
	if (max == 1)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", max - 1);
	}
	return 0;
}
