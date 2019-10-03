#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <set>
#include <stack>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const long long LINF = 1e18 + 1;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> P;

int arr[100];

int main()
{
	int N;
	scanf("%d", &N);
	int sum = 0;
	int c=0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		if (arr[i] == 1)
		{
			sum += ++c;
		}
		else
			c = 0;
	}
	printf("%d\n", sum);
	return 0;
}
