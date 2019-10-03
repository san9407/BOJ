#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int MAX = 100000;
const int MOD = 100000007;

int main()
{
	char str[31];
	scanf("%s", str);
	int len = strlen(str);
	char ans[31];
	int temp = 1, sum = 0, cnt = 0;
	bool check = false;
	for (int i = 0; i < len; i++)
	{
		if (cnt < 0)
		{
			puts("0");
			return 0;
		}
		if (str[i] == '(')
		{
			check = true;
			ans[cnt++] = str[i];
			temp *= 2;
		}
		else if (str[i] == '[')
		{
			check = true;
			ans[cnt++] = str[i];
			temp *= 3;
		}
		else if (str[i] == ')')
		{
			cnt--;
			if (ans[cnt] != '(')
			{
				puts("0");
				return 0;
			}
			if (check)
			{
				check = false;
				sum += temp;
			}
			temp /= 2;
		}
		else if (str[i] == ']')
		{
			cnt--;
			if (ans[cnt] != '[')
			{
				puts("0");
				return 0;
			}
			if (check)
			{
				check = false;
				sum += temp;
			}
			temp /= 3;
		}
	}
	if (cnt == 0)
	{
		printf("%d\n", sum);
	}
	else
		puts("0");
	return 0;
}
