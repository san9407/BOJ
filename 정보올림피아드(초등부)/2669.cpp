#include<iostream>
using namespace std;

int a[101][101];

int main()
{
	int cnt = 0;
	int a[101][101] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++)
		{
			for (int k = y1; k < y2; k++)
			{
				if (a[j][k] == 0)
				{
					a[j][k] = 1;
					cnt++;
				}
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
