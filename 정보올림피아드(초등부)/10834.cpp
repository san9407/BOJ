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

int main()
{
	int M;
	scanf("%d", &M);
	int p = 0;
	long long ans = 1;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		p ^= c;
		ans = ans * b / a;
	}
	printf("%d %lld\n", p, ans);
	return 0;
}
