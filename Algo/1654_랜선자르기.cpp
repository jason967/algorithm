#include<cstdio>

#define ll long long

using namespace std;

int N, K;

ll A[10001],hi;

bool can(ll len)
{
	int tmp = 0;
	for (int i = 0; i < N; i++) tmp += A[i] / len;
	return tmp >= K;
}

ll binarySearch()
{
	ll res = 0;
	ll lo = 1;
	ll mid;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (can(mid))
		{
			res = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	return res;
}

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &A[i]);
		if (A[i] > hi) hi = A[i];
	}
	printf("%lld", binarySearch());
}