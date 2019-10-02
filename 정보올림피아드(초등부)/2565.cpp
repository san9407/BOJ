#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 100000;
const long long LINF = 1e18;

pair<int, int> a[100];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &a[i].first, &a[i].second);
	sort(a, a + N);
	vector<int> ans;
	for (int i = 0; i < N; i++)
	{
		if (ans.empty())
			ans.push_back(a[i].second);
		if (ans.back() < a[i].second)
			ans.push_back(a[i].second);
		else
		{
			auto t = lower_bound(ans.begin(), ans.end(), a[i].second) - ans.begin();
			ans[t] = a[i].second;
		}
	}
	printf("%d\n", N - ans.size());
	return 0;
}
