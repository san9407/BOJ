#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;

long long fibo[41];
bool check[41];

int main()
{
	fibo[0] = fibo[1] = 1;
	for (int i = 2; i <= 40; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	int N;
	scanf("%d", &N);
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int num;
		scanf("%d", &num);
		check[num] = true;
	}
	long long ans = 1;
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (check[i])
		{
			ans *= fibo[cnt];
			cnt = 0;
		}
		else
			cnt++;
	}
	ans *= fibo[cnt];
	printf("%lld\n", ans);
	return 0;
}
