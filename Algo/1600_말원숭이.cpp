#include<cstdio>
#include<queue>

using namespace std;

struct mon
{
	int y, x, k,cost;
};

int hx[] = { 1,2,2,1,-1,-2,-2,-1,1,-1,0,0 };
int hy[] = { -2,-1,1,2,-2,-1,1,2,0,0,1,-1 };

int A[200][200];
bool vis[200][200][30];
int N, M, K;

bool oob(int y, int x) {return y < 0 || y >= N || x < 0 || x >= M;}

int bfs()
{
	queue<mon> q;
	q.push({ 0,0,0,0 });
	vis[0][0][0] = true;
	while (!q.empty())
	{
		mon c=q.front();
		q.pop();
		if (c.y == N - 1 && c.x == M - 1) return c.cost;
		for (int i = 0; i < 12; i++)
		{
			int ny = c.y + hy[i];
			int nx = c.x + hx[i];
			int nk = c.k;
			if (i < 8)
			{
				if (c.k >= K) continue;
				nk = c.k + 1;
			}
			if (oob(ny, nx)||A[ny][nx]==1||vis[ny][nx][nk]) continue;
			vis[ny][nx][nk] = true;
			q.push({ ny,nx,nk,c.cost+1 });
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d %d", &K, &M, &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &A[i][j]);
	printf("%d",bfs());
}