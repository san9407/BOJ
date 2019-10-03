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
const int MOD = 1000000000;
typedef long long ll;
typedef pair<int, int> P;

int s[100][1000];
int len[100];
int fail[1000][1000];
bool check[1000];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	int i, j, k, t;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &len[i]);
		for (j = 0; j < len[i]; j++)
		{
			int x;
			scanf("%d", &x);
			s[i][j] = x;
		}
	}
	for (i = 0; i <= len[0] - K; i++)
	{
		for (j = 1, k = 0; j < K; j++)
		{
			while (k && s[0][i + j] != s[0][i + k])
				k = fail[i][k - 1];
			if (s[0][i + j] == s[0][i + k])
				fail[i][j] = ++k;
		}
	}
	for (i = 1; i < N; i++)
	{
		for (j = 0; j <= len[0] - K; j++)
		{
			bool flag = false;
			if (check[j])
				continue;
			for (k = 0, t = 0; k < len[i]; k++)
			{
				while (t && s[i][k] != s[0][j+t])
					t = fail[j][t - 1];
				if (s[i][k] == s[0][j+t])
				{
					if (t == K - 1)
					{
						flag = true;
						break;
					}
					else
						t++;
				}
			}
			if (!flag)
			{
				for (k = len[i]-1, t = 0; k >=0; k--)
				{
					while (t && s[i][k] != s[0][j+t])
						t = fail[j][t - 1];
					if (s[i][k] == s[0][j+t])
					{
						if (t == K-1)
						{
							flag = true;
							break;
						}
						else
							t++;
					}
				}
			}
			if (!flag)
				check[j] = true;
		}
	}
	for (i = 0; i <= len[0]-K; i++)
	{
		if (!check[i])
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
