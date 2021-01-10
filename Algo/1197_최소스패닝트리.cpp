#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int V, E;
struct info { int s, e, dist; };
vector<info> path;
int p[10001];
bool cycle;

bool comp(info a, info b) { return a.dist < b.dist; }

int find(int n)
{
	if (n == p[n]) return p[n];
	else return p[n] = find(p[n]);
}

void merge(int a, int b)
{
	cycle = false;
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[a] = b;
	cycle = true;
}

int main()
{
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= V; i++) p[i] = i;
	int res = 0;
	for (int i = 0; i < E; i++)
	{
		int s, e, dist;
		scanf("%d %d %d", &s, &e, &dist);
		path.push_back({ s,e,dist });
	}
	sort(path.begin(), path.end(), comp);
	for (int i = 0; i < path.size(); i++)
	{
		merge(path[i].s, path[i].e);
		if (cycle) res += path[i].dist;
	}
	printf("%d", res);
}