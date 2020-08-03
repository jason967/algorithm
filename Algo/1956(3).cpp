#include<cstdio>
#include<vector>
#include<cstring>
#define pii pair<int,int>
using namespace std;
const int INF = 1e9;
bool visited[401];
int V, E,ans;
vector<pii> adj[401];
bool flag;
void dfs(int node,int start,int dist)
{
	if (dist > ans) return;
	if (node == start&&flag)
	{
		if (ans > dist) ans = dist;
		return;
	}
	flag = true;
	for (int i = 0; i < adj[node].size(); i++)
	{
		int next = adj[node][i].first;
		int nextCost = dist+adj[node][i].second;
		if (visited[next]) continue;
		visited[next] = true;
		dfs(next, start, nextCost);
		//visited[next] = false;
	}
}
int main()
{
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b,c });
	}
	ans = V * 10000;
	for (int i = 1; i <= V; i++)
	{
		flag = false;
		memset(visited, false, sizeof(visited));
		dfs(i, i,0);
	}
	if (ans == INF) ans = -1;
	printf("%d", ans);
}