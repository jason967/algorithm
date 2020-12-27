#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

struct medal {
	int nation,gold,silver,bronze,rank;
};

bool cmp(const medal &a, const medal &b)
{
	if (a.gold > b.gold)
	{
		return true;
	}
	else if (a.gold == b.gold)
	{
		if (a.silver > b.silver)
			return true;
		else if (a.silver == b.silver)
		{
			if (a.bronze > b.bronze)
				return a.nation < b.nation;
		}
	}
	return false;
}


int main()
{
	
	scanf("%d %d", &N, &K);

	vector<medal>v(N);

	for (int i = 0; i < N; i++)
		scanf("%d %d %d %d", &v[i].nation, &v[i].gold, &v[i].silver, &v[i].bronze);

	sort(v.begin(), v.end(), cmp);

	v[0].rank = 1;

	for (int i = 1; i < N; i++)
	{
		if (v[i].gold == v[i - 1].gold&&v[i].silver == v[i - 1].silver&&v[i].bronze == v[i - 1].bronze)
			v[i].rank = v[i - 1].rank;
		else
			v[i].rank = i + 1;
	}

	for (int i = 0; i < N; i++)
	{
		if (K == v[i].nation)
			printf("%d\n", v[i].rank);
	}
}
