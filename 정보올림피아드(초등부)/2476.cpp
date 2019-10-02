#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int arr[1000][3];

int main()
{
	int N;
	scanf("%d", &N);
	int maxx = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &arr[i][j]);
		}
		sort(arr[i], arr[i] + 3);
		if (arr[i][0]==arr[i][2])
		{
			maxx = max(maxx, 10000 + arr[i][0] * 1000);
		}
		else if (arr[i][0] == arr[i][1])
		{
			maxx = max(maxx, 1000 + arr[i][0] * 100);
		}
		else if (arr[i][1] == arr[i][2])
		{
			maxx = max(maxx, 1000 + arr[i][1] * 100);
		}
		else
		{
			maxx = max(maxx, arr[i][2] * 100);
		}
	}
	printf("%d\n", maxx);
	return 0;
}
