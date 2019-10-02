#include <stdio.h>
#pragma warning(disable:4996)

int hint[100];
int st[100];
int bal[100];
int check[1000];

int main()
{
	int N;
	scanf("%d", &N);
	int i, j;
	for (i = 0; i < N; i++)
	{
		int num, strike, ball;
		scanf("%d %d %d", &num, &strike, &ball);
		hint[i] = num;
		st[i] = strike;
		bal[i] = ball;
	}
	
	for (i = 123; i <= 987; i++)
	{
		
		int hund=i/100;
		int ten=(i/10)%10;
		int one=i%10;
		if (hund == ten || hund == one || ten == one || ten == 0 || one ==0)
		{
			continue;
		}
		for (j = 0; j < N; j++)
		{
			int s = 0;
			int b = 0;
			int hund2=hint[j]/100;
			int ten2=(hint[j]/10)%10;
			int one2=hint[j]%10;
			if (hund == hund2)
			{
				s++;
			}
			else if (hund == ten2)
			{
				b++;
			}
			else if (hund == one2)
			{
				b++;
			}
			if (ten == hund2)
			{
				b++;
			}
			else if (ten == ten2)
			{
				s++;
			}
			else if (ten == one2)
			{
				b++;
			}
			if (one == hund2)
			{
				b++;
			}
			else if (one == ten2)
			{
				b++;
			}
			else if (one == one2)
			{
				s++;
			}


			if (s != st[j] || b != bal[j])
			{
				break;
			}
			if (j == N - 1)
			{
				check[i] = 1;
			}
		}
		
	}
	int sum = 0;
	for (i = 123; i <= 987; i++)
	{
		sum += check[i];
	}
	printf("%d\n", sum);
	return 0;
}
