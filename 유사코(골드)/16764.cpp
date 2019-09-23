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

int arr[50000][5];
map<int, vector<int> > mp;
int check[50000];

int main() 
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", arr[i] + j);
		}
		sort(arr[i], arr[i] + 5);
	}
	ll cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int t = 0;
		for (int j = 0; j < 5; j++)
		{
			if (t == i)
			{
				mp[arr[i][j]].push_back(i);
				continue;
			}
			for (auto& it : mp[arr[i][j]])
			{
				if (check[it] != i + 1)
				{
					t++;
					cnt++;
					check[it] = i + 1;
				}
			}
			mp[arr[i][j]].push_back(i);
		}
	}
	ll ans = (1LL * N * (N - 1)) / 2 -cnt;
	printf("%lld\n", ans);
	return 0;
}
