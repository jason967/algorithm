#include<cstdio>
#include<queue>
#include<cstring>
#define pii pair<int,int>

using namespace std;

int N, T,ans;
int INF = 1e9;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,1,-1 };

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= N;
}

int A[20][20], d[20][20];

int bfs(int y, int x,int start)
{
	memset(d, -1, sizeof(d));
	int res = start;
	queue<pii> q;
	d[y][x] = 0;
	q.push({ y,x });
	while (q.size() > 0)
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (oob(ny, nx) || d[ny][nx] != -1) continue;
			d[ny][nx] = d[cy][cx] + 1;
			q.push({ ny,nx });
			if (A[ny][nx] == 1) res += d[ny][nx];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) printf("%d ", d[i][j]);
		printf("\n");
	}
	return res;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] >= 2)
			{
				int temp = bfs(i, j, A[i][j]);
				printf("%d\n", temp);

			}
		}
	}
}