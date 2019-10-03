#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <functional>
#include <deque>
using namespace std;
const int INF = 1000000000;

int arr[201];

int main() 
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	vector<int> vt;
	for (int i = 0; i < N; i++)
	{
		if (vt.empty())
			vt.push_back(arr[i]);
		if (vt.back() < arr[i])
		{
			vt.push_back(arr[i]);
		}
		else
		{
			int k = lower_bound(vt.begin(), vt.end(), arr[i]) - vt.begin();
			vt[k] = arr[i];
		}
	}
	printf("%d\n", N-vt.size());
	return 0;
}
