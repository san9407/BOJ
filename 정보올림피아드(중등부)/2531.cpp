#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#include <stack>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const long long LINF = 1e18 + 1;
const int MOD = 998244353;
typedef long long ll;
typedef pair<int, int> P;

int arr[60000];
int cnt[3001];

int main()
{
	int N, d, k, c;
	scanf("%d %d %d %d", &N, &d, &k, &c);
	for (int i = 0; i < N; i++)
	{
		int x;
		scanf("%d", &x);
		arr[i] = arr[i + N] = x;
	}
	int ans = 0;
	int curr = 0;
	for (int i = 0; i < k; i++)
	{
		if (cnt[arr[i]] == 0)
			curr++;
		cnt[arr[i]]++;
	}
	if (cnt[c] == 0)
		ans = curr + 1;
	else
		ans = curr;
	int l = 0, r = k;
	while (r < 2 * N)
	{
		cnt[arr[l]]--;
		if (cnt[arr[l++]] == 0)
			curr--;
		if (cnt[arr[r]] == 0)
			curr++;
		cnt[arr[r++]]++;
		if (cnt[c] == 0)
			ans = max(ans, curr + 1);
		else
			ans = max(ans, curr);
	}
	printf("%d\n", ans);
	return 0;
}
