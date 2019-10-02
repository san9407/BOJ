#include<stdio.h>
#pragma warning(disable:4996)

int size[101][101];

int main()
{
	int T;
	scanf("%d", &T);
	int i,j,k;
	for (i = 0; i < T; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		for (j = a; j < a + 10; j++)
		{
			for (k = b; k < b + 10; k++)
			{
				size[j][k] = 1;
			}
		}
		
	}
	int sum = 0;
	for (j = 0; j < 101; j++)
	{
		for (k = 0; k < 101; k++)
		{
			sum += size[j][k];
		}
	}
	printf("%d\n", sum);

}
