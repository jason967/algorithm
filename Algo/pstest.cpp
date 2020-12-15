#include<cstdio>
#include<stack>

using namespace std;

int T, N, A[301];

int main()
{
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &A[i]);
		for (int i = 0; i < N / 2; i++)
		{
			printf("%d %d ", A[i], A[N - 1 - i]);
		}
		if (N % 2 != 0)
		{
			printf("%d", A[N / 2]);
		}
		printf("\n");
	}

}