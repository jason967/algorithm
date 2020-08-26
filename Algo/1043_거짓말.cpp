#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int N, M;
vector<int> P[51];
bool d[51], used[51];
int A[51][51],num[51];
bool can;
void dfs(int node)
{
	if (d[node]) can = false;
	for (int i = 0; i < P[node].size(); i++)
	{
		int nx = P[node][i];
		if (d[nx]) can = false;
		if (used[nx]) continue;
		used[nx] = true;
		dfs(nx);
	}
}
int main()
{
	int K;
	scanf("%d %d", &N, &M);
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int a;
		scanf("%d", &a);
		d[a] = true;
	}
	
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &num[i]);
		for (int j = 0; j < num[i]; j++) scanf("%d", &A[i][j]);
		for (int j = 0; j < num[i]; j++)
		{
			for (int m = 0; m < num[i]; m++)
			{
				if (m == j) continue;
				P[A[i][j]].push_back(A[i][m]);
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < M; i++)
	{
		can = true;
		for (int j = 0; j < num[i]; j++)
		{
			memset(used, false, sizeof(used));
			dfs(A[i][j]);
			if (!can) break;
		}
		if (can) ans++;
		
	}
	printf("%d", ans);
}