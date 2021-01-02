#include<cstdio>
#include <algorithm>

using namespace std;

int C[1000001];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int k;
		scanf("%d", &k);
		C[i] = k;
	}
	sort(C, C + N);

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", C[i]);
	}
}