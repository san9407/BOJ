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

int cnt[1001];

int main()
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		int num;
		scanf("%d", &num);
		cnt[num]++;
		sum += num;
	}
	int maxx = 0;
	int idx = 0;
	for (int i = 0; i <= 1000; i++)
	{
		if (maxx < cnt[i])
		{
			maxx = cnt[i];
			idx = i;
		}
	}
	printf("%d\n%d\n", sum / 10, idx);
	return 0;
}
