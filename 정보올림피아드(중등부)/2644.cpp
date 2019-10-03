#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <iostream>
#include <string>
using namespace std;
#define ll long long
const int INF = 1000000000;
const int MAX = 100000;

vector<int> adj[101];
int visit[101];

int main()
{
	int N;
	scanf("%d", &N);
	int x, y;
	scanf("%d %d", &x, &y);
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<int> q;
	q.push(x);
	visit[x] = 1;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int i = 0; i < adj[curr].size(); i++)
		{
			int next = adj[curr][i];
			if (!visit[next])
			{
				visit[next] = visit[curr] + 1;
				q.push(next);
			}
		}
	}
	printf("%d\n", visit[y] ? visit[y] - 1 : -1);
	return 0;
}
