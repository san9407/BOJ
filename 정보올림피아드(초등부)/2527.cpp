#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1000000000;

int main()
{
	for (int i = 0; i < 4; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int tx1, ty1, tx2, ty2;
		scanf("%d %d %d %d", &tx1, &ty1, &tx2, &ty2);
		if ((x2 == tx1 && y2 == ty1) || (x1 == tx2 && y2 == ty1) || (x2 == tx1 && y1 == ty2) || (x1 == tx2 && y1 == ty2))
		{
			puts("c");
		}
		else if ((x2 == tx1 && y2 != ty1) || (x1 == tx2 && y2 != ty1) || (x2 != tx1 && y1 == ty2) || (x1 != tx2 && y1 == ty2)) 
		{
			puts("b");
		}
		else if (x2 < tx1 || tx2 < x1 || y2 < ty1 || ty2 < y1)
		{
			puts("d");
		}
		else 
		{
			puts("a");
		}
	}
	return 0;
}
