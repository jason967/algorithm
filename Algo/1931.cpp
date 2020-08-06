#include<cstdio>
#include<vector>
#include<algorithm>
#define pii pair<int,int>
using namespace std;

int N;

vector<pii> v;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int f, t;
		scanf("%d %d", &f, &t);
		v.push_back({ f,t });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		printf("%d %d\n", v[i].first, v[i].second);
	}
}