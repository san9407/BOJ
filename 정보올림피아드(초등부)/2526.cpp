#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1000000000;

map<int, int> mp;

int main()
{
	int N, P;
	scanf("%d %d", &N, &P);
	int temp = N;
	while (mp[temp] != 2)
	{
		mp[temp]++;
		temp *= N;
		temp %= P;
	}
	int cnt = 0;
	for (auto it : mp)
	{
		if (it.second == 2)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
