#include<cstdio>
#include<queue>

using namespace std;

int N, M, A[251][251];
bool vis[251][251];

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}

int dy[] = { 1,1,1,0,0,-1,-1,-1 };
int dx[] = { 1,0,-1,-1,1,1,0,-1 };

void bfs(int y, int x)
{
	vis[y][x] = true;
	queue<pair<int, int>> q;
	q.push({ y,x });
	while (q.size() > 0)
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (oob(ny, nx) || A[ny][nx] == 0 || vis[ny][nx]) continue;
			vis[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &A[i][j]);
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] == 1 && !vis[i][j])
			{
				cnt++;
				bfs(i, j);
			}
		}
	}
	printf("%d", cnt);
}