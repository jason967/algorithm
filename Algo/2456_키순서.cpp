#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

vector<int>	adj[2][501];
bool v[501];

int N, M,ans, d[501];

void dfs(int node,int state)
{
	int sz = adj[state][node].size();
	for (int i = 0; i <sz ; i++)
	{
		int nx = adj[state][node][i];
		if (v[nx]) continue;
		v[nx] = true;
		d[nx]++;
		dfs(nx,state);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		adj[0][u].push_back(v);
		adj[1][v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
	{
		memset(v, false, sizeof(v));
		dfs(i,0);
		memset(v, false, sizeof(v));
		dfs(i, 1);
	}
	for (int i = 1; i <= N; i++)
	{
		if(d[i]==(N-1)) ans++;
	}
	printf("%d", ans);
}