#include<cstdio>

using namespace std;

int N,len,A[50],sel[6];

bool used[50];

void go(int idx, int cnt)
{
	if (cnt == 6)
	{
		for (int i = 0; i < 6; i++) printf("%d ", sel[i]);
		printf("\n");
		return;
	}
	for (int i = idx; i < len; i++)
	{
		if (used[i]) continue;
		used[i] = true;
		sel[cnt] = A[i];
		go(i, cnt + 1);
		used[i] = false;
	}
}

int main()
{
	while (1)
	{
		scanf("%d", &len);
		if (len == 0) break;
		for (int i = 0; i < len; i++) scanf("%d", &A[i]);
		go(0, 0);
		printf("\n");
	}
}