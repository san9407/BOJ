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
#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const long long LINF = 1e18 + 1;
const int MOD = 1000000007;
typedef long long ll;

int N, M, T, K;
pair<int, int> p[100];
vector<pair<int, int> > temp;
int ans;
int ansX, ansY;

void go(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < T; i++)
	{
		if (x <= p[i].first && p[i].first <= x + K && y <= p[i].second && p[i].second <= y + K)
			cnt++;
	}
	if (ans < cnt)
	{
		ans = cnt;
		ansX = (x + y) / 2;
		ansY = (y - x) / 2;
	}
}

int main()
{
	scanf("%d %d %d %d", &N, &M, &T, &K);
	for (int i = 0; i < T; i++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		p[i] = { A - B,A + B };
	}

	for (int i = 0; i < T; i++)
	{
		temp.push_back({ p[i].first, p[i].second });
		for (int j = i + 1; j < T; j++)
		{
			temp.push_back({ p[i].first, p[j].second });
			temp.push_back({ p[j].first, p[i].second });
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		int x = temp[i].first;
		int y = temp[i].second;
		if ((x + y) & 2)
		{
			go(x + 1, y);
			go(x - 1, y);
            go(x,y-1);
            go(x,y+1);
		}
		go(x, y);
	}
	ansX += K / 2;
	ansX = max(0, ansX);
	ansX = min(N, ansX);
	ansY = max(0, ansY);
	ansY = min(M, ansY);
	printf("%d %d\n%d\n", ansX, ansY, ans);
	return 0;
}
