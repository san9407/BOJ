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

bool check[1002][1002];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main()
{
	int C, R, K;
	scanf("%d %d %d", &C, &R, &K);
	for (int i = 0; i <= 1001; i++)
	{
		check[i][0] = check[0][i] = check[C+1][i] = check[i][R+1] = true;
	}
	int x = 1, y = 1;
	int d = 0;
	for (int i = 1; i <= C * R; i++)
	{
		check[x][y] = true;
		if (check[x + dx[d]][y + dy[d]])
			d = (d + 1) % 4;
		if (i == K)
		{
			printf("%d %d", x, y);
			return 0;
		}
		x += dx[d];
		y += dy[d];
	}
	puts("0");
	return 0;
}
