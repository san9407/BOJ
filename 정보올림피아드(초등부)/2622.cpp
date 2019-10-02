#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning(disable:4996)


int main()
{
	int N;
	scanf("%d", &N);
	if (N < 3)
	{
		puts("0");
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N-i; j++)
		{
			int k = N - i - j;
			if (k < j)
				break;
			if (i + j > k)
				cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
