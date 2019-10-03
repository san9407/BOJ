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

pair<int, int> p[100000];
int fr[500001], ck[500001];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p + N);
	vector<int> vt;
	for (int i = 0; i < N; i++)
	{
		if (vt.empty())
		{
			vt.push_back(p[i].second);
		}
		else
		{
			if (vt.back() < p[i].second)
			{
				vt.push_back(p[i].second);
				fr[p[i].second] = vt[vt.size() - 2];
			}
			else
			{
				auto t = lower_bound(vt.begin(), vt.end(), p[i].second) - vt.begin();
				vt[t] = p[i].second;
				fr[vt[t]] = t ? vt[t - 1] : 0;
			}
		}
	}
	printf("%d\n", N - vt.size());
	for (int i = vt[vt.size()-1]; i; i = fr[i])
		ck[i] = 1;
	for (int i = 0; i < N; i++)
		if (!ck[p[i].second])
			printf("%d\n", p[i].first);
	return 0;
}
