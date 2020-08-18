#include<cstdio>
#include<algorithm>
using namespace std;

int N, M,hi;
int A[300001];

bool f(int mid)
{
	int res = 0;
	for (int i = 0; i < M; i++)
	{
		res += A[i] / mid;
		if (A[i] % mid != 0) res++;
	}
	return res<=N;
}

int bs()
{
	int lo = 1;
	int res = 1e9;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (f(mid))
		{
			hi = mid - 1;
			res = min(res, mid);
		}
		else lo = mid + 1;
		
	}
	return res;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &A[i]);
		if (hi < A[i]) hi = A[i];
	}
	printf("%d", bs());
}