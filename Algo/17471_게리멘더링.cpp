#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

const int INF = 1e9;

int N;
int A[11];
vector<int> adj[11];
vector<int> T[2];
bool used[11];
int sum[2];
int ans = INF;


void dfs(int node,vector<int> &t)
{
	for (int i = 0; i < adj[node].size(); i++)
	{
		int nx = adj[node][i];
		if (used[nx]) continue;
		bool isHere = false;
		for (int j = 0; j < t.size(); j++)
		{
			if (nx == t[j]) isHere = true;
		}
		if (!isHere) continue;
		used[nx] = true;
		dfs(nx,t);
	}
}
void go(int cnt)
{
	if (cnt == N+1)
	{
		int t1sz = T[0].size();
		int t2sz = T[1].size();
		if (t1sz == 0 || t2sz == 0) return;
		bool can = true;
		for (int i = 0; i < 2; i++)
		{
			int temp = 0;
			memset(used, false, sizeof(used));
			for (int j = 0; j < T[i].size(); j++)
			{
				if (!used[T[i][j]])
				{
					dfs(T[i][j], T[i]);
					temp++;
					if (temp == 2) return;
				}
			}
		}
		
		for (int i = 0; i < 2; i++)
		{
			sum[i] = 0;
			for (int j = 0; j < T[i].size(); j++)
			{
				sum[i] += A[T[i][j]];
			}
		}
		int diff = abs(sum[0] - sum[1]);
		if (ans > diff) ans = diff;
		return;
	}
	T[0].push_back(cnt);
	go(cnt + 1);
	T[0].pop_back();
	T[1].push_back(cnt);
	go(cnt + 1);
	T[1].pop_back();
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for (int i = 1; i <= N; i++)
	{
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++)
		{
			int b;
			scanf("%d", &b);
			adj[i].push_back(b);
			adj[b].push_back(i);
		}
	}
	go(1);
	if (ans == INF) ans = -1;
	printf("%d", ans);
}