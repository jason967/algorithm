#include <cstdio>
#include<vector>
using namespace std;

const long long Max = 10000000;
bool c[Max + 1];

vector<long long> prime;

int main()
{
	long long A, B;

	c[0] = true;
	c[1] = true;

	for (int i = 2; i*i <= Max; i++)
	{
		if (c[i] == false)
		{
			for (int j = i + i; j <= Max; j += i)
				c[j] = true;
		}
	}
	for (int i = 2; i <= Max; i++) if (!c[i]) prime.push_back(i);
	scanf("%lld %lld", &A, &B);
	long long ans = 0;
	for (int i = 0; i < prime.size(); i++)
	{
		long long p = prime[i];
		long long cur = p;
		while (cur <= B / p)
		{
			cur *= p;
			if (cur >= A)
			{
				ans++;
			}
		}
	}
	printf("%lld", ans);
}