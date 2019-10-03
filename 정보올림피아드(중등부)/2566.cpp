#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <set>
#include <stack>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const long long LINF = 1e18 + 1;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
	int maxx = 0;
	int x=0, y = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int num;
			scanf("%d", &num);
			if (maxx < num)
			{
				maxx = num;
				x = i + 1;
				y = j + 1;
			}
		}
	}
	
	printf("%d\n%d %d\n", maxx, x, y);
	return 0;
}
