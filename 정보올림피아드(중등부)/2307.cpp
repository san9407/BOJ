#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

const int INF = 2000000000;
vector<pair<int, int>> vt[1001];
bool visit[1001];
int ans[1001];
vector<int> f;
int path[1001];

void findPath(int start)
{
	f.push_back(start);
	if (start == 1)
		return;
	findPath(path[start]);
}


void Dijkstra(int start)
{
	ans[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });

	while (!pq.empty())
	{
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (ans[now] < cost)
		{
			continue;
		}
		if (ans[now] == cost && visit[now] == true)
		{
			continue;
		}
		visit[now] = true;
		for (int i = 0; i < vt[now].size(); i++)
		{
			int next = vt[now][i].first;
			int nextCost = vt[now][i].second;
			if (ans[next] > nextCost + ans[now])
			{
				ans[next] = nextCost + ans[now];
				pq.push({ nextCost,next });
				path[next] = now;
			}
		}
	}
}

void Dijkstra2(int start, int x, int y)
{
	ans[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });

	while (!pq.empty())
	{
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (ans[now] < cost)
		{
			continue;
		}
		if (ans[now] == cost && visit[now] == true)
		{
			continue;
		}
		visit[now] = true;
		for (int i = 0; i < vt[now].size(); i++)
		{
			int next = vt[now][i].first;
			int nextCost = vt[now][i].second;
			if ((now == x && next == y) || (now == y && next == x))
			{
				continue;
			}
			else
			{
				if (ans[next] > nextCost + ans[now])
				{
					ans[next] = nextCost + ans[now];
					pq.push({ nextCost,next });
				}
			}
		}
	}
}


int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int u, v, t;
		scanf("%d %d %d", &u, &v, &t);
		vt[u].push_back({ v,t });
		vt[v].push_back({ u,t });
	}
	for (int i = 1; i <= N; i++)
	{
		ans[i] = INF;
	}
	Dijkstra(1);
	int temp = ans[N];
	findPath(N);
	int maxx = 0;
	int vertex = N;

	while (path[vertex] != 0) 
	{
		for (int k = 1; k <= N; k++)
		{
			visit[k] = false;
			ans[k] = INF;
		}
		int u = vertex;
		int v = path[vertex];
		Dijkstra2(1, u, v);
		int zz = ans[N];
		if (maxx < zz)
		{
			maxx = zz;
		}
		vertex = v;
	}

	if (maxx == INF)
		printf("-1\n");
	else
		printf("%d\n", maxx - temp);

	return 0;
}
