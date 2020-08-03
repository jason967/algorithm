#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;

vector<pii> v;

int N,d[501];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int len = v.size();
	int ans = 1;
	d[0] = 1;
	for (int i = 1; i < len; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (v[i].second > v[j].second && d[i] <= d[j])
			{
				d[i] = d[j] + 1;
				if (ans < d[i]) ans = d[i];
			}
		}
	}
	printf("%d", N - ans);
}