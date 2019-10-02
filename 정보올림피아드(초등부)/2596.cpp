#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;

char s[8][7] = { "000000","001111","010011","011100",
				"100110","101001","110101","111010" };

int main()
{
	int N;
	scanf("%d", &N);
	char str[61];
	scanf("%s", str);
	char ans[11];
	for (int i = 0; i < 6*N; i+=6)
	{
		int minn = INF;
		int idx = 0;
		for (int j = 0; j < 8; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 6; k++)
			{
				if (str[i + k] != s[j][k])
				{
					cnt++;
				}
			}
			if (minn > cnt)
			{
				minn = cnt;
				idx = j;
			}
		}
		if (minn <= 1)
		{
			ans[i / 6] = 'A' + idx;
		}
		else
		{
			printf("%d\n", i / 6 + 1);
			return 0;
		}
	}
	ans[N] = '\0';
	printf("%s\n", ans);
	return 0;
}
