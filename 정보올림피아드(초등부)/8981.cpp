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

int arr[30];
int ans[30];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	int count = 0, from = 0, value;
	while (count < N)
	{
		while (ans[from] != 0)
		{
			from = (from + 1) % N;
		}
		ans[from] = arr[count++];
		from = (ans[from] + from) % N;
	}
	printf("%d\n", N);
	for (int i = 0; i < N; i++)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
