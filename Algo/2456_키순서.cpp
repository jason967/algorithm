#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

vector<int> In[501],Out[501];
bool v[501];

int N, M,ans, d[501];

void dfsI(int node)
{
	int sz = In[node].size();
	for (int i = 0; i <sz ; i++)
	{
		int nx = In[node][i];
		if (v[nx]) continue;
		v[nx] = true;
		d[nx]++;
		dfsI(nx);
	}
}
void dfsO(int node)
{
	int sz = Out[node].size();
	for (int i = 0; i < sz; i++)
	{
		int nx = Out[node][i];
		if (v[nx]) continue;
		v[nx] = true;
		d[nx]++;
		dfsO(nx);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		In[u].push_back(v);
		Out[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
	{
		memset(v, false, sizeof(v));
		dfsO(i);
	}
	for (int i = 1; i <= N; i++)
	{
		memset(v, false, sizeof(v));
		dfsI(i);
	}
	for (int i = 1; i <= N; i++)
	{
		if(d[i]==(N-1)) ans++;
	}
	printf("%d", ans);
}