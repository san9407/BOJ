#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#include <stack>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const long long LINF = 1e18 + 1;
const int MOD = 998244353;
typedef long long ll;
typedef pair<int, int> P;



int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int d;
	scanf("%d", &d);
	int time = a * 3600 + b * 60 + c + d;
	int ta = (time / 3600) % 24;
	int tb = (time / 60) % 60;
	int tc = time % 60;
	printf("%d %d %d\n", ta, tb, tc);
	return 0;
}
