#include<cstdio>
#include<queue>
#include<algorithm>
#define pii pair<int,int>

using namespace std;
const int INF = 1e9;
int N, M,d[1001];
vector<pii> V[1001];

void Dijkstra(int start,int arrive)
{
	fill(d, d + N+1, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,start });
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (cur == arrive)
		{
			printf("%d", d[arrive]);
			return;
		}
		if (cost > d[cur]) continue;
		for (int i = 0; i < V[cur].size(); i++)
		{
			int nx = V[cur][i].first;
			int nxCost = cost + V[cur][i].second;
			if (d[nx] > nxCost)
			{
				d[nx] = nxCost;
				pq.push({ nxCost,nx });
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		V[a].push_back({ b,c });
	}
	int fr,to ;
	scanf("%d %d", &fr, &to);
	Dijkstra(fr, to);
}