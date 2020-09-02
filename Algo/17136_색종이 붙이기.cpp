#include<cstdio>

using namespace std;
const int INF = 1e9;
const int N = 5;
int A[10][10];
int paper[5];
int ans = INF;


bool check(int y, int x, int sz)
{
	if (y + sz > N || x + sz > N) return false;
	for (int i = y; i < y + sz; i++)
	{
		for (int j = x; j < x + sz; j++) if (A[i][j] == 0) return false;
	}
	return true;
}

void go(int y,int x, int cnt)
{
	printf("y %d, x: %d cnt: %d\n", y,x,cnt);
	if (y==N)
	{
		if (ans > cnt) ans = cnt;
		printf("res: %d\n", cnt);
		return;
	}
	if (x == N) 
	{
		go(y + 1, 0, cnt);
		return;
	}
	if (A[y][x] == 0)
	{
		printf("A[%d][%d]=0\n", y, x);
		go(y, x + 1, cnt);
		printf("A[%d][%d]=0 END\n", y, x);
		return;
	}
	
	for (int sz = 5; sz > 0; sz--)
	{
		if (paper[sz] == 5) continue;
		bool can = check(y, x, sz);
		if (can)
		{
			for (int i = y; i < y + sz; i++)
			{
				for (int j = x; j < x + sz; j++) A[i][j] = 0;
			}
			paper[sz]++;
			printf("\n");
			printf("fill->y: %d, x: %d ,size: %d\n",y,x, sz);
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++) printf("%d ", A[i][j]);
				printf("\n");
			}
			printf("\n");
			go(y,x+1, cnt + 1);
			paper[sz]--;
			for (int i = y; i < y + sz; i++)
			{
				for (int j = x; j < x + sz; j++) A[i][j] =1;
			}
			printf("\n");
			printf("eraze->y: %d, x: %d, size: %d\n",y,x ,sz);
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++) printf("%d ", A[i][j]);
				printf("\n");
			}
			printf("\n");
		}
		else printf("y: %d, x: %d, sz: %d , Return\n",y,x,sz);
	}
}

int main()
{
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
	go(0, 0,0);
	if (ans == INF) ans = -1;
	printf("%d", ans);
}