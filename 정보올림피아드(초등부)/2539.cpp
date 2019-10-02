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
const int INF = 1000000000;

pair<int, int> p[1000];

int main()
{
	int h, w;
	scanf("%d %d", &h, &w);
	int k;
	scanf("%d", &k);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i].second, &p[i].first);
	sort(p, p + n);
	int l = 0, r = max(h, w);
	while (l + 1 < r)
	{
		int mid = (l + r) >> 1;
		int cnt = 0;
		int square = 0;
		bool visit[1000] = { false, };
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			if (visit[i])
				continue;
			visit[i] = true;
			square++;
			int sx = p[i].first;
			cnt++;
			for (int j = 0; j < n; j++)
			{
				if (visit[j])
					continue;
				int nx = p[j].first;
				int ny = p[j].second;
				if (sx + mid > nx && ny <= mid)
				{
					visit[j] = true;
					cnt++;
				}
				else if (ny > mid)
				{
					flag = true;
					break;
				}
			}
		}
		if (square > k||flag)
			l = mid;
		else
			r = mid;
	}
	printf("%d\n", r);
	return 0;
}
