#include<cstdio>

using namespace std;

int A[3000000], kind[3001];
int N, d, k, c,cnt,ans;

int main()
{
	scanf("%d %d %d %d", &N, &d, &k, &c);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	kind[c] = 1;
	cnt = 1;
	for (int i = 0; i < k; i++)
	{
		if (kind[A[i]] == 0) cnt++;
		kind[A[i]]++;
	}
	for (int i = 0; i < N-1; i++)
	{
		if (ans < cnt) ans = cnt;
		kind[A[i]]--;
		if (kind[A[i]] == 0) cnt--;
		if (kind[A[(i + k)%N]] == 0) cnt++;
		kind[A[(i + k)%N]]++;
	}
	printf("%d", ans);
}