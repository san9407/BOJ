#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;

int a[10];
int b[10];

int main()
{
	for (int i = 0; i < 10; i++)
		scanf("%d", a + i);
	for (int i = 0; i < 10; i++)
		scanf("%d", b + i);
	int last = 0;
	int cnt = 0;
	int A = 0, B = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] > b[i])
		{
			A += 3;
			last = 0;
		}
		else if (a[i] == b[i])
		{
			cnt++;
			A++;
			B++;
		}
		else
		{
			B += 3;
			last = 1;
		}
	}
	printf("%d %d\n", A, B);
	if (cnt == 10)
		puts("D");
	else
	{
		if (A > B)
			puts("A");
		else if (B > A)
			puts("B");
		else
			printf("%c\n", last == 0 ? 'A' : 'B');
	}
	return 0;
}
