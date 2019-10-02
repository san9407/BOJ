#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int arr[10];
	memset(arr, 0, sizeof(arr));
	int A, B, C;
	cin >> A >> B >> C;
	unsigned long long N = A*B*C;
	while (N > 0)
	{
		int mod = N % 10;
		arr[mod] += 1;
		N /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << '\n';
	}
}
