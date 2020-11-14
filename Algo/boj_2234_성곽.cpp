#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int N, M, pos, ans;
int A[51][51];

bool used[51][51];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}

int bfs(int y, int x)
{
	int cnt = 0;
	queue<pair<int, int>> Q;
	used[y][x] = true;
	Q.push({ y,x });
	while (Q.size() > 0)
	{
		int cy = Q.front().first;
		int cx = Q.front().second;
		int current = A[cy][cx];
		cnt++;
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			if ((current&(1 << i)) != 0) continue;
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (oob(ny, nx) || used[ny][nx]) continue;
			used[ny][nx] = true;
			Q.push({ ny,nx });
		}
	}
	return cnt;
}

void simulation()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int cur = A[i][j];
			for (int dir = 0; dir < 4; dir++)
			{
				if ((cur & (1 << dir)) != 0)
				{
					memset(used, false, sizeof(used));
					int nx = cur & ~(1 << dir);
					A[i][j] = nx;
					if (!used[i][j])
					{
						int temp = bfs(i, j);
						if (temp > ans) ans = temp;
					}
					A[i][j] = cur;
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) scanf("%d", &A[i][j]);
	}

	int MAX = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!used[i][j])
			{
				int temp = bfs(i, j);
				if (temp > MAX) MAX = temp;
				pos++;
			}
		}
	}
	simulation();
	printf("%d\n", pos);
	printf("%d\n", MAX);
	printf("%d\n", ans);
}