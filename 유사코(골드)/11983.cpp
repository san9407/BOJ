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

int N,M;
char A[1001];
char B[1001];
int dp[1000][1000];

int  dist(int x1, int y1, int x2, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int go(int l, int r,int x1,int y1,int x2,int y2)
{
	if (l == N && r == M)
		return 0;
	if (l == N || r == M)
		return INF;
	int& ret = dp[l][r];
	if (ret != -1)
		return ret;
	ret = INF;
	if (A[l] == 'N')
	{
		ret = min(ret, go(l+1, r, x1, y1 + 1, x2, y2) + dist(x1,y1+1,x2,y2));
		if (B[r] == 'N')
		{
			ret = min(ret, go(l + 1, r + 1, x1, y1 + 1, x2, y2 + 1) + dist(x1, y1 + 1, x2, y2 + 1));
		}
		else if (B[r] == 'S')
		{
			ret = min(ret, go(l + 1, r + 1, x1, y1 + 1, x2, y2 - 1) + dist(x1, y1 + 1, x2, y2 - 1));
		}
		else if (B[r] == 'W')
		{
			ret = min(ret, go(l + 1, r + 1, x1, y1 + 1, x2-1, y2) + dist(x1, y1 + 1, x2-1, y2));
		}
		else if (B[r] == 'E')
		{
			ret = min(ret, go(l + 1, r + 1, x1, y1 + 1, x2+1, y2) + dist(x1, y1 + 1, x2+1, y2));
		}
	}
	else if (A[l] == 'S')
	{
		ret = min(ret, go(l+1, r, x1, y1 - 1, x2, y2) + dist(x1, y1 - 1, x2, y2));
		if (B[r] == 'N')
		{
			ret = min(ret, go(l + 1, r + 1, x1, y1 - 1, x2, y2 + 1) + dist(x1, y1 - 1, x2, y2 + 1));
		}
		else if (B[r] == 'S')
		{
			ret = min(ret, go(l + 1, r + 1, x1, y1 - 1, x2, y2 - 1) + dist(x1, y1 - 1, x2, y2 - 1));
		}
		else if (B[r] == 'W')
		{
			ret = min(ret, go(l + 1, r + 1, x1, y1 - 1, x2 - 1, y2) + dist(x1, y1 - 1, x2 - 1, y2));
		}
		else if (B[r] == 'E')
		{
			ret = min(ret, go(l + 1, r + 1, x1, y1 - 1, x2 + 1, y2) + dist(x1, y1 - 1, x2 + 1, y2));
		}
	}
	else if (A[l] == 'W')
	{
		ret = min(ret, go(l+1, r, x1-1, y1, x2, y2) + dist(x1-1, y1, x2, y2));
		if (B[r] == 'N')
		{
			ret = min(ret, go(l + 1, r + 1, x1-1, y1, x2, y2 + 1) + dist(x1-1, y1, x2, y2 + 1));
		}
		else if (B[r] == 'S')
		{
			ret = min(ret, go(l + 1, r + 1, x1-1, y1, x2, y2 - 1) + dist(x1-1, y1, x2, y2 - 1));
		}
		else if (B[r] == 'W')
		{
			ret = min(ret, go(l + 1, r + 1, x1-1, y1, x2 - 1, y2) + dist(x1-1, y1, x2 - 1, y2));
		}
		else if (B[r] == 'E')
		{
			ret = min(ret, go(l + 1, r + 1, x1-1, y1, x2 + 1, y2) + dist(x1-1, y1, x2 + 1, y2));
		}
	}
	else if (A[l] == 'E')
	{
		ret = min(ret, go(l+1, r, x1+1, y1, x2, y2) + dist(x1+1, y1, x2, y2));
		if (B[r] == 'N')
		{
			ret = min(ret, go(l + 1, r + 1, x1+1, y1, x2, y2 + 1) + dist(x1+1, y1, x2, y2 + 1));
		}
		else if (B[r] == 'S')
		{
			ret = min(ret, go(l + 1, r + 1, x1+1, y1, x2, y2 - 1) + dist(x1+1, y1, x2, y2 - 1));
		}
		else if (B[r] == 'W')
		{
			ret = min(ret, go(l + 1, r + 1, x1+1, y1, x2 - 1, y2) + dist(x1+1, y1, x2 - 1, y2));
		}
		else if (B[r] == 'E')
		{
			ret = min(ret, go(l + 1, r + 1, x1+1, y1, x2 + 1, y2) + dist(x1+1, y1, x2 + 1, y2));
		}
	}

	if (B[r] == 'N')
	{
		ret = min(ret, go(l, r + 1, x1, y1, x2, y2 + 1) + dist(x2, y2 + 1, x1, y1));
	}
	else if (B[r] == 'S')
	{
		ret = min(ret, go(l, r + 1, x1, y1, x2, y2 - 1) + dist(x2, y2 - 1, x1, y1));
	}
	else if (B[r] == 'W')
	{
		ret = min(ret, go(l, r + 1, x1, y1, x2-1, y2) + dist(x2-1, y2, x1, y1));
	}
	else if (B[r] == 'E')
	{
		ret = min(ret, go(l, r + 1, x1, y1, x2+1, y2) + dist(x2+1, y2, x1, y1));
	}
	return ret;
}

int main()
{
	scanf("%d %d", &N,&M);
	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	scanf("%s %s", A, B);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 0,x1,y1,x2,y2));
	return 0;
}
