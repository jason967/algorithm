#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int A[20][20];
int ans = 1e9;

bool m[20];


vector<int> T1, T2;

void go(int t1, int t2, int member)
{
	if (member > N) return;
	if (T1.size() == N / 2 && T2.size() == N / 2)
	{
		int sum1 = 0, sum2 = 0;
		int t1_sz = T1.size();
		int t2_sz = T2.size();
		for (int i = 0; i < t1_sz; i++)
		{
			for (int j = 0; j < t1_sz; j++)
			{
				if (i == j) continue;
				sum1 += A[T1[i]][T1[j]];
			}
		}
		for (int i = 0; i < t2_sz; i++)
		{
			for (int j = 0; j < t2_sz; j++)
			{
				if (i == j) continue;
				sum2 += A[T2[i]][T2[j]];
			}
		}
		ans = min(ans, abs(sum1 - sum2));
		return;
	}
	T1.push_back(member);
	go(t1 + 1, t2, member + 1);
	T1.pop_back();
	T2.push_back(member);
	go(t1, t2 + 1, member + 1);
	T2.pop_back();
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
	go(0, 0, 0);
	printf("%d", ans);
}