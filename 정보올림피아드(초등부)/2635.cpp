#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main()
{
	int N;
	scanf("%d", &N);
	int maxx = 0;
	int a, b, c;
	int ans;
	for (int i = 0; i <= N; i++)
	{
		int cnt = 0;
		a = N;
		b = i;
		while (b >= 0)
		{
			cnt++;
			c = a - b;
			a = b;
			b = c;
		}
		if (cnt > maxx)
		{
			maxx = cnt;
			ans = i;
		}
	}
	printf("%d\n%d", maxx+1,N);
	a = N;
	b = ans;
	while (b >= 0)
	{
		printf(" %d", b);
		c = a - b;
		a = b;
		b = c;
	}
	puts("");
	return 0;
}
