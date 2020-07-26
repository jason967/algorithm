#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;
int p[1000001];

int find(int n)
{
	if (n==p[n]) return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[a] = b;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) p[i] = i;
	for (int i = 0; i < m; i++)
	{
		int A, a, b;
		scanf("%d %d %d", &A, &a, &b);
		if (A == 1)
		{
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
		else merge(a, b);
	}
}