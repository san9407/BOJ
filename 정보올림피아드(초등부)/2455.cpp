#include<iostream>
using namespace std;

int main()
{
	int max = 0;
	int pass = 0;
	for (int i = 0; i < 4; i++)
	{
		int out, in;
		cin >> out >> in;
		int sum = in - out;
		pass += sum;
		if (pass>max)
		{
			max = pass;
		}
	}
	cout << max << '\n';
	return 0;
}
