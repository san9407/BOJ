#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[100000];

int main()
{
	int N;
	scanf("%d", &N);
	int curr, prev;
	scanf("%d", &prev);
	int maxInc = 0, maxDec = 0, cntInc = 1, cntDec = 1;
	for (int i = 1; i < N; i++)
	{
		scanf("%d", &curr);
		if (prev == curr)
		{
			cntInc++;
			cntDec++;
		}
		else if (prev < curr)
		{
			cntInc++;
			maxDec = max(maxDec, cntDec);
			cntDec = 1;
		}
		else
		{
			cntDec++;
			maxInc = max(maxInc, cntInc);
			cntInc = 1;
		}
		prev = curr;
	}
	maxInc = max(maxInc, cntInc);
	maxDec = max(maxDec, cntDec);
	printf("%d\n", max(maxInc, maxDec));
	return 0;
}
