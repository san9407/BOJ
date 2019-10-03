#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <set>
#include <stack>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const long long LINF = 1e18 + 1;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> P;

vector<P> adj[1000];
int point[1000];
int path[1000];

void dijkstra(int start)
{
	priority_queue<P> pq;
	pq.push({ 0,start });
	point[start] = 0;
	while (!pq.empty())
	{
		int curr = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[curr].size(); i++)
		{
			int next = adj[curr][i].first;
			int nextCost = adj[curr][i].second;
			if (point[next] < point[curr] + nextCost)
			{
				point[next] = point[curr] + nextCost;
				path[next] = curr;
				if(next!=start)
					pq.push({ point[next],next });
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
		int p, q, r;
		scanf("%d %d %d", &p, &q, &r);
		p--;
		q--;
		adj[p].emplace_back(q, r);
	}
	memset(point, -1, sizeof(point));
	memset(path, -1, sizeof(path));
	dijkstra(0);
	stack<int> s;
	for (int i = path[0]; i != 0; i = path[i])
		s.push(i + 1);
    
	printf("%d\n1 ",point[0]);
	while (!s.empty())
	{
		printf("%d ", s.top());
		s.pop();
	}
	puts("1");
	return 0;
}
