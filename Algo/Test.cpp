#include<cstdio>
using namespace std;

int A[10];
bool C[10];

int N = 5;

void go(int idx, int cnt)
{
	if (cnt == 5) {
		for (int i = 0; i < 5; i++) printf("%d ", A[i]);
		printf("\n");
		return;
	}
	for (int i = idx; i <= 7; i++)
	{
		if (C[i])continue;
		C[i] = true;
		A[cnt] = i;
		go(i, cnt+1);
		C[i] = false;
	}
}

int main()
{
	go(1, 0);
}