#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

struct Node
{
	int width, height;
};

bool cmp(Node& A, Node& B)
{
	if (A.width == B.width)
		return A.height > B.height;
	return A.width > B.width;
}

Node arr[100];
int dp[100];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int w, h;
		scanf("%d %d", &w, &h);
		if (w < h)
			swap(w, h);
		arr[i].width = w;
		arr[i].height=h;
	}
	sort(arr, arr + N, cmp);
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i].width <= arr[j].width && arr[i].height <= arr[j].height)
				dp[i] = max(dp[i], dp[j]);
		}
		dp[i]++;
		ans = max(ans, dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
