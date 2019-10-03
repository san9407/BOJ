#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1000000000;

vector<int> adj[100];
vector<int> adj2[100];
bool visit[100];
int cnt = 0;

void dfs(int x)
{
	visit[x] = true;
	cnt++;
	for (int i = 0; i < adj[x].size(); i++)
	{
		int next = adj[x][i];
		if (!visit[next])
			dfs(next);
	}
}

void dfs2(int x)
{
	visit[x] = true;
	cnt++;
	for (int i = 0; i < adj2[x].size(); i++)
	{
		int next = adj2[x][i];
		if (!visit[next])
			dfs2(next);
	}
}

int main()
{
	int N, M;
	scanf("%d %d",&N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		adj[b].push_back(a);
		adj2[a].push_back(b);
	}
	int mid = (N + 1) / 2;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		memset(visit, false, sizeof(visit));
		cnt = 0;
		dfs(i);
		if (cnt > mid)
			ans++;
	}
	for (int i = 0; i < N; i++)
	{
		memset(visit, false, sizeof(visit));
		cnt = 0;
		dfs2(i);
		if (cnt > mid)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
