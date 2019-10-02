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

double arr[100000];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%lf", arr + i);
	}
	sort(arr, arr + N);
	double sum1 = 0, sum2 = 0;
	for (int i = K; i < N - K; i++)
		sum1 += arr[i];
	for (int i = 0; i < N; i++)
	{
		if (i < K)
			sum2 += arr[K];
		else if (i >= N - K)
			sum2 += arr[N - K - 1];
		else
			sum2 += arr[i];
	}
	double ans1 = sum1 / (N - 2 * K) + 1e-9;
	double ans2 = sum2 / N + 1e-9;
	printf("%.2lf\n%.2lf\n", ans1,ans2);
	return 0;
}
