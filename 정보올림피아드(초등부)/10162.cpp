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

int arr[3] = { 300,60,10 };
int cnt[3];

int main()
{
	int N;
	scanf("%d", &N);
	int idx = 0;
	while (N > 0&&idx<3)
	{
		if (N >= arr[idx])
		{
			cnt[idx]=N / arr[idx];
			N -= cnt[idx] * arr[idx];
			idx++;
		}
		else
		{
			idx++;
		}
	}
	if (N == 0)
		printf("%d %d %d\n", cnt[0], cnt[1], cnt[2]);
	else
		puts("-1");
	return 0;
}
