#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

vector<int> v[501];

int N, M,ans;
int d[501];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	memset(d, -1, sizeof(d));
	d[1] = 0;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int nx = v[cur][i];
			if (d[nx]!=-1) continue;
			d[nx] = d[cur] + 1;
			q.push(nx);
		}
	}
	for (int i = 2; i <= N; i++) if (d[i]==1 || d[i]==2) ans++;
	printf("%d", ans);
}