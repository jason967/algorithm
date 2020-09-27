#include<cstdio>

using namespace std;

bool A[101][101];
int N,ans;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int y, x;
		scanf("%d %d", &y, &x);
		for (int i = y; i < y + 10; i++)
		{
			for (int j = x; j < x + 10; j++) A[i][j] = true;
		}
	}
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++) if (A[i][j]) ans++;
	}
	printf("%d", ans);
}