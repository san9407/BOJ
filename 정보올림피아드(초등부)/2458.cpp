#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int MAX = 100000;
const int MOD = 100000007;

vector<int> vt[500];
bool visit[500];
int arr[500][2];
int cnt = 0;

void dfs(int x)
{
	visit[x] = true;
	for (int i = 0; i < vt[x].size(); i++)
	{
		int next = vt[x][i];
		if (!visit[next])
		{
			cnt++;
			arr[next][0]++;
			dfs(next);
		}
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		vt[u].push_back(v);
	}

	for (int i = 0; i < N; i++)
	{
		memset(visit, false, sizeof(visit));
		dfs(i);
		arr[i][1] = cnt;
		cnt = 0;
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i][0] + arr[i][1] == N - 1)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
