#include <cstdio>
using namespace std;
int d[21],n;
int main()
{
	d[0] = 0;
	d[1] = 1;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
		d[i] = d[i - 1] + d[i - 2];

	printf("%d", d[n]);
}