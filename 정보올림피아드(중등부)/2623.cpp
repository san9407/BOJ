#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
using namespace std;

vector<int> vt[1001];
int in[32001];
vector<int> temp;
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int K;
		scanf("%d", &K);
		for (int j = 0; j < K; j++)
		{
			int a;
			scanf("%d", &a);
			temp.push_back(a);
		}
		for (int j = 0; j < temp.size()-1; j++)
		{
			vt[temp[j]].push_back(temp[j+1]);
			in[temp[j+1]]++;
		}
		temp.clear();
	}
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (!in[i])
			q.push(i);
	}
	vector<int> ans;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		ans.push_back(curr);
		for (int i = 0; i < vt[curr].size(); i++)
		{
			int next = vt[curr][i];
			in[next]--;
			if (!in[next])
				q.push(next);
		}
	}
	if (ans.size() != N)
		puts("0");
	else
	{
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
