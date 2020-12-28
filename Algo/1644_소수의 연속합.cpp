#include<cstdio>
#include<vector>
using namespace std;

bool c[4000000];
int n, k, s, e;
int sum,result;

int main()
{
	vector<int> V;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 2; i <= n; i++)
		for (int j = i; j <= n; j += i)
			if (!c[j])
			{
				c[j] = true;
				if (i == j)
					V.push_back(j);
			}

	int len = (int)V.size();
	while (e <= s && e < len)
	{
		if (sum >= n || e == len - 1) sum -= V[e++];
		else sum += V[s++];
		if (sum == n) result++;
	}
	if (n == 2) result = 1;
	printf("%d", result);

	return 0;
}