#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int arr[101];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", arr + i);
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 1)
		{
			for (int i = b; i <= N; i += b)
			{
				arr[i] ^= 1;
			}
		}
		else
		{
			int le = b, ri = b;
			while (arr[le] == arr[ri]&&le>=1&&ri<=N)
			{
				if (le == ri)
					arr[ri] ^= 1;
				else
				{
					arr[le] ^= 1;
					arr[ri] ^= 1;
				}
				le--;
				ri++;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		printf("%d ", arr[i]);
		if (i % 20 ==0)
			puts("");
	}
	puts("");
	return 0;
}
