#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int arr[301][301];
bool visit[301][301];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

int main() 
{
	int N, M;
	scanf("%d %d", &N, &M);
	queue<pair<int,int> > q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j])
			{
				q.push(make_pair(i, j));
			}
		}
	}
	int ans = 0;
	stack<pair<int, int> > s;
	int result = 0;
	while (!q.empty())
	{
		result++;
		vector<pair<int, int> > temp;
		queue<pair<int, int>> q2;
		int size = q.size();
		ans = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < size; i++)
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();
			int cnt = 0;
			for (int j = 0; j < 4; j++)
			{
				int ny = cy + dy[j];
				int nx = cx + dx[j];
				if (arr[ny][nx] == 0)
				{
					cnt++;
				}
			}
			if (arr[cy][cx] - cnt <= 0)
			{
				s.push(make_pair(cy, cx));
			}
			else
			{
				arr[cy][cx] -= cnt;
				temp.push_back(make_pair(cy, cx));
				q.push(make_pair(cy, cx));
			}
		}
		while (!s.empty())
		{
			pair<int,int> t = s.top();
			s.pop();
			arr[t.first][t.second] = 0;
		}
		for (int i = 0; i < temp.size(); i++)
		{
			int y = temp[i].first;
			int x = temp[i].second;
			if (!visit[y][x])
			{
				ans++;
				visit[y][x] = true;
				q2.push(make_pair(y, x));
				while (!q2.empty())
				{
					int cy = q2.front().first;
					int cx = q2.front().second;
					q2.pop();
					for (int j = 0; j < 4; j++)
					{
						int ny = cy + dy[j];
						int nx = cx + dx[j];
						if (arr[ny][nx] && !visit[ny][nx])
						{
							visit[ny][nx] = true;
							q2.push(make_pair(ny, nx));
						}
					}
				}
			}
			else
				continue;
		}
		if (ans >= 2)
		{
			printf("%d\n", result);
			return 0;
		}
	}
	puts("0");
	return 0;
}
