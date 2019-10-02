#include<cstdio>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

vector<int> v[101];
bool check[101];
int cnt = 0;

void bfs(int start)
{
	queue<int> q;
	check[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for(int i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i];
			if (!check[next])
			{
				check[next]=true;
				q.push(next);
				cnt++;
			}
		}
	}
}

int main()
{
	int N,M;
	scanf("%d %d", &N,&M);
	for (int i = 0; i < M; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(1);
	printf("%d\n", cnt);
	return 0;
}
