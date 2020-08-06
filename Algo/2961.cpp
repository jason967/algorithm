#include<cstdio>
#include<vector>
#include<algorithm>

#define pii pair<int,int>

using namespace std;

const int INF = 1e9;
int N;

bool used[10];
int sel[10];

int ans = INF;
vector<pii> v;

void go(int cnt, int idx,int target)
{
	if (cnt == target)
	{
		int S = 1;
		int B = 0;
		for (int i = 0; i < cnt; i++)
		{
			S *= v[sel[i]].first;
			B += v[sel[i]].second;
		}
		int diff = abs(S - B);
		if (ans > diff) ans = diff;
		return;
	}
	for (int i = idx; i < N; i++)
	{
		if (used[i]) continue;
		sel[cnt] = i;
		used[i] = true;
		go(cnt + 1, i, target);
		used[i] = false;
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}
	for (int i = 1; i <= N; i++)
	{
		go(0, 0, i);
	}
	printf("%d", ans);
}