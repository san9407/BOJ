#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning(disable:4996)

int h[100], w[100];

int main()
{
	int width, height;
	scanf("%d %d", &width, &height);
	int N;
	scanf("%d", &N);
	int hcnt = 0;
	int wcnt = 0;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a,&b);
		if (a == 0)
			h[hcnt++] = b;
		else
			w[wcnt++] = b;
	}
	h[hcnt++] = height;
	w[wcnt++] = width;
	sort(h, h + hcnt);
	sort(w, w + wcnt);
	int maxx = 0;
	int last = 0, last2 = 0;
	for (int i = 0; i < hcnt; i++)
	{
		if (i > 0)
			last = h[i - 1];
		last2 = 0;
		for (int j = 0; j < wcnt; j++)
		{
			maxx = max(maxx, (h[i] - last) * (w[j] - last2));
			last2 = w[j];
		}
	}
	printf("%d\n", maxx);
	return 0;
}
