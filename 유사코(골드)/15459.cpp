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

int flavor[100000];
int spice[100000];
int tree[262144];

void init(int node, int start, int end)
{
	if (start == end)
		tree[node] = spice[start];
	else
	{
		int mid = (start + end) >> 1;
		init(node * 2, start, mid);
		init(node * 2 + 1, mid + 1, end);
		tree[node]=max(tree[node*2],tree[node*2+1]);
	}
}

int find(int node, int start, int end, int left,int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) >> 1;
	return max(find(node * 2, start, mid, left, right), find(node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
	int N;
	ll M;
	scanf("%d %lld", &N, &M);
	for (int i = 0; i < N; i++)
	{
		int f, s;
		scanf("%d %d", &f, &s);
		flavor[i] = f;
		spice[i] = s;
	}
	init(1, 0, N - 1);
	ll sum = 0;
	int l = 0, r = 0;
	int minn = INF;
	while (r < N)
	{
		if (sum < M)
		{
			sum += flavor[r++];
		}
		else
		{
			sum -= flavor[l++];
			minn = min(minn, find(1, 0, N - 1, l, r));
		}
	}
	printf("%d\n", minn);
	return 0;
}
