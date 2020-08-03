#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

#define pii pair<int,int>

using namespace std;
const int INF = 1e9;
vector<pii> adj[20001];
int d[20001];

int V, E, K;

void Dijkstra()
{
	for (int i = 1; i <= V; i++) d[i] = INF;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,K });
	d[K] = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (d[cur] < cost) continue;
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int nextCost = cost + adj[cur][i].second;
			int Next = adj[cur][i].first;
			if (d[Next] > nextCost)
			{
				d[Next] = nextCost;
				pq.push({ nextCost,Next });
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (d[i] == INF) printf("INF\n");
		else printf("%d\n", d[i]);
	}
}

int main()
{
	scanf("%d %d %d", &V, &E, &K);
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b,c });
	}

	Dijkstra();

}