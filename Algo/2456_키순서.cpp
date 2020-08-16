#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;


vector<int> adj[501];

int N, M;

bool vis[501];
int d[501];
bool isCycle;
void go(int node)
{
	d[node]++;
	//printf("%d\n", node);
	int len = adj[node].size();
	for (int i = 0; i < len; i++)
	{
		int next = adj[node][i];
		if (vis[next]) continue;
		vis[next] = true;
		go(next);
	}
}


int main()
{
	scanf("%d %d", &N,&M);
	for (int i = 0; i < M; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		adj[v].push_back(u);
	}
	//go(4, 4);
	for (int i = 1; i <= N; i++)
	{
		memset(vis, false, sizeof(vis));
		go(i);
	}
	for (int i = 0; i <= N; i++) printf("%d ", d[i]);
	//printf("%d", d[0]);
}