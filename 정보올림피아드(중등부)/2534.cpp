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
const int MOD = 1000000007;
typedef long long ll;
//typedef pair<int, int> P;

vector<int> adj[300000];
vector<int> adj2[300000];
int in[300000];
int in2[300000];
ll mul[300001];

int main()
{
	int N, K, P;
	scanf("%d %d %d", &N, &K, &P);
	mul[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		mul[i] = (mul[i - 1] * N) % MOD;
	}
	for (int i = 0; i < P; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a != b)
		{
			adj[a].push_back(b);
			in[b]++;
			adj2[b].push_back(a);
			in2[a]++;
		}
	}
	priority_queue<int, vector<int>, greater<int> > pq;
	int k = K-1;
	for (int i = 0; i < K; i++)
	{
		if (in[i] == 0)
			pq.push(i);
	}
	ll minn = 0;
	while (!pq.empty())
	{
		int curr = pq.top();
		pq.pop();
		minn += (k * mul[curr]) % MOD;
		k--;
		minn %= MOD;
		for (int i = 0; i < adj[curr].size(); i++)
		{
			int next = adj[curr][i];
			in[next]--;
			if (in[next] == 0)
				pq.push(next);
		}
	}

	priority_queue<int, vector<int>, greater<int> > pq2;
	int k2 = N - K;
	for (int i = 0; i <K; i++)
	{
		if (in2[i] == 0)
		{
			pq2.push(i);
		}
	}
	ll maxx = 0;
	while (!pq2.empty())
	{
		int curr = pq2.top();
		pq2.pop();
		maxx += (k2 * mul[curr]) % MOD;
		k2++;
		maxx %= MOD;
		for (int i = 0; i < adj2[curr].size(); i++)
		{
			int next = adj2[curr][i];
			in2[next]--;
			if (in2[next] == 0)
				pq2.push(next);
		}
	}
	ll ans = (maxx - minn + MOD) % MOD;
	printf("%lld\n", ans);
	return 0;
}
