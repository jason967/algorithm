#include<cstdio>
using namespace std;

int N,M,A[9];
bool C[9];

void go(int idx, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++) printf("%d ", A[i]);
		printf("\n");
		return;
	}
	for (int i = idx; i <= N; i++)
	{
		if (C[i]) continue;
		C[i] = true;
		A[cnt] = i;
		go(i, cnt + 1);
		C[i] = false;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	go(1, 0);
}
