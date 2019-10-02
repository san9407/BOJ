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

int main()
{
	char str[51];
	scanf("%s", str);
	int ans = 10;
	int len = strlen(str);
	for (int i = 1; i < len; i++)
	{
		if (str[i] == str[i - 1])
			ans += 5;
		else
			ans += 10;
	}
	printf("%d\n", ans);
	return 0;
}
