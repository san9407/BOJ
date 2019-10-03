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

int main() 
{
	int maxx = 0;
	int curr = 0;
	for (int i = 0; i < 10; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		curr -= a;
		curr += b;
		maxx = max(maxx, curr);
	}
	printf("%d\n", maxx);
	return 0;
}
