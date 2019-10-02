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

struct Node
{
	int c;
	int g, s, b;
	bool operator<(const Node& A)
	{
		if (g == A.g)
		{
			if (s == A.s)
				return b > A.b;
			else
				return s > A.s;
		}
		else
			return g > A.g;
	}
};

Node arr[1000];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		int country;
		scanf("%d", &country);
		int gold, silver, bronze;
		scanf("%d %d %d", &gold, &silver, &bronze);
		arr[i].c = country;
		arr[i].g = gold;
		arr[i].s = silver;
		arr[i].b = bronze;
	}
	sort(arr, arr + N);
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i].c == K)
		{
			idx = i;
			break;
		}
	}
	int ans = 0;
	for (int i = idx; i >= 0; i--)
	{
		if (arr[idx].g != arr[i].g || arr[idx].s != arr[i].s || arr[idx].b != arr[i].b)
		{
			ans = i + 1;
			break;
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}
