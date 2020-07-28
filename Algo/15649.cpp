#include<cstdio>
using namespace std;

int N, M,A[9];
bool C[9];

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
		if (C[i]) continue;
		C[i] = true;
		A[cnt] = i;
		go(cnt + 1);
		C[i] = false;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	go(0);
}