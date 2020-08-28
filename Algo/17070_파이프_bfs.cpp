#include<cstdio>
#include<queue>

using namespace std;

int A[16][16];

struct pos
{
	int  y, x, dir;
};

int N, ans;;

int dy[] = { 0,1,1 };
int dx[] = { 1,0,1 };

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= N;
}

void bfs()
{
	queue<pos> q;
	q.push({ 0,1,0 });
	while (!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		int cdir = q.front().dir;
		if (cy == N - 1 && cx == N - 1) ans++;
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (oob(ny, nx) || A[ny][nx] == 1) continue;
			if ((cdir ^ 1) == i) continue;
			if (i == 2 && (A[cy][cx + 1] == 1 || A[cy + 1][cx] == 1)) continue;
			q.push({ ny,nx,i });
		}
	}
}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
	bfs();
	printf("%d", ans);
}