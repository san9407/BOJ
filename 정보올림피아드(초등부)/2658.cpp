#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 100000;
const long long LINF = 1e18;

char board[10][11];
bool check[10][10];

bool cmp(const pair<int, int>& A, const pair<int, int>& B)
{
	return A.first == B.first ? A.second < B.second : A.first < B.first;
}

bool cmp2(const pair<int, int>& A, const pair<int, int>& B)
{
	return A.second == B.second ? A.first > B.first : A.second < B.second;
}

int dist(const pair<int, int>& A, const pair<int, int>& B)
{
	return (A.first - B.first)*(A.first - B.first) + (A.second - B.second)*(A.second - B.second);
}

int main()
{
	vector<pair<int, int> > temp;
	for (int i = 0; i < 10; i++)
	{
		scanf("%s", board[i]);
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] == '1')
				temp.push_back({ i,j });
		}
	}
	int sz = temp.size();
	vector<pair<int, int> > ans;
	sort(temp.begin(), temp.end(),cmp);
	int x = temp[0].first, y = temp[0].second;
	int x2 = temp[sz-1].first, y2 = temp[sz-1].second;
	if (!check[x][y])
	{
		check[x][y] = true;
		ans.push_back({ x,y });
	}
	if (!check[x2][y2])
	{
		check[x2][y2] = true;
		ans.push_back({ x2,y2 });
	}
	sort(temp.begin(), temp.end(), cmp2);
	x = temp[0].first, y = temp[0].second;
	x2 = temp[sz-1].first, y2 = temp[sz-1].second;
	if (!check[x][y])
	{
		check[x][y] = true;
		ans.push_back({ x,y });
	}
	if (!check[x2][y2])
	{
		check[x2][y2] = true;
		ans.push_back({ x2,y2 });
	}
	if (ans.size() != 3)
	{
		puts("0");
		return 0;
	}
	int a[3] = { 0,1,2 };
	bool flag = false;
	int tx1, ty1,tx2,ty2,tx3,ty3;
	do
	{
		int ta = dist(ans[a[0]], ans[a[1]]);
		int tb = dist(ans[a[0]], ans[a[2]]);
		int tc = dist(ans[a[1]], ans[a[2]]);
		if (ta==tb&&ta+tb==tc)
		{
			flag = true;
			tx1 = ans[a[0]].first;
			ty1 = ans[a[0]].second;
			tx2 = ans[a[1]].first;
			ty2 = ans[a[1]].second;
			tx3 = ans[a[2]].first;
			ty3 = ans[a[2]].second;
			break;
		}
	} while (next_permutation(a, a + 3));

	int color = 0;
	if (flag)
	{
		if (tx2 == tx3 && tx1 < tx2)
		{
			color = 0;
		}
		else if (tx2 == tx3 && tx1 > tx2)
		{
			color = 1;
		}
		else if (ty2 == ty3 && ty1 < ty2)
		{
			color = 2;
		}
		else if (ty2 == ty3 && ty1 > ty3)
			color = 3;
		else
			color = 4;
		if (color == 0)
		{
			if (ty2 > ty3)
				swap(ty2, ty3);
			for (int i = tx2; i >= tx1;i--)
			{
				int sy = ty2;
				int dy = ty3;
				while (sy <= dy)
				{
					if (board[i][sy] != '1')
					{
						puts("0");
						return 0;
					}
					sy++;
				}
				ty2++;
				ty3--;
			}
		}
		else if (color == 1)
		{
			if (ty2 > ty3)
				swap(ty2, ty3);
			for (int i = tx2; i <= tx1; i++)
			{
				int sy = ty2;
				int dy = ty3;
				while (sy <= dy)
				{
					if (board[i][sy] != '1')
					{
						puts("0");
						return 0;
					}
					sy++;
				}
				ty2++;
				ty3--;
			}
		}
		else if (color == 2)
		{
			if (tx2 > tx3)
				swap(tx2, tx3);
			for (int i = ty2; i >= ty1; i--)
			{
				int sx = tx2;
				int dx = tx3;
				while (sx <= dx)
				{
					if (board[sx][i] != '1')
					{
						puts("0");
						return 0;
					}
					sx++;
				}
				tx2++;
				tx3--;
			}
		}
		else if(color==3)
		{
			if (tx2 > tx3)
				swap(tx2, tx3);
			for (int i = ty2; i <= ty1; i++)
			{
				int sx = tx2;
				int dx = tx3;
				while (sx <= dx)
				{
					if (board[sx][i] != '1')
					{
						puts("0");
						return 0;
					}
					sx++;
				}
				tx2++;
				tx3--;
			}
		}
		else
		{
			int color2 = 0;
			if (tx1 != tx2)
			{
				swap(tx2, tx3);
				swap(ty2, ty3);
			}
			if (tx1 == tx2 && ty1 > ty2)
				color2 = 0;
			else if (tx1 == tx2 && ty1 < ty2)
				color2 = 1;
			
			bool flag2 = false;
			if (color2 == 0)
			{
				if (ty1 > ty2)
				{
					swap(ty1, ty2);
					flag2 = true;
				}
				if (flag2)
				{
					for (int i = tx1; i >= tx3; i--)
					{
						int sy = ty1;
						int dy = ty2;
						while (sy <= dy)
						{
							if (board[i][sy] != '1')
							{
								puts("0");
								return 0;
							}
							sy++;
						}
						ty1++;
					}
				}
				else
				{
					for (int i = tx1; i >= tx3; i--)
					{
						int sy = ty1;
						int dy = ty2;
						while (sy <= dy)
						{
							if (board[i][sy] != '1')
							{
								puts("0");
								return 0;
							}
							sy++;
						}
						ty2--;
					}
				}
			}
			else
			{
				if (ty1 > ty2)
				{
					swap(ty1, ty2);
					flag2 = true;
				}
				if (flag2)
				{
					for (int i = tx1; i <= tx3; i++)
					{
						int sy = ty1;
						int dy = ty2;
						while (sy <= dy)
						{
							if (board[i][sy] != '1')
							{
								puts("0");
								return 0;
							}
							sy++;
						}
						ty1++;
					}
				}
				else
				{
					for (int i = tx1; i <= tx3; i++)
					{
						int sy = ty1;
						int dy = ty2;
						while (sy <= dy)
						{
							if (board[i][sy] != '1')
							{
								puts("0");
								return 0;
							}
							sy++;
						}
						ty2--;
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
		}
	}
	else
		puts("0");
	return 0;
}
