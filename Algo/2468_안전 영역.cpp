#include<cstdio>
#include<queue>
#include<cstring>
#define pii pair<int,int>

using namespace std;

int dy[] = { 0,0,1,-1 };
int dx[] = { -1,1,0,0 };

int N, H, ans;
int A[100][100];
bool d[100][100];
bool can[100][100];

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= N;
}

void bfs(int y,int x,int h)
{
	queue<pii> q;
	d[y][x] = true;
	q.push({ y,x });
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (oob(ny, nx) || d[ny][nx] ||!can[ny][nx]) continue;
			q.push({ ny,nx });
			d[ny][nx] = true;
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &A[i][j]);
			if (H < A[i][j])H = A[i][j];
		}
	}
	for (int h = H; h > 0; h--)
	{
		memset(d, false, sizeof(d));
		memset(can, false, sizeof(can));
		int res = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (A[i][j] >= h) can[i][j] = true;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!d[i][j] && can[i][j])
				{
					bfs(i, j,res++);
				}
			}
		}
		if (ans < res) ans = res;
	}
	printf("%d", ans);
}