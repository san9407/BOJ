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

int main()
{
	int N;
	scanf("%d", &N);
	int ans = 0;
	for (int i = 0; i < 5; i++)
	{
		int num;
		scanf("%d", &num);
		if (num == N)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
