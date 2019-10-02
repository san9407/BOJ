#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1000000000;

char arr[1000][31];
vector<int> adj[1000];
int path[1000];
int dist[1000];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", arr[i]);
	}
	for (int i = 0; i < N; i++)
	{
		dist[i] = INF;
		for (int j = i+1; j < N; j++)
		{
			if (i == j)
				continue;
			int cnt = 0;
			for (int k = 0; k < K; k++)
			{
				if (arr[i][k] != arr[j][k])
				{
					cnt++;
				}
			}
			if(cnt==1)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	int S, E;
	scanf("%d %d", &S, &E);
	S--;
	E--;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
	dist[S] = 0;
	pq.push({ 0,S });
	while (!pq.empty())
	{
		int curr = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[curr].size(); i++)
		{
			int next = adj[curr][i];
			if (dist[next] > dist[curr] + 1)
			{
				dist[next] = dist[curr] + 1;
				path[next] = curr;
				pq.push({ dist[next],next });
			}
		}
	}
	if (dist[E] == INF)
		puts("-1");
	else
	{
		printf("%d ", S + 1);
		stack<int> s;
		s.push(E);
		for (int i = path[E]; dist[i] != 0; i = path[i])
			s.push(i);
		while (!s.empty())
		{
			printf("%d ", s.top()+1);
			s.pop();
		}
		puts("");
	}
	return 0;
}
