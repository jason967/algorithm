#include<cstdio>
#include<algorithm>

using namespace std;

const int INF = 1e9;

int N, M, A[101][101];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			A[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		A[a][b] = 1;
		A[b][a] = -1;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (A[i][k] == -1 && A[k][j] == -1)
				{
					A[i][j] = -1;
					A[j][i] = 1;
				}
			}
		}
	}
	int mid = N / 2;
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		int r = 0, l = 0;
		for (int j = 1; j <= N; j++)
		{
			if (A[i][j] == -1) l++;
			else if (A[i][j] == 1) r++;
		}
		if (r > mid || l > mid)ans++;
	}
	printf("%d", ans);
}