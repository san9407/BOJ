#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 100000;
const long long LINF = 1e18;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	vector<int> temp;
	for (int i = 1; i*i <= N; i++)
	{
		if (N%i == 0)
		{
			temp.push_back(i);
			if (i*i != N)
				temp.push_back(N / i);
		}
	}
	if (temp.size() < K)
		puts("0");
	else
	{
		sort(temp.begin(), temp.end());
		printf("%d\n", temp[K - 1]);
	}
	return 0;
}
