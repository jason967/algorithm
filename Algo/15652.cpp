#include<cstdio>
using namespace std;

int A[8], N, M;

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
		if (cnt != 0 && i < A[cnt - 1]) continue;
		A[cnt] = i;
		go(cnt + 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	go(0);
}