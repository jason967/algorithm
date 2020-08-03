#include<cstring>
#include<queue>
#define pii pair<int,int>

using namespace std;

const int INF = 1e9;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int N, M, d[101][101],A[101][101];

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}

void bfs()
{
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) d[i][j] = INF;
	queue<pii> q;
	q.push({ 0,0 });
	d[0][0] = 0;
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (oob(ny, nx)) continue;
			if (A[ny][nx] == 1)
			{
				if (d[ny][nx] > d[cy][cx] + 1)
				{
					d[ny][nx] = d[cy][cx] + 1;
					q.push({ ny,nx });
				}
			}
			else
			{
				if (d[ny][nx] > d[cy][cx])
				{
					d[ny][nx] = d[cy][cx];
					q.push({ ny,nx });
				}
			}

		}
	}
}

int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%1d", &A[i][j]);
	bfs();
	printf("%d", d[N - 1][M - 1]);
}