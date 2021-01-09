#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int getP(int set[], int x)
{
	if (set[x] == x) return x;
	return set[x] = getP(set, set[x]);
}

void uniP(int set[], int a, int b)
{
	a = getP(set, a);
	b = getP(set, b);
	if (a < b) set[b] = a;//더 작은 숫자가 부모로 병합
	else set[a] = b;
}

int find(int set[], int a, int b)
{
	a = getP(set, a);
	b = getP(set, b);
	if (a == b) return 1;
	else return 0;
}

class Edge {
public:
	int node[2];
	int dist;
	Edge(int a, int b, int dist)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->dist = dist;
	}
	bool operator<(Edge &edge)
	{
		return this->dist < edge.dist;
	}
};

int main()
{
	vector<Edge> V;
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		V.push_back(Edge(a, b, c));
	}
	sort(V.begin(), V.end());
	int set[1000];
	int sum = 0;
	for (int i = 0; i < n; i++)
		set[i] = i;
	for (int i = 0; i < V.size(); i++) {
		if (!find(set, V[i].node[0] - 1, V[i].node[1] - 1))
			sum += V[i].dist;
		uniP(set, V[i].node[0] - 1, V[i].node[1] - 1);
	}
	printf("%d", sum);
	return 0;
}