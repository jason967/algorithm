#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

#define pii pair<int,int>

using namespace std;

int A[101][101],cnt[101];
int R, C, K;
int maxR = 3, maxC = 3;

bool cmp(pii a, pii b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

void calR()
{
	int curC = maxC;
	for (int i = 0; i <maxR ; i++)
	{
		vector<pii> N;
		memset(cnt, 0, sizeof(cnt));

		for (int j = 0; j < curC; j++) cnt[A[i][j]]++;

		for (int n = 1; n <= 100; n++)
		{
			if (cnt[n] != 0) N.push_back({ cnt[n],n });
		}
		sort(N.begin(), N.end(), cmp);
		maxC = max(maxC, (int)N.size() * 2);
		int idx = 0;
		for (int j = 0; j < 100; j++) A[i][j] = 0;
		for (int j = 0; j < N.size(); j++)
		{
			A[i][idx++] = N[j].second;
			A[i][idx++] = N[j].first;
		}
	}
}

void calC()
{
	int curR = maxR;
	for (int i = 0; i < maxC; i++)
	{
		vector<pii> N;
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < curR; j++) cnt[A[j][i]]++;
		for (int n = 1; n <= 100; n++)
		{
			if (cnt[n] != 0) N.push_back({ cnt[n],n });
		}
		sort(N.begin(), N.end(), cmp);
		maxR = max(maxR, (int)N.size() * 2);
		int idx = 0;
		for (int j = 0; j < 100; j++) A[j][i] = 0;
		for (int j = 0; j < N.size(); j++)
		{
			A[idx++][i] = N[j].second;
			A[idx++][i] = N[j].first;
		}
	}
}

int main()
{
	scanf("%d %d %d", &R, &C, &K);
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) scanf("%d", &A[i][j]);
	if (A[R - 1][C - 1] == K)
	{
		printf("0");
		return 0;
	}
	int t = 0;
	while (1)
	{
		if (t > 100)
		{
			t = -1;
			break;
		}
		if (A[R - 1][C - 1] == K) break;
		if (maxR >= maxC) calR();
		else calC();
		t++;
	}
	printf("%d", t);
}