#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const int MOD = 1e9 + 9;
const long long LINF = 1e18 + 1;
typedef long long ll;
typedef pair<int, int> P;

int arr[10];
int brr[10];

int main()
{
	int a = 0, b = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", arr + i);
	}
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", brr + i);
	}
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > brr[i])
			a++;
		else if (arr[i] < brr[i])
			b++;
	}
	if (a > b)
		puts("A");
	else if (a == b)
		puts("D");
	else
		puts("B");
	return 0;
}
