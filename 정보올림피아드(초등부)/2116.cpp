#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning(disable:4996)

int arr[10000][6];
int rev[6] = { 5,3,4,1,2,0 };

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int maxx = 0;
	for (int i = 0; i < 6; i++)
	{
		int sum = 0;
		int top = arr[0][i];
		int maxx2 = 0;
		for (int j = 0; j < 6; j++)
		{
			if (i == j || j == rev[i])
				continue;
			maxx2 = max(maxx2, arr[0][j]);
		}
		sum += maxx2;
		for (int j = 1; j < N; j++)
		{
			int maxx3 = 0;
			int idx = 0;
			for (int k = 0; k < 6; k++)
			{
				if (top == arr[j][k])
				{
					idx = k;
					break;
				}
			}
			for (int k = 0; k < 6; k++)
			{
				if (arr[j][k] == top || k == rev[idx])
					continue;
				maxx3 = max(maxx3, arr[j][k]);
			}
			sum += maxx3;
			top = arr[j][rev[idx]];
		}
		maxx = max(sum, maxx);
	}
	printf("%d\n", maxx);
	return 0;
}
