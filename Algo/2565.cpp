#include<cstdio>
#include<algorithm>
using namespace std;

int A[501],cnt[501];
int N;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		A[a] = b;
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%d %d\n", i, A[i]);
	}
	printf("after\n");
	sort(A, A + 20);
	for (int i = 0; i < 20; i++)
	{
		printf("%d %d\n", i, A[i]);
	}

}