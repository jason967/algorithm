#include<cstdio>

using namespace std;

int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

int N, M, A[20][20],d[4][4],y,x,K;

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}

void ga()
{
	int temp = d[1][3];
	for (int i = 3; i > 0; i--) d[1][i] = d[1][i - 1];
	d[1][0] = temp;
	d[3][1] = d[1][3];
}

void se()
{
	int temp = d[3][1];
	for (int i = 3; i > 0; i--) d[i][1] = d[i-1][1];
	d[0][1] = temp;
	d[1][3] = d[3][1];
}

void m(int dir)
{
	if (dir == 1) ga();
	else if (dir == 2) for (int i = 0; i < 3; i++) ga();
	else if (dir == 3) se();
	else if (dir == 4) for (int i = 0; i < 3; i++) se();
}

int main()
{
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			scanf("%d", &A[i][j]);
	for (int i = 0; i < K; i++)
	{
		int dir;
		scanf("%d", &dir);
		int ny = y + dy[dir-1];
		int nx = x + dx[dir-1];
		if (oob(ny, nx)) continue;
		y = ny, x = nx;
		m(dir);
		if (A[ny][nx] != 0)
		{
			d[3][1] = A[ny][nx];
			d[1][3] = A[ny][nx];
			A[ny][nx] = 0;
		}
		else A[ny][nx] = d[3][1];
		printf("%d\n", d[1][1]);
	}
}