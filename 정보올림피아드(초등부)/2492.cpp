#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

pair<int, int> arr[100];
vector<pair<int, int> > temp;

int main()
{
	int N, M, T, K;
	scanf("%d %d %d %d", &N, &M, &T, &K);
	for (int i = 0; i < T; i++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		arr[i] = { A,B };
	}

	for (int i = 0; i < T; i++)
	{
		temp.push_back({ arr[i].first, arr[i].second });
		for (int j = i + 1; j < T; j++)
		{
			temp.push_back({ arr[i].first, arr[j].second });
			temp.push_back({ arr[j].first, arr[i].second });
		}
	}
	int ans = 0;
	int ansX, ansY;
	for (int i = 0; i < temp.size(); i++)
	{
		int cx = temp[i].first;
		int cy = temp[i].second;
		int cnt = 0;
		for (int j = 0; j < T; j++)
		{
			if (cx <= arr[j].first&&arr[j].first <= cx + K && cy - K <= arr[j].second&&arr[j].second <= cy)
			{
				cnt++;
			}
		}
		if (ans < cnt)
		{
			ans = cnt;
			ansX = cx;
			ansY = cy;
		}
	}
	if (ansX + K > N)
		ansX = N - K;
	if (ansY - K < 0)
		ansY = K;
	printf("%d %d\n%d\n", ansX, ansY, ans);
	return 0;
}
