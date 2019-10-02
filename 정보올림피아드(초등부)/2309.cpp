#include <cstdio>
#include<algorithm>
#pragma warning(disable:4996)

int main(void)
{
	int arr[9];
	int i, j;
	int sum = 0;
	for (i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	std::sort(arr, arr + 9);

	int ti = -1;
	int tj = -1;
	for (i = 0; i < 9; i++)
	{
		int temp = sum;
		temp -= arr[i];

		for (j = i + 1; j < 9; j++)
		{
			int tmp = temp;
			tmp -= arr[j];
			if (tmp == 100)
			{
				ti = i;
				tj = j;
				break;
			}
		}
		if (ti > -1)
		{
			break;
		}
	}
	for (i = 0; i <9; i++)
	{
		if (i == ti || i == tj)
		{
			continue;
		}
		else
		{
			printf("%d\n", arr[i]);
		}
	}

	return 0;
}
