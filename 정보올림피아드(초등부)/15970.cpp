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

vector<int> color[5000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		y--;
		color[y].push_back(x);
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (color[i].empty())
			continue;
		sort(color[i].begin(), color[i].end());
		int sz = color[i].size();
		ans += color[i][1] - color[i][0] + color[i][sz - 1] - color[i][sz - 2];
		for (int j = 1; j < sz - 1; j++)
		{
			ans += min(color[i][j] - color[i][j - 1], color[i][j + 1] - color[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
