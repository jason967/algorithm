#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int INF = 987654321;

int A[101],T,N;

int main() {
	
	for (int tc = 1; tc <= 4; tc++)
	{
		scanf("%d", &N);
		for (int i = 0; i < 100; i++)
		{
			scanf("%d", &A[i]);
		}
		sort(A, A + 100);
		for (int i = 0; i < N; i++)
		{
			A[0]++;
			A[99]--;
			sort(A, A + 100);
		}
		printf("#%d %d",tc, A[99] - A[0]);
	}
}
