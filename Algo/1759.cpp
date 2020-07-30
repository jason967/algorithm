#include<cstdio>
#include<algorithm>
using namespace std;
int L, C;
char A[16],sel[16];
bool vis[16];

void go(int cnt)
{
	if (cnt == L)
	{
		int n = 0,m = 0;
		for (int i = 0; i < L; i++)
		{
			char temp = sel[i];
			if (temp == 'a' || temp == 'e' | temp == 'i' || temp == 'o' || temp == 'u')
				n++;
			else m++;
		}
		if (n < 1 || m < 2) return;
		for (int i = 0; i < L; i++) printf("%c", sel[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < C; i++)
	{
		if (vis[i]) continue;
		if (cnt != 0 && sel[cnt - 1] > A[i]) continue;
		vis[i] = true;
		sel[cnt] = A[i];
		go(cnt + 1);
		vis[i] = false;
	}
}

int main()
{
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++)scanf(" %c", &A[i]);
	sort(A, A + C);
	go(0);
}