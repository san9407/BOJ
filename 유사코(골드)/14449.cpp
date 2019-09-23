#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000001;
const long long LINF = 1e18 + 1;
typedef long long ll;

int arr[100000];
int brr[100000];
int tree[262144];
int tree2[262144];
int L[100000];
int R[100000];

void update(int node, int start, int end, int index, int val)
{
	if (index<start || index>end)
		return;
	tree[node] += val;
	if (start != end)
	{
		int mid = (start + end) >> 1;
		update(node * 2, start, mid, index, val);
		update(node * 2 + 1, mid + 1, end, index, val);
	}
}

int find(int node, int start, int end, int left, int right)
{
	if (right<start || left>end)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) >> 1;
	return find(node * 2, start, mid, left, right) + find(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> a;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		brr[i] = arr[i];
	}
	sort(brr, brr + N);
	map<int, int> mp;
	for (int i = 0; i < N; i++)
		mp[brr[i]] = i;
	for (int i = 0; i < N; i++)
		arr[i] = mp[arr[i]];
	for (int i = 0; i < N; i++)
	{
		L[i] = find(1, 0, 100000-1, arr[i],100000-1);
		update(1, 0, 100000-1, arr[i], 1);
	}
	memset(tree, 0, sizeof(tree));
	for (int i = N-1; i >= 0; i--)
	{
		R[i] = find(1, 0, 100000-1, arr[i],100000-1);
		update(1, 0, 100000-1, arr[i], 1);
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (L[i] > 2 * R[i] || 2 * L[i] < R[i])
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
