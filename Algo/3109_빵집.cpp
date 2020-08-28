#include<cstdio>

using namespace std;

char A[10001][501];
bool used[10001][501];

int N, M;

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}

int dy[] = { -1,0,1 };
int dx[] = { 1,1,1 };
int ans = 0;
void go(int y, int x, int c)
{
	used[y][x] = true;
	//printf("y: %d\n", y);
	if (y == N)
	{
		//printf("temp: %d\n", c);
		if (ans < c) ans = c;
		return;
	}
	for (int dir = 0; dir < 3; dir++)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (oob(ny, nx) || used[ny][nx] ||  A[ny][nx] == 'x') continue;
		if (nx == M - 1)
		{
			go(y + 1, 0, c + 1);
			return;
		}
		else go(ny, nx, c);
	}
	go(y + 1, 0, c);
	used[y][x] = false;
}


int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf(" %c", &A[i][j]);
	go(0, 0, 0);
	printf("%d", ans);
}