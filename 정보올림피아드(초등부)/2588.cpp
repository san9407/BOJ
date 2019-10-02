#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int hun, mid, last;
	hun = m / 100;
	mid = (m / 10) % 10;
	last = m % 10;
	cout << n*last << '\n';
	cout << n*mid << '\n';
	cout << n*hun << '\n';
	cout << n*m << '\n';
	return 0;
}
