#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

int N,M;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
char arr[51][51];
int map[51][51];
bool check[51][51];


int bfs(int y,int x)
{
	int mx = 0;
	queue<pair<int,int>> q;
	q.push({ y, x });
	while (!q.empty())
	{
		int ry = q.front().first;
		int rx = q.front().second;
		q.pop();
		if (map[ry][rx] > mx)
		{
			mx = map[ry][rx];
		}
		for (int i = 0; i < 4; i++)
		{
			int ty = ry + dy[i];
			int tx = rx + dx[i];
			if (ty < 0 || tx < 0 || tx >= M || ty >= N || check[ty][tx] == true || arr[ty][tx]=='W')
			{
				continue;
			}
			else
			{
				check[ty][tx] = true;
				map[ty][tx] = map[ry][rx] + 1;
				q.push({ ty,tx });
			}
		}
	}
	return mx;
}

int main()
{
	scanf("%d %d", &N,&M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", arr[i]);
	}
	int max = 0;
	int max2 = 0;
	int tmp = 0;
	int z1, z2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j]=='L')
			{
				map[i][j] = 0;
				tmp=bfs(i, j);
				if (max2 < tmp)
				{
					max2 = tmp;
				}
				memset(check, false, sizeof(check));
				memset(map, 0, sizeof(map));
			}
		}
	}

	printf("%d\n", max2);
	return 0;
}
