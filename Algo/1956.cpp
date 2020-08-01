#include<cstdio>
#include<algorithm>

#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF = 987654321;

int V, E, dist[401][401];

int main()
{
	scanf("%d %d", &V, &E);
	f(i, V) f(j, V) dist[i][j] = INF;

	f(i,E)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a - 1][b - 1] =  c;
	}

	f(k,V) f(i,V) f(j,V) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int ans = INF;
	f(i, V)
	{
		f(j, V)
		{
			if (i == j)
			{
				ans = min(ans, dist[i][j]);
			}
		}
	}
	if (ans == INF) ans = -1;
	printf("%d", ans);
}