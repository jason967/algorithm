#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int A[64][64],CA[64][64];
int N, Q,origin;

void go(int y, int x, int sz, int target)
{
	if (sz == pow(2, target))
	{
		for (int i = 0; i < pow(2, target); i++)
		{
			for (int j = 0; j < pow(2, target); j++) printf("%d ", A[i][j]);
			printf("\n");
		}
		printf("\n");
		return;
	}
	go(y, x, sz / 2,target);
	go(y, x + sz / 2, sz / 2,target);
	go(y + sz / 2, x , sz / 2,target);
	go(y + sz / 2, x + sz / 2, sz / 2,target);
}

int main()
{
	scanf("%d %d", &N, &Q);
	origin = pow(2, N);
	for (int i = 0; i < origin; i++) for (int j = 0; j < origin; j++) scanf("%d", &A[i][j]);
	go(0, 0, origin, 1);
}