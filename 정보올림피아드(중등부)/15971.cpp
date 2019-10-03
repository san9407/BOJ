#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <functional>
#include <tuple>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000001;
const long long LINF = 1e18 + 1;
typedef long long ll;

vector<pair<int,int> > adj[100000];
int dist[100000];
int maxx[100000];

void dfs(int cur, int prev,int m)
{
	maxx[cur] = m;
	for (int i = 0; i < adj[cur].size(); i++)
	{
		int next = adj[cur][i].first;
		int cost = adj[cur][i].second;
		if (next == prev)
			continue;
		dist[next] = dist[cur] + cost;
		dfs(next, cur,max(m,cost));
	}
}

int main()
{
	int N,S,E;
	scanf("%d %d %d", &N, &S, &E);
	S--;
	E--;
	for (int i = 0; i < N - 1; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--;
		v--;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	dist[S] = 0;
	dfs(S, -1, 0);
	printf("%d\n", dist[E] - maxx[E]);
	return 0;
}
