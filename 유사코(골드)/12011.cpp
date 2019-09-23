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

ll minx[131072];
ll miny[131072];
ll maxx[131072];
ll maxy[131072];
ll minx2[131072];
ll miny2[131072];
ll maxx2[131072];
ll maxy2[131072];

pair<ll, ll> a[50000];

void init1(int node, int start, int end)
{
	if (start == end)
		minx[node] = a[start].first;
	else
	{
		int mid = (start + end) >> 1;
		init1(node * 2, start, mid);
		init1(node * 2 + 1, mid + 1, end);
		minx[node] = min(minx[node * 2], minx[node * 2 + 1]);
	}
}

void init2(int node, int start, int end)
{
	if (start == end)
		miny[node] = a[start].second;
	else
	{
		int mid = (start + end) >> 1;
		init2(node * 2, start, mid);
		init2(node * 2 + 1, mid + 1, end);
		miny[node] = min(miny[node * 2], miny[node * 2 + 1]);
	}
}

void init3(int node, int start, int end)
{
	if (start == end)
		maxx[node] = a[start].first;
	else
	{
		int mid = (start + end) >> 1;
		init3(node * 2, start, mid);
		init3(node * 2 + 1, mid + 1, end);
		maxx[node] = max(maxx[node * 2], maxx[node * 2 + 1]);
	}
}

void init4(int node, int start, int end)
{
	if (start == end)
		maxy[node] = a[start].second;
	else
	{
		int mid = (start + end) >> 1;
		init4(node * 2, start, mid);
		init4(node * 2 + 1, mid + 1, end);
		maxy[node] = max(maxy[node * 2], maxy[node * 2 + 1]);
	}
}


void init5(int node, int start, int end)
{
	if (start == end)
		minx2[node] = a[start].first;
	else
	{
		int mid = (start + end) >> 1;
		init5(node * 2, start, mid);
		init5(node * 2 + 1, mid + 1, end);
		minx2[node] = min(minx2[node * 2], minx2[node * 2 + 1]);
	}
}

void init6(int node, int start, int end)
{
	if (start == end)
		miny2[node] = a[start].second;
	else
	{
		int mid = (start + end) >> 1;
		init6(node * 2, start, mid);
		init6(node * 2 + 1, mid + 1, end);
		miny2[node] = min(miny2[node * 2], miny2[node * 2 + 1]);
	}
}

void init7(int node, int start, int end)
{
	if (start == end)
		maxx2[node] = a[start].first;
	else
	{
		int mid = (start + end) >> 1;
		init7(node * 2, start, mid);
		init7(node * 2 + 1, mid + 1, end);
		maxx2[node] = max(maxx2[node * 2], maxx2[node * 2 + 1]);
	}
}

void init8(int node, int start, int end)
{
	if (start == end)
		maxy2[node] = a[start].second;
	else
	{
		int mid = (start + end) >> 1;
		init8(node * 2, start, mid);
		init8(node * 2 + 1, mid + 1, end);
		maxy2[node] = max(maxy2[node * 2], maxy2[node * 2 + 1]);
	}
}

ll find1(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return LINF;
	if (left <= start && end <= right)
		return minx[node];
	int mid = (start + end) >> 1;
	return min(find1(node * 2, start, mid, left, right), find1(node * 2 + 1, mid + 1, end, left, right));
}

ll find2(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return LINF;
	if (left <= start && end <= right)
		return miny[node];
	int mid = (start + end) >> 1;
	return min(find2(node * 2, start, mid, left, right), find2(node * 2 + 1, mid + 1, end, left, right));
}

ll find3(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return maxx[node];
	int mid = (start + end) >> 1;
	return max(find3(node * 2, start, mid, left, right), find3(node * 2 + 1, mid + 1, end, left, right));
}

ll find4(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return maxy[node];
	int mid = (start + end) >> 1;
	return max(find4(node * 2, start, mid, left, right), find4(node * 2 + 1, mid + 1, end, left, right));
}


ll find5(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return LINF;
	if (left <= start && end <= right)
		return minx2[node];
	int mid = (start + end) >> 1;
	return min(find5(node * 2, start, mid, left, right), find5(node * 2 + 1, mid + 1, end, left, right));
}

ll find6(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return LINF;
	if (left <= start && end <= right)
		return miny2[node];
	int mid = (start + end) >> 1;
	return min(find6(node * 2, start, mid, left, right), find6(node * 2 + 1, mid + 1, end, left, right));
}

ll find7(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return maxx2[node];
	int mid = (start + end) >> 1;
	return max(find7(node * 2, start, mid, left, right), find7(node * 2 + 1, mid + 1, end, left, right));
}

ll find8(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return maxy2[node];
	int mid = (start + end) >> 1;
	return max(find8(node * 2, start, mid, left, right), find8(node * 2 + 1, mid + 1, end, left, right));
}


int main()
{
	int N;
	scanf("%d", &N);
	ll sx = LINF, sy = LINF;
	ll ex = 0, ey = 0;
	for (int i = 0; i < N; i++)
	{
		ll x, y;
		scanf("%lld %lld", &x, &y);
		sx = min(sx, x);
		sy = min(sy, y);
		ex = max(ex, x);
		ey = max(ey, y);
		a[i].first = x;
		a[i].second = y;
	}
	sort(a, a + N);
	init1(1, 0, N - 1);
	init2(1, 0, N - 1);
	init3(1, 0, N - 1);
	init4(1, 0, N - 1);

	long long sum = (ex - sx) * (ey - sy);
	long long mins = LINF;
	for (int i = 0; i < N - 1; i++)
	{
		ll w1 = a[i].first - a[0].first;
		ll w2 = a[N - 1].first - a[i + 1].first;
		ll h1 = find4(1, 0, N - 1, 0, i) - find2(1, 0, N - 1, 0, i);
		ll h2 = find4(1, 0, N - 1, i + 1, N - 1) - find2(1, 0, N - 1, i + 1, N - 1);
		mins = min(mins, w1 * h1 + w2 * h2);
	}
	sort(a, a + N, [&](const pair<int, int>& A, const pair<int, int>& B)
		{
			if (A.second == B.second)
				return A.first < B.first;
			return A.second < B.second;
		});
	init5(1, 0, N - 1);
	init6(1, 0, N - 1);
	init7(1, 0, N - 1);
	init8(1, 0, N - 1);
	for (int i = 0; i < N - 1; i++)
	{
		ll w1 = a[i].second - a[0].second;
		ll w2 = a[N - 1].second - a[i + 1].second;
		ll h1 = find7(1, 0, N - 1, 0, i) - find5(1, 0, N - 1, 0, i);
		ll h2 = find7(1, 0, N - 1, i + 1, N - 1) - find5(1, 0, N - 1, i + 1, N - 1);
		mins = min(mins, w1 * h1 + w2 * h2);
	}
	printf("%lld\n", sum - mins);
	return 0;
}
