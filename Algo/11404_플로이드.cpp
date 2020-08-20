#include<cstdio>
#include<algorithm>
using namespace std;
const int INF = 1e9;
int A[101][101];
int N, M;

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j) A[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(A[a][b]>c) A[a][b] = c;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (A[i][j] == INF) A[i][j] = 0;
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}