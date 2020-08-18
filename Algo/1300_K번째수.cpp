#include<cstdio>

using namespace std;

int N, K;

bool f(int mid)
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		int len = mid / i;
		if (len < N) cnt += len;
		else cnt += N;
	}
	printf("mid:%d cnt: %d\n", mid,cnt);
	return cnt < K;
}

int bs()
{
	int lo = 1;
	int hi = 1000;
	int res = 0;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		
		if (f(mid))
		{
			printf("Right\n");
			lo = mid + 1;
		}
		else
		{
			res = mid;
			printf("val:%d Left\n",res);
			hi = mid - 1;
		}
		printf("%d %d\n", lo, hi);
	}
	return res;
}

int main()
{
	scanf("%d %d", &N, &K);
	printf("%d", bs());
}