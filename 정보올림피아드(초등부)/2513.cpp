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

pair<int, int> arr[30001];

int main()
{
	int N, K, S;
	scanf("%d %d %d", &N, &K, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	arr[N] = { S,0 };
	sort(arr, arr + N + 1);
	int school;
	for (int i = 0; i <= N; i++)
	{
		if (arr[i].first == S)
		{
			school = i;
			break;
		}
	}
	int ans = 0;
	for (int i = 0; i < school;)
	{
		int sum = 0;
		int j = 0;
		for (j = i; j < school; j++)
		{
			sum += arr[j].second;
			if (sum > K)
			{
				arr[j].second = sum - K;
				break;
			}
		}
		ans += (S - arr[i].first) * 2;
		i = j;
	}
	for (int i = N; i > school;)
	{
		int sum = 0;
		int j = 0;
		for (j = i; j > school; j--)
		{
			sum += arr[j].second;
			if (sum > K)
			{
				arr[j].second = sum - K;
				break;
			}
		}
		ans += (arr[i].first - S) * 2;
		i = j;
	}
	printf("%d\n", ans);
	return 0;
}
