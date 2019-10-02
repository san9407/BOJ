#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

const int INF = 1000000000;
int arr[51][51];
vector<int> vt[51];
int visit[51];
int ans[51];

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	visit[x] = 0;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int i = 0; i < vt[curr].size(); i++)
		{
			int next = vt[curr][i];
			if (visit[next]==-1)
			{
				visit[next] = visit[curr]+1;
				q.push(next);
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int u, v;
	
	while (scanf("%d %d", &u, &v) == 2)
	{
		if (u == -1 && v == -1)
			break;
		vt[u].push_back(v);
		vt[v].push_back(u);
	}
/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(arr[i][j]==0)
				arr[i][j] = INF;
		}
	}
*/
	/*for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][j] > arr[i][k] + arr[k][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}*/
	int maxx = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(visit, -1, sizeof(visit));
		bfs(i);
		for (int i = 1; i <= n; i++)
		{
			maxx = max(maxx, visit[i]);
		}
		ans[i] = maxx;
		maxx = 0;
	}
	int minn = INF;
	for (int i = 1; i <= n; i++)
	{
		minn = min(minn, ans[i]);
	}
	vector<int> result;
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == minn)
		{
			result.push_back(i);
		}
	}
	printf("%d %d\n",minn,result.size());
	for (int i = 0; i < result.size(); i++)
	{
		printf("%d ", result[i]);
	}
	puts("");
	return 0;
}
