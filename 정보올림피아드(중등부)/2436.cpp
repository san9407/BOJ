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

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int g, l;
	scanf("%d %d", &g, &l);
	l /= g;
	int a, b;
	for (int i = 1; i * i <= l; i++)
	{
		if (l % i == 0)
		{
			if (gcd(i, l / i) == 1)
			{
				a = i;
				b = l / i;
			}
		}
	}
	printf("%d %d\n", a * g, b * g);
	return 0;
}
