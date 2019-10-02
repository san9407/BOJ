#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;

int arr[1000][5];
int temp[1000];

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
	for (int i = 0; i < N; i++)
	{
		sort(arr[i], arr[i] + 5);
		do
		{
			temp[i] = max(temp[i], (arr[i][0] + arr[i][1] + arr[i][2]) % 10);
		} while (next_permutation(arr[i], arr[i] + 5));
	}
	int maxx = -1;
	int ans = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (maxx < temp[i])
		{
			maxx = temp[i];
			ans = i;
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}
