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

char str[5][16];

int main()
{
	int maxx = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%s", str[i]);
		int len = strlen(str[i]);
		maxx = max(maxx, len);
	}
	for (int i = 0; i < maxx; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (str[j][i] == 0)
				continue;
			printf("%c", str[j][i]);
		}
	}
	puts("");
	return 0;
}
