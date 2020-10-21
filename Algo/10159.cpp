#include<cstdio>

using namespace std;

int N, M;
bool A[101][101];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		A[u][v] = true;
	}
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				if (A[i][k] && A[k][j]) A[i][j] = true;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i == j) continue;
			if (!A[i][j] && !A[j][i]) cnt++;
		}
		printf("%d\n", cnt);
	}
}