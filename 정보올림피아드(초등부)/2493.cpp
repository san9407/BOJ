#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <functional>
#include <deque>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
const int INF = 1000000000;
typedef long long ll;

stack<pair<int, int> > st;

int main() 
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int num;
		scanf("%d", &num);
		while (!st.empty())
		{
			if (st.top().second > num)
			{
				printf("%d ", st.top().first);
				break;
			}
			st.pop();
		}
		if (st.empty())
			printf("0 ");
		st.push(make_pair(i, num));
	}
	return 0;
}
