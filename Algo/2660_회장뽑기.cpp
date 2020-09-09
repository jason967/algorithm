#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int N;
vector<int> adj[51];
int P[51];
bool used[51];
int bfs(int num)
{
	queue<int> q;
	memset(used, false, sizeof(used));
	used[num] = true;
	q.push(num);
	int depth = 0;
	while (!q.empty())
	{
		int sz = q.size();
		for (int i = 0; i < sz; i++)
		{
			int cur = q.front();
			q.pop();
			for (int i = 0; i < adj[cur].size(); i++)
			{
				int nx = adj[cur][i];
				if (used[nx]) continue;
				used[nx] = true;
				q.push(nx);
			}
		}
		depth++;
	}
	return depth;
}
int main()
{
	scanf("%d",&N);
	while (1)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1) break;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 1e9;
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		int temp = bfs(i);
		if (temp < ans) ans = temp;
		P[i] = temp;
	}
	for (int i = 1; i <= N; i++)
	{
		if (P[i] == ans) cnt++;
	}
	printf("%d %d\n", ans-1, cnt);
	for (int i = 1; i <= N; i++)
	{
		if (P[i] == ans) printf("%d ", i);
	}
}