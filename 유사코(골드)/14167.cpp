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
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000001;
const long long LINF = 1e18 + 1;
typedef long long ll;

struct kruskal
{
	int from;
	int to;
	int val;
	bool operator<(const kruskal& A)
	{
		return val < A.val;
	}
};

pair<int, int> arr[1000];
map<pair<int, int>, int> mp;
kruskal ks[550000];
int par[1000];

int find(int x)
{
	if (x == par[x])
		return x;
	return par[x] = find(par[x]);
}

bool merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	par[x] = y;
	return true;
}

int dist(pair<int, int> a, pair<int, int> b)
{
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main()
{
	int N;
	scanf("%d", &N);
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		arr[i] = make_pair(x, y);
		mp[make_pair(x,y)] = idx++;
	}
	for (int i = 0; i < idx; i++)
	{
		par[i] = i;
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			int x1 = arr[i].first;
			int y1 = arr[i].second;
			int x2 = arr[j].first;
			int y2 = arr[j].second;
			ks[cnt].from = mp[{x1, y1}];
			ks[cnt].to = mp[{x2, y2}];
			ks[cnt++].val = dist(arr[i], arr[j]);
		}
	}
	sort(ks, ks + cnt);
	int ans = 0;
	int count = 0;
	for (int i = 0; i < cnt; i++)
	{
		int u = ks[i].from;
		int v = ks[i].to;
		int w = ks[i].val;
		if (merge(u, v))
		{
			count++;
			ans = max(ans, w);
			if (count == N - 1)
				break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
