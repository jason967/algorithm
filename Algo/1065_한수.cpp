#include <cstdio>

using namespace std;

int n, ans, cnt, a, b;

int main()
{
	scanf("%d", &n);

	if (n < 100)
		ans = n;

	else if (n >= 100 && n <= 1000)
	{
		for (int i = 100; i <= n; i++)
		{
			a = (i % 100 / 10) - (i / 100);
			b = (i % 10) - (i % 100 / 10);
			if (a == b)
				cnt++;
		}
		ans = cnt + 99;
	}
	printf("%d\n", ans);
}