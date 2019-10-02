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

int border[1400];

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);
	int len = M * 2 - 1;
	fill(border, border + len, 1);
	for (int i = 0; i < N; i++)
	{
		int zero, one, two;
		scanf("%d %d %d", &zero, &one, &two);
		for (int i = zero; i < zero + one; i++)
			border[i]++;
		for (int i = zero + one; i < len; i++)
			border[i] += 2;
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (j == 0)
				printf("%d ", border[M - i - 1]);
			else
				printf("%d ", border[M + j - 1]);
		}
		puts("");
	}
	return 0;
}
