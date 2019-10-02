#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int arr[7] = { 0,0,0,0,0,0,0 };
	int i;
	int sum = 0;
	for (i = 0; i < 7; i++)
	{
		int num;
		scanf("%d", &num);
		if (num % 2 == 1)
		{
			arr[i] = num;
			sum += num;
		}
	}
	
	int check = 0;
	int min = 100;
	for (i = 0; i < 7; i++)
	{
		if (min > arr[i] && arr[i] != 0)
		{
			check = 1;
			min = arr[i];
		}
	}
	if (check)
	{
		printf("%d\n%d\n",sum ,min);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
