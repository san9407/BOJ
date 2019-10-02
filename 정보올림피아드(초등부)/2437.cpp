#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i<N; ++i)
		scanf("%d", &arr[i]);

	sort(arr, arr + N);

	int sum = 0;
	for (int i = 0; i<N; i++) 
	{
		if (sum + 1<arr[i])
			break;
		sum += arr[i];
	}
	printf("%d\n",sum+1);
	return 0;
}
