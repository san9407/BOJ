#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning(disable:4996)


int board[100][100];
bool visit[100][100];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

int main()
{
	int N, M;
	scanf("%d %d", &N,&M);
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &board[i][j]);
			cnt += board[i][j];
		}
	}
	int t = 0;
	int ans = cnt;
	while (1)
	{
		queue<pair<int, int> > q;
		queue<pair<int, int> > temp;
		q.push({ 0, 0 });
		visit[0][0] = true;
		while (!q.empty())
		{
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny])
					continue;
				else
				{
					visit[nx][ny] = true;
					if (board[nx][ny] == 0)
					{
						q.push({ nx,ny });
					}
					else
						temp.push({ nx,ny });
				}
			}
		}
		while (!temp.empty())
		{
			int cx = temp.front().first;
			int cy = temp.front().second;
			temp.pop();
			board[cx][cy] = 0;
			cnt--;
		}
		t++;
		if (cnt == 0)
			break;
		ans = cnt;
		memset(visit, false, sizeof(visit));
	}
	printf("%d\n%d\n", t, ans);
	return 0;
}
