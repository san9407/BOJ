#include<iostream>
#include<string>
using namespace std;

int main()
{
	string ph;
	cin >> ph;
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < ph.size(); i++)
	{
		if (ph[i] == '(')
		{
			cnt++;
		}
		else
		{
			if (ph[i - 1] == ')')
			{
				cnt--;
				sum += 1;
			}
			else
			{
				cnt--;
				sum += cnt;
			}
		}
		if (cnt < 0)
		{
			break;
		}
	}
	printf("%d\n", sum);
	return 0;
}
