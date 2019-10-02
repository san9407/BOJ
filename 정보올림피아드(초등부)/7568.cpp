#include <cstdio>
#include<vector>
using namespace std;
#pragma warning(disable:4996)

int main() 
{
	int N;
	scanf("%d", &N);
	int arr[50];
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back({ x,y });
	}
	for (int i = 0; i < N; i++)
	{
		arr[i] = 1;
	}
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (v[i].first < v[j].first && v[i].second < v[j].second)
			{
				arr[i]++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("");
	return 0;
}
