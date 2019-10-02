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
#include <tuple>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000001;
const long long LINF = 1e18 + 1;
typedef long long ll;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int cntA[5],cntB[5];
		memset(cntA, 0, sizeof(cntA));
		memset(cntB, 0, sizeof(cntB));
		int A;
		scanf("%d", &A);
		for (int i = 0; i < A; i++)
		{
			int num;
			scanf("%d", &num);
			cntA[num]++;
		}
		int B;
		scanf("%d", &B);
		for (int i = 0; i < B; i++)
		{
			int num;
			scanf("%d", &num);
			cntB[num]++;
		}
		if (cntA[4] > cntB[4])
			puts("A");
		else if (cntA[4] < cntB[4])
			puts("B");
		else
		{
			if (cntA[3] > cntB[3])
				puts("A");
			else if (cntA[3] < cntB[3])
				puts("B");
			else
			{
				if (cntA[2] > cntB[2])
					puts("A");
				else if (cntA[2] < cntB[2])
					puts("B");
				else
				{
					if (cntA[1] > cntB[1])
						puts("A");
					else if (cntA[1] < cntB[1])
						puts("B");
					else
						puts("D");
				}
			}
		}
	}
	return 0;
}
