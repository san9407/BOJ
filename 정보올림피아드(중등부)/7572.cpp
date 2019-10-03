#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const long long LINF = 1e18 + 1;
const int MOD = 1000000000;
typedef long long ll;
typedef pair<int, int> P;

int main() 
{
	int N;
	scanf("%d", &N);
	N %= 120;
	int t = 2013 % 120;
	int a = 5;
	int b = 9;
	if (N > t)
	{
		while (N > t)
		{
			a = (a + 1) % 12;
			b = (b + 1) % 10;
			N--;
		}
	}
	else
	{
		while (N < t)
		{
			a = (a - 1 + 12) % 12;
			b = (b - 1 + 10) % 10;
			N++;
		}
	}
	char c = 'A' + a;
	char d = '0' + b;
	printf("%c%c\n", c, d);
	return 0;
}
