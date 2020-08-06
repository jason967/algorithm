#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

struct pos
{
	int x, y;
};

int N,T;
bool vis[102],ans;

vector<int> adj[102];

int md(int x1, int y1, int x2, int y2)
{
	return abs(y1 - y2) + abs(x1 - x2);
}

void dfs(int node) 
{
	if (ans) return;
	if (node == N + 1)
	{
		ans = true;
		return;
	}
	int sz = adj[node].size();
	for (int i = 0; i < sz; i++)
	{
		int nx = adj[node][i];
		if (vis[nx])continue;
		vis[nx] = true;
		dfs(nx);
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		
		vector<pos> coord;

		for (int i = 0; i < N + 2; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			coord.push_back({ a,b });
		}

		//i->j
		for (int i = 0; i < N + 2; i++)
		{
			for (int j = i + 1; j < N + 2; j++)
			{
				if (md(coord[i].x, coord[i].y, coord[j].x, coord[j].y) <= 1000)
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		ans = false;
		vis[0] = true;
		dfs(0);
		if (ans) printf("happy\n");
		else printf("sad\n");
		//Init
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < N + 2; i++) adj[i].clear();
	}
}