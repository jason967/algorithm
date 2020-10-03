#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int sel[3];
int N, M;
vector<int> V[201];
bool C[201];
bool check[201];
int ans;

void dfs(int node)
{
	check[node] = true;
	for (int i = 0; i < V[node].size(); i++)
	{
		int nx = V[node][i];
		if (check[nx]) continue;
		check[nx] = true;
	}
}

void go(int idx, int cnt)
{
	if (cnt == 3)
	{
		int count = 0;
		memset(check, false, sizeof(check));
		for (int i = 0; i < 3; i++)
		{
			if (!check[sel[i]])
			{
				dfs(sel[i]);
				count++;
			}
		}
		if (count == 3) ans++;
		return;
	}
	for (int i = idx; i <= N; i++)
	{
		if (C[i]) continue;
		C[i] = true;
		sel[cnt] = i;
		go(i, cnt + 1);
		C[i] = false;
	}
}


int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	go(1, 0);
	printf("%d", ans);
}
