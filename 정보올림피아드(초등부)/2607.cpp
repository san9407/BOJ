#include <stdio.h>
#include <stdlib.h>

int n;
int alpa[26], total;
int inputAlpa[26], inputTotal;

int main()
{
	int i;
	char c;
	int cnt, count = 0, check;

	scanf("%d ", &n);

	while (scanf("%c", &c) && c != '\n') 
	{
		inputTotal++;
		inputAlpa[c - 'A']++;
	}

	while (n-- > 1)
	{
		total = cnt = 0;

		while (scanf("%c", &c) && c != '\n') 
		{
			total++;
			alpa[c - 'A']++;
		}

		for (i = 0; i < 26; i++)
		{
			check = abs(inputAlpa[i] - alpa[i]);
			alpa[i] = 0;

			if (check == 1)             cnt++;
			else if (check > 1)         cnt = 10;
		}

		if (cnt < 2 || (cnt == 2 && inputTotal == total))        count++;
	}

	printf("%d\n", count);

	return 0;
}
