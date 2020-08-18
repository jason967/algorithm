#include<cstdio>
#include<algorithm>
#define ll long long

using namespace std;

ll A[1000001], N, M,ans;

int main()
{
	
	scanf("%lld %lld", &N, &M);

	ll high = 1;
	ll low = 0;

	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		if (A[i] > high) high = A[i];
	}

	while (low <= high)
	{
		ll mid = (low + high) / 2;
		ll temp = 0;

		for (int i = 0; i < N; i++)
			if (A[i] > mid)
				temp += A[i] - mid;

		if (temp >= M)
		{
			ans = max(ans, mid);
			low = mid + 1;
		}

		else
			high = mid - 1;
	}

	printf("%lld", ans);
}

