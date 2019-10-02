#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1000000000;

int main()
{
	int K, N, M;
	scanf("%d %d %d", &K, &N, &M);
	if (K*N > M)
		printf("%d\n", K*N - M);
	else
		puts("0");
	return 0;
}
