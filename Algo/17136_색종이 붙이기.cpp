#include<cstdio>

using namespace std;

const int N = 5;
int A[10][10];
bool vis[10][10];

bool check(int y, int x, int sz)
{
	for (int i = y; i < y + sz; i++)
	{
		for (int j = 0; j < x + sz; j++) if (A[i][j] == 0) return false;
	}
	return true;
}

void go(int idx, int cnt)
{
	printf("idx: %d\n", idx);
	if (idx == N * N)
	{
		printf("res: %d\n", cnt);
		return;
	}
	int y = idx / N;
	int x = idx % N;
	if (A[y][x] == 0 || A[y][x]==1 && vis[y][x]) go(idx + 1, cnt);
	
	for (int sz = 3; sz > 0; sz--)
	{
		bool can = check(y, x, sz);
		printf("%d %d %d %d\n", y, x,sz, can);
		if (can)
		{
			for (int i = y; i < y + sz; i++)
			{
				for (int j = x; j < x + sz; j++) vis[i][j] = true;
			}
			go(idx + 1, cnt + 1);
			for (int i = y; i < y + sz; i++)
			{
				for (int j = x; j < x + sz; j++) vis[i][j] = false;
			}
		}
		else go(idx + 1, cnt);
	}
}

int main()
{
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
	go(0, 0);
}