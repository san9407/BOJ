#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1000000000;

int x[100000];
int y[100000];

int main()
{
	int N,M;
	scanf("%d %d", &N,&M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", x + i, y + i);
	}
	sort(x, x + M);
	sort(y, y + M);
	int ans = 0;
	int mx = x[M / 2];
	int my = y[M / 2];
	for (int i = 0; i < M; i++)
	{
		ans += abs(x[i] - mx);
		ans += abs(y[i] - my);
	}
	printf("%d\n", ans);
	return 0;
}
