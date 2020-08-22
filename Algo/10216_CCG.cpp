#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int p[3001];
int N, T;

struct _G
{
	int y, x, R;
}G[3001];

int find(int n)
{
	if (p[n] == n) return p[n];
	return p[n] = find(p[n]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}

int dist(int y1, int x1, int y2, int x2)
{
	int a = abs(y1 - y2);
	int b = abs(x1 - x2);
	a = pow(a, 2);
	b = pow(b, 2);

	return a+b;
}

int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) p[i] = i;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d %d %d", &G[i].y, &G[i].x, &G[i].R);
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j) continue;
				int R = G[i].R + G[j].R;
				if (dist(G[i].y, G[i].x, G[j].y, G[j].x) <=R*R)
				{
					merge(find(i), find(j));
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			if (p[i] == i) ans++;
		}
		printf("%d\n", ans);
	}
}