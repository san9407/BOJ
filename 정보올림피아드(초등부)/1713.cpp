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
const int INF = 1000000000;

int time[101];
map<int, int> mp;

int main()
{
	int N;
	scanf("%d", &N);
	int M;
	scanf("%d", &M);
	int curr = 0;
	for (int i = 0; i < M; i++)
	{
		int x;
		scanf("%d", &x);
		map<int, int>::iterator it;
		it = mp.find(x);
		if (it != mp.end())
		{
			int cnt = it->second;
			mp.erase(it);
			mp[x] = ++cnt;
		}
		else
		{
			if (curr < N)
			{
				mp[x] = 1;
				curr++;
			}
			else
			{
				int minn = INF;
				int tmp = INF;
				int idx = -1;
				for (auto k : mp)
				{
					if (k.second < minn)
					{
						minn = k.second;
						tmp = time[k.first];
						idx = k.first;
					}
					else if (k.second == minn)
					{
						if (time[k.first] < tmp)
						{
							tmp = time[k.first];
							idx = k.first;
						}
					}
				}
				mp.erase(mp.find(idx));
				mp[x] = 1;
			}
			time[x] = i;
		}
	}
	for (auto k : mp)
	{
		printf("%d ", k.first);
	}
	puts("");
	return 0;
}
