#include<cstdio>
#include<algorithm>
using namespace std;

int A[8], S[8], N, M;

void go(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++) printf("%d ", S[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (cnt != 0 && A[i] < S[cnt - 1]) continue;
		S[cnt] = A[i];
		go(cnt + 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	sort(A, A + N);
	go(0);
}