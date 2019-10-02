#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

int main()
{
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		int num;
		scanf("%d", &num);
		arr[i] = num;
	}
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += pow(arr[i], 2);
	}
	printf("%d\n", sum % 10);
	return 0;
}
