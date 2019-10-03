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
	char str[3][10];
	for (int i = 0; i < 3; i++)
	{
		scanf("%s", str[i]);
		int len = strlen(str[i]);
		int ans = 0;
		int c = 1;
		for (int j = 1; j < len; j++)
		{
			if (str[i][j] == str[i][j - 1])
				c++;
			else
				c = 1;
			ans = max(ans, c);
		}
		printf("%d\n", ans);
	}
	return 0;
}
