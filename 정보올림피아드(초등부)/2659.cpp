#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1000000000;

int arr[4];
map<int, int> mp;

int main()
{
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", arr + i);
	}
	int a = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
	int b = arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[0];
	int c = arr[2] * 1000 + arr[3] * 100 + arr[0] * 10 + arr[1];
	int d = arr[3] * 1000 + arr[0] * 100 + arr[1] * 10 + arr[2];
	int t[4] = { a,b,c,d };
	sort(t, t + 4);
	int idx = 0;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 1; k <= 9; k++)
			{
				for (int r = 1; r <= 9; r++)
				{
					int a = i * 1000 + j * 100 + k * 10 + r;
					int b = j * 1000 + k * 100 + r * 10 + i;
					int c = k * 1000 + r * 100 + i * 10 + j;
					int d = r * 1000 + i * 100 + j * 10 + k;
					int t[4] = { a,b,c,d };
					sort(t, t + 4);
					if (mp.find(t[0]) == mp.end())
					{
						mp[t[0]] = ++idx;
					}
				}
			}
		}
	}
	printf("%d\n", mp[t[0]]);

	return 0;
}
