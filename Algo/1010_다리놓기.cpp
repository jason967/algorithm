#include<cstdio>

using namespace std;

int dp[31][31];

int main()
{

	int T;
	scanf("%d", &T);

	dp[0][0] = 1;
	for (int i = 1; i < 30 + 1; i++)
		for (int j = 0; j < 31; j++)
		{
			dp[i][0] = 1;
			dp[i][i] = 1;
			//dp[i][j] % 10007;
		}
	for (int i = 1; i < 31; i++)
		for (int j = 1; j < 31; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			//dp[i][j] %=10007;
		}

	while (T--)
	{
		int n, k;
		scanf("%d %d", &k, &n);
		printf("%d\n", dp[n][k]);
	}
}