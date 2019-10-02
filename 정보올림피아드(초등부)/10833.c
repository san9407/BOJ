#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int)*N);
	int i;
	for (i = 0; i < N; i++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		arr[i] = B % A;
	}
	int sum = 0;
	for (i = 0; i < N; i++)
	{
		sum += arr[i];
	}
	printf("%d\n", sum);
	free(arr);
	return 0;
}
