#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int gcdA = a;
	int gcdB = b;
	while (gcdB != 0)
	{
		int r = gcdA%gcdB;
		gcdA = gcdB;
		gcdB = r;
	}
	printf("%d\n", gcdA);
	long long lcd = a*b / gcdA;
	printf("%lld\n", lcd);
}
