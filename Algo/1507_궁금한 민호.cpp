#include<cstdio>

using namespace std;

const int INF = 1e9;
int N,A[21][21];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) scanf("%d", &A[i][j]);
	}
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (A[i][j] != INF && A[i][j] > A[i][k] + A[k][j])
				{
					printf("-1");
					return 0;
				}
				if (i == j || i==k|| j==k) continue;
				if (A[i][j] == (A[i][k] + A[k][j])) A[i][j] = INF;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i ++ )
	{
		for (int j = i; j <= N; j++)
		{
			if (A[i][j] != INF) ans += A[i][j];
		}
	}
	printf("%d", ans);
}