#include<cstdio>
#include<cstring>
#include<queue>
#define pii pair<int,int>

using namespace std;

int N, M;
int A[300][300],CA[300][300];
bool vis[300][300];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}

void bfs(int y, int x)
{
	queue<pii> q;
	vis[y][x] = true;
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
			if (oob(ny, nx) || vis[ny][nx] || A[ny][nx] == 0) continue;
			vis[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}

bool check()
{
	memset(vis, false, sizeof(vis));
	int cnt = 0;
	bool div = true;
	for (int i = 1; i < N-1&&div; i++)
	{
		for (int j = 1; j < M-1; j++)
		{
			if (A[i][j] != 0 && !vis[i][j])
			{
				bfs(i, j);
				cnt++;
				if (cnt == 2)
				{
					div = false;
					break;
				}
			}
		}
	}
	return div;
}

void melt()
{
	memcpy(CA, A, sizeof(A));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] == 0) continue;
			int num = 0;
			for (int dir = 0; dir < 4; dir++)
			{
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				if (oob(ny, nx)) continue;
				if (A[ny][nx] == 0) num++;
			}
			CA[i][j] -= num;
			if (CA[i][j] < 0) CA[i][j] = 0;
		}
	}
	memcpy(A, CA,sizeof(A));
}


int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &A[i][j]);
	int t = 0;
	while (1)
	{
		bool state = check();
		if (!state)break;
		melt();
		bool chk = true;
		for (int i = 0; i < N&&chk; i++)
			for (int j = 0; j < M; j++)
			{
				if (A[i][j] != 0)
				{
					chk = false;
					break;
				}
			}
		
		if (chk&&state)
		{
			t = 0;
			break;
		}
		t++;
	}
	printf("%d", t);
}