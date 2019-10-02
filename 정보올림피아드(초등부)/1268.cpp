#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;

int arr[1000][5];
int cnt[1000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int ans = 0;
	int maxx = 0;
	for (int i = 0; i < N; i++)
	{
		int count = 0;
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (i == k)
					continue;
				if (arr[i][j] == arr[k][j])
				{
					cnt[k]++;
				}
			}
		}
		for (int j = 0; j < N; j++)
		{
			if (cnt[j] > 0)
			{
				count++;
				cnt[j] = 0;
			}
		}
		if (maxx < count)
		{
			maxx = count;
			ans = i;
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}
