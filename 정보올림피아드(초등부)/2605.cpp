#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main()
{
	int size;
	cin >> size;
	vector<int> student(size);
	vector<int> list;
	for (int i = 0; i < size; i++)
	{
		int k;
		cin >> k;
		list.insert(begin(list) + k, i + 1);
	}
	for (int i = size; i > 0;)
	{
		cout << list[--i] << " ";
	}
	cout << endl;

	return 0;
}
