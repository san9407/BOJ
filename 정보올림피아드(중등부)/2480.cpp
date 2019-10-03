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

int cnt[7];

int main() 
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int maxx = max({ a,b,c });
	cnt[a]++;
	cnt[b]++;
	cnt[c]++;
	for (int i = 1; i <= 6; i++)
	{
		if (cnt[i] == 3)
		{
			printf("%d\n", 10000 + i * 1000);
			return 0;
		}
		else if (cnt[i] == 2)
		{
			printf("%d\n", 1000 + i * 100);
			return 0;
		}
	}
	printf("%d\n", maxx * 100);
	return 0;
}
