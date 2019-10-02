#include<stdio.h>
#pragma warning(disable:4996)

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int c;
	scanf("%d", &c);
	int q = b + c;
	int w = q / 60;
	int e = q % 60;
	printf("%d %d\n", (a + w) % 24, e);
	return 0;
}
