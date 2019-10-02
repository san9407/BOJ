#include <cstdio>
using namespace std;
#pragma warning(disable:4996)

int arr[100];
int ans[100][50];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		arr[i + N] = arr[i];
	}
	int Q;
	scanf("%d", &Q);
	int dap = 0;
	for (int i = 0; i < Q; i++)
	{
		int temp[51];
		int rev[51];
		for (int i = 0; i < N; i++)
		{
			scanf("%d", temp + i);
			if (temp[i] == 1)
				rev[N-1-i] = 3;
			else if (temp[i] == 2)
				rev[N-1-i] = 4;
			else if (temp[i] == 3)
				rev[N-1-i] = 1;
			else if (temp[i] == 4)
				rev[N-1-i] = 2;
		}
		for (int j = 0; j < N; j++)
		{
			int cnt = 0;
			for (int k = 0; k < N; k++)
			{
				if (arr[j + k] != temp[k])
				{
					cnt = 0;
					break;
				}
				else
					cnt++;
			}
			if (cnt != N)
			{
				for (int k = 0; k < N; k++)
				{
					if (arr[j + k] != rev[k])
					{
						cnt = 0;
						break;
					}
					else
						cnt++;
				}
			}
			if (cnt == N)
			{
				for (int k = 0; k < N; k++)
				{
					ans[dap][k] = temp[k];
				}
				dap++;
			}
		}
	}
	printf("%d\n", dap);
	for (int i = 0; i < dap; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", ans[i][j]);
		}
		puts("");
	}
	return 0;
}
