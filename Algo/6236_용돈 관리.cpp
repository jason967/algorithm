#include<cstdio>
#include<algorithm>

using namespace std;

int N, M, lo = 1;
int A[100001];
int hi = 1e9;

bool f(int mid)
{
	int m = 1;
	int cur = 0;
	for (int i = 0; i < N; i++)
	{
		if (cur + A[i] > mid)
		{
			m++;
			cur = A[i];
		}
		else cur += A[i];
	}
	return m>M;
}

int bs()
{
	int res = 1e9;
	int mid;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (f(mid))
		{
			lo = mid + 1;
		}
		else
		{
			res = min(res, mid);
			hi = mid - 1;
			//res = mid;
		}
	}
	return res;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		if (A[i] > lo) lo = A[i];
	}
	printf("%d", bs());
}