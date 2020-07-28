#include<cstdio>
#include<algorithm>
using namespace std;

int N, M, A[9],S[9];
bool C[9];
void go(int idx, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", S[i]);
		printf("\n");
	}
	for (int i = idx; i < N; i++)
	{
		if (C[i]) continue;
		C[i] = true;
		S[cnt] = A[i];
		go(i, cnt + 1);
		C[i] = false;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	sort(A, A + N);
	go(0, 0);
}