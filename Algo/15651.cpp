#include<cstdio>
using namespace std;

int N,M,A[8];

void go(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++) printf("%d ", A[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		A[cnt] = i;
		go(cnt + 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	go(0);
}
