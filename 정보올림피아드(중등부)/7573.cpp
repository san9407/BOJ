#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

pair<int, int> arr[100];
vector<pair<int, int> > temp;
vector<int> t;
int main()
{
	int N, I, M;
	scanf("%d %d %d", &N, &I, &M);
	for (int i = 0; i < M; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		arr[i] = { x,y };
	}
	for (int i = 0; i < M; i++)
	{
		temp.push_back({ arr[i].first,arr[i].second });
		for (int j = i+1; j < M; j++)
		{
			temp.push_back({ arr[i].first,arr[j].second });
			temp.push_back({ arr[j].first,arr[i].second });
		}
	}
	int ans=0;
	int ansX, ansY,R,C;
	for (int i = 0; i < temp.size(); i++)
	{
		int cx = temp[i].first;
		int cy = temp[i].second;
		for (int r = 1; r < I/2; r++)
		{
			int cnt = 0;
			int c = I/2 - r;
			for (int j = 0; j < M; j++)
			{
				if (cx <= arr[j].first&&arr[j].first <= cx + r && cy <= arr[j].second&&arr[j].second <= cy+c)
				{
					cnt++;
				}
			}
			if (ans < cnt)
			{
				ans = cnt;
				ansX = cx;
				ansY = cy;
				R = r;
				C = c;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
