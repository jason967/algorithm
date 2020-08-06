#include <cstdio>
using namespace std;

const long long Max = 100000000000000;
bool c[Max + 1];


//다시 풀것
int main()
{
	int M, N;

	c[0] = true;
	c[1] = true;

	for (int i = 2; i*i <= Max; i++)
	{
		if (c[i] == false)
			for (int j = i + i; j <= Max; j += i)
				c[j] = true;
	}
	scanf("%d %d", &M, &N);
	int cnt = 0;
	for (int i = M; i <= N; i++)
		if (c[i] == false)
			cnt++;
	printf("%d", cnt);

	return 0;

}
