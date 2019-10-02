#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning(disable:4996)

int board[19][19];
bool check[19][19];

int dx[4] = { -1,0,1,1 };
int dy[4] = { 1,1,1,0 };

int main()
{
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			scanf("%d", &board[i][j]);
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (board[j][i]&&!check[j][i])
			{
				int color = board[j][i];
				for (int k = 0; k < 4; k++)
				{
					int cnt = 0;
					int cx = j;
					int cy = i;
					int nx = cx, ny = cy;
					for (int t = 0; t < 5; t++)
					{
						nx += dx[k];
						ny += dy[k];
						if (nx >= 19 || ny >= 19 || board[nx][ny] != color)
							break;
						else
							cnt++;
					}
					if (cnt >= 5)
					{
						nx = cx, ny = cy;
						check[cx][cy] = true;
						while (nx < 19 && ny < 19)
						{
							nx += dx[k];
							ny += dy[k];
							check[nx][ny] = true;
						}
					}
					if (cnt == 4)
					{
						printf("%d\n%d %d", color, j+1, i+1);
						return 0;
					}
				}
			}
		}
	}
	puts("0");
	return 0;
}
