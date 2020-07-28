#include<cstdio>
#include<algorithm>
using namespace std;

int N,M,s[9],A[9];
bool C[9];
void go(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", s[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (C[i]) continue;
		s[cnt] = A[i];
		C[i] = true;
		go(cnt+1);
		C[i] = false;
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	sort(A, A + N);
	go(0);
}