#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

int N, M;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int A[1001][1001], d[1001][1001][2];

struct info {
	int y, x, w;
};

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}

void bfs()
{
	queue<info> q;
	memset(d, -1, sizeof(d));
	d[0][0][0] = 1;
	q.push({ 0,0,0 });
	while (!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		int cw = q.front().w;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (oob(ny, nx)|| d[ny][nx][cw] != -1) continue;
			if (A[ny][nx] == 0)
			{
				d[ny][nx][cw] = d[cy][cx][cw] + 1;
				q.push({ ny,nx,cw });
			}
			else if (A[ny][nx] == 1)
			{
				if (cw == 0)
				{
					d[ny][nx][1] = d[cy][cx][cw] + 1;
					q.push({ ny,nx,1 });
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%1d", &A[i][j]);
	bfs();
	int a = d[N - 1][M - 1][0];
	int b = d[N - 1][M - 1][1];
	if (a == -1 && b == -1) printf("-1");
	else if (a == -1 && b != -1) printf("%d", b);
	else if (a != -1 && b == -1) printf("%d", a);
	else
	{
		if (a < b) printf("%d", a);
		else printf("%d", b);
	}
}