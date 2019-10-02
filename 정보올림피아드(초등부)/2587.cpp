#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	const int len = 5;
	vector<int> a;
	for (int i = 0; i < len; i++)
	{
		int n;
		cin >> n;
		a.push_back(n);
	}
	int avg = 0;
	for (int i = 0; i < len; i++)
	{
		avg += a[i];
	}
	avg /= len;
	sort(a.begin(), a.end());
	cout << avg << '\n';
	cout << a[2] << '\n';
	return 0;
}
