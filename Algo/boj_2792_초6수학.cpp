#include <cstdio>


int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	int a, b, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);

		int g = gcd(a, b);
		int l = g * (a / g)*(b / g);
		printf("%d %d", l, g);
		printf("\n");
	}
	return 0;
}
