#include<cstdio>

using namespace std;

int A[16][16];
bool vis[16][16];

int N;

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= N;
}

int ans;

int dy[] = { 0,1,1 };
int dx[] = { 1,0,1 };

void go(int y,int x,int dir)
{
	if (y == N - 1 && x == N - 1)
	{
		ans++;
		return;
	}
	
	for (int i = 0; i < 3; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (dir == 0 && i == 1) continue;
		if (dir == 1 && i == 0) continue;
		if (oob(ny, nx) || A[ny][nx] == 1 || vis[ny][nx]) continue;
		if (i == 2 && (A[y][x + 1] == 1 || A[y + 1][x] == 1)) continue;
		vis[ny][nx] = true;
		go(ny, nx, i);
		vis[ny][nx] = false;
	}
}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
	vis[0][0] = true;
	vis[0][1] = true;
	go(0, 1, 0);
	printf("%d", ans);
}