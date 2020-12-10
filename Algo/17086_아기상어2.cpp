#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

int N, M,ans;
int A[51][51], vis[51][51];


int dy[] = { 1,1,1,0,0,-1,-1,-1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}

int bfs(int y, int x)
{
	int dist = 101;
	memset(vis, 0, sizeof(vis));
	queue<pair<int, int>> q;
	q.push({ y,x });
	vis[y][x] = 0;
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (oob(ny, nx) || vis[ny][nx]) continue;
			vis[ny][nx] = vis[cy][cx] + 1;
			q.push({ ny,nx });
			if (A[ny][nx] == 1)
			{
				if (vis[ny][nx] < dist) dist = vis[ny][nx];
			}
		}
	}
	return dist;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] != 1)
			{
				int dist = bfs(i, j);
				if (ans < dist) ans = dist;
			}
		}
	}
	printf("%d", ans);
}