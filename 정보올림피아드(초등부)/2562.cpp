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

pair<int, int> arr[9];

int main()
{
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i].first);
		arr[i].second = i + 1;
	}
	sort(arr, arr + 9, greater<pair<int, int>>());
	printf("%d\n%d\n",arr[0].first ,arr[0].second);
	return 0;
}
