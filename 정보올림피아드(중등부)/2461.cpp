#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const long long LINF = 1e18 + 1;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> P;

P arr[1000 * 1000];
int cnt[1000];

int main() 
{
	int N, M;
	scanf("%d %d", &N, &M);
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int x;
			scanf("%d", &x);
			arr[idx++] = P(x, i);
		}
	}
	sort(arr, arr + idx);
	int l = 0, r = 0;
	int minn = INF;
	int student = 0;
	while (r < N * M)
	{
		if (cnt[arr[r].second] == 0)
			student++;
		cnt[arr[r++].second]++;
		while (student == N)
		{
			minn = min(minn, arr[r-1].first - arr[l].first);
			cnt[arr[l].second]--;
			if (cnt[arr[l].second] == 0)
				student--;
			l++;
		}
	}
	printf("%d\n", minn);
	return 0;
}
