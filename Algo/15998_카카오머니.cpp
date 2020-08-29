#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

struct _pay
{
	ll in, res;
}pay[300001];

const ll INF = 9*10e18;
ll M, max_res = INF;
int N;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld %lld", &pay[i].in, &pay[i].res);
		if (pay[i].res != 0 && pay[i].res < max_res) max_res = pay[i].res;
	}
	for (int i = 1; i <= N; i++)
	{
		if (pay[i].in > 0)
		{
			if (pay[i - 1].res + pay[i].in != pay[i].res)
			{
				printf("-1");
				return 0;
			}
		}
		else if (pay[i].in < 0)
		{
			ll tmp = pay[i].res - pay[i].in - pay[i - 1].res;

			if (pay[i - 1].res + pay[i].in >= 0)
			{
				if (tmp != 0)
				{
					printf("-1");
					return 0;
				}
			}
			else
			{
				if (tmp == 0)
				{
					printf("-1");
					return 0;
				}
				M = gcd(M, tmp);
				if (max_res !=INF &&M <= max_res)
				{
					printf("-1");
					return 0;
				}
				if (M == 1 && pay[i].res != 0)
				{
					printf("-1");
					return 0;
				}
			}
		}
	}
	if (M == 0)
	{
		printf("1");
		return 0;
	}
	printf("%lld", M);
}