#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int K, M, N;
int arr[1000];
int brr[1000];

int a[1000000];
int b[1000000];


int main()
{
	scanf("%d", &K);
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &brr[i]);
	}

	for (int i = 0; i < M; i++)
	{
		int sum = arr[i];
		a[sum]++;
		int j = M-1;
		int k = (i + 1) % M;
		while (j--)
		{
			sum += arr[k];
			a[sum]++;
			k++;
			k %= M;
		}
	}
	int z = 0;
	for (int i = 0; i < M; i++)
	{
		z += arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		int sum = brr[i];
		b[sum]++;
		int j = N-1;
		int k = (i + 1) % N;
		while (j--)
		{
			sum += brr[k];
			b[sum]++;
			k++;
			k %= N;
		}
	}
	int w = 0;
	for (int i = 0; i < N; i++)
	{
		w += brr[i];
	}
	a[z] -= M - 1;
	b[w] -= N - 1;
	long long ans = 0;
	a[0] = b[0] = 1;
	for (int i = 0; i <= K; i++)
	{
		ans += a[i] * b[K - i];
	}
	printf("%lld\n", ans);
	return 0;
}
