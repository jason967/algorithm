#include<cstdio>
#include<algorithm>

using namespace std;

int N, M, A[9], S[9];

void go(int cnt)
{
	if (cnt == M)
	{
		for(int i=0;i<M;i++)
			printf("%d ", S[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++)
	{
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