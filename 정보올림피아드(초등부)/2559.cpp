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
#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;

int arr[100000];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	int sum = 0;
	for (int i = 0; i < K; i++)
	{
		scanf("%d", arr + i);
		sum += arr[i];
	}
	int maxx = sum;
	for (int i = K; i < N; i++)
	{
		scanf("%d", arr + i);
		sum += arr[i];
		sum -= arr[i - K];
		maxx = max(maxx, sum);
	}
	printf("%d\n", maxx);
	return 0;
}
