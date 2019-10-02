#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1000000000;

struct Point
{
	int left, right;
	int dir;
};

Point p[3000];

int main()
{
	int N, L;
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
	{
		int l, d;
		scanf("%d %d", &l, &d);
		if (d == 0)
		{
			p[i].left = 0;
			p[i].right = l;
			p[i].dir = 0;
		}
		else
		{
			p[i].left = L - l;
			p[i].right = L;
			p[i].dir = 1;
		}
	}
	int h = 0;
	int t = 0;
	while (h != N-1)
	{
		while (h!=N-1&&(p[h].left <= p[h+1].right&&p[h+1].right <= p[h].right)
			|| (p[h + 1].left <= p[h].right&&p[h].right <= p[h + 1].right))
		{
			h++;
		}
		if (h == N - 1)
			break;
		for (int i = h; i < N; i++)
		{
			if (p[i].dir == 0)
			{
				p[i].left++;
				p[i].right++;
				if (p[i].right == L)
				{
					p[i].dir ^= 1;
				}
			}
			else
			{
				p[i].left--;
				p[i].right--;
				if (p[i].left == 0)
					p[i].dir ^= 1;
			}
		}
		t++;
	}
	printf("%d\n", t);
	return 0;
}
