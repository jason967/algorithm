#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

struct gra
{
	int here, cost;
};

int N,ans;
int dist[10001];
vector<gra> adj[10001];

int bfs(int st)
{
	int res = 0;
	queue<gra> q;
	memset(dist, -1, sizeof(dist));
	dist[st] = 0;
	q.push({ st,0 });
	while (!q.empty())
	{
		int cur = q.front().here;
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int nx = adj[cur][i].here;
			int nDist = adj[cur][i].cost;
			if (dist[nx] != -1) continue;
			dist[nx] = dist[cur] + nDist;
			if (res < dist[nx]) res = dist[nx];
			q.push({ nx,dist[nx] });
		}
	}
	return res;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++)
	{
		int v, u, cost;
		scanf("%d %d %d", &v, &u, &cost);
		adj[v].push_back({ u,cost });
		adj[u].push_back({ v,cost });
	}
	for (int i = 1; i <= N; i++)
	{
		int temp = bfs(i);
		if (ans < temp) ans = temp;
	}
	printf("%d", ans);
}