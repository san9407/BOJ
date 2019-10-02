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
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	int l = 0, r = N - 1;
	int minn = 2 * INF;
	int sum = 0;
	int ansl, ansr;
	while (l < r)
	{
		sum = arr[l] + arr[r];
		if (minn > abs(sum))
		{
			minn = abs(sum);
			ansl = l;
			ansr = r;
		}
		if (sum < 0)
			l++;
		else if (sum > 0)
			r--;
		else
			break;
	}
	printf("%d %d\n", arr[ansl], arr[ansr]);
	return 0;
}
