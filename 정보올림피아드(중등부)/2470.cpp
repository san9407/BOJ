#include<cstdio>
#include<algorithm>
using namespace std;

int arr[100001];

int main() 
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i<N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N);
	int s = 0, e = N - 1;
	int minn = 2000000000;
	int i, j;

	while (s < e) 
	{
		if (abs(arr[s] + arr[e]) < minn) 
		{
			i = s;
			j = e;
			minn = abs(arr[s] + arr[e]);
		}
		if (arr[s] + arr[e] < 0) 
			s++;
		else if (arr[s] + arr[e] > 0) 
			e--;
		else break;
	}
	printf("%d %d\n", arr[i], arr[j]);
	return 0;
}
