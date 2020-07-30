#include<cstdio>
#include<vector>

using namespace std;

int N, M;
vector<int> V[101];
bool mid[101];
int cnt[101];

void go(int c)
{
	if (!mid[c])
	{
		cnt[c]++;
		return;
	}
	int Vsz = V[c].size();
	for (int i = 0; i < Vsz; i++)
	{
		int nx = V[c][i];
		go(nx);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int x, y, k;
		scanf("%d %d %d", &x, &y, &k);
		mid[x] = true;
		for (int j = 0; j < k; j++)V[x].push_back(y);
	}
	go(N);
	for (int i = 1; i < N;i++)
	{
		if (!mid[i]) printf("%d %d\n", i, cnt[i]);
	}
}