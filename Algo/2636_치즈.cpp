#include<cstdio>
#include<queue>
#include<cstring>
#define pii pair<int,int>

using namespace std;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int A[100][100], CA[100][100];
int component[100][100];
bool can[10000];

int N, M;

bool oob(int y, int x)
{
	return y < 0 || y >=N || x < 0 || x >= M;
}

void air(int y, int x,int com)
{
	queue<pii> q;
	component[y][x] = com;
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
			if (oob(ny, nx)) continue;
			if (A[ny][nx]==-1)
			{
				can[com] = true;
				continue;
			}
			if (A[ny][nx] == 1 || component[ny][nx] != 0) continue;
			component[ny][nx] = com;
			q.push({ ny,nx });
		}
	}

}
	void cheeze(int y,int x)
	{
		queue<pii> q;
		component[y][x] = -1;
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
				if (component[ny][nx] == -1 || oob(ny,nx)) continue;
				else if (can[component[ny][nx]] || A[ny][nx]==-1)
				{
					A[cy][cx] = 0;
				}
				if (A[ny][nx] == 0 || A[ny][nx]==-1) continue;
				component[ny][nx] = -1;
				q.push({ ny,nx });
			}
		}
	}

	void simul()
	{
		int com = 0;
		memset(component, 0, sizeof(component));
		memset(can, false, sizeof(can));
		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < M - 1; j++)
			{
				if (A[i][j] == 0 && component[i][j] == 0)
				{
					air(i, j, ++com);
				}
			}
		}
		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < M - 1; j++)
			{
				if (A[i][j] == 1 && component[i][j] == 0)
				{
					cheeze(i, j);
				}
			}
		}
	}
	int check()
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0;j < M; j++) if (A[i][j] == 1) cnt++;
		}
		return cnt;
	}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &A[i][j]);
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) A[i][j] = -1;
		}
	}
	int ans = 0;
	int time = 0;
	while (1)
	{
		if (check() == 0)
		{
			printf("%d\n", time);
			printf("%d", ans);
			break;
		}
		ans = check();
		simul();
		time++;
	}
}