#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

struct pos{int y, x;};

const int INF = 1e9;

int ans = INF;
int N, M,Vsz;

int A[50][50],d[50][50];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= N;
}

bool used[10];
int sel[10];

vector<pos> V;

int bfs(queue<pos> &Q)
{
	while (!Q.empty())
	{
		pos c = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = c.y + dy[i];
			int nx = c.x + dx[i];
			if (oob(ny, nx) || d[ny][nx] != -1 || A[ny][nx] == 1) continue;
			d[ny][nx] = d[c.y][c.x] + 1;
			Q.push({ ny,nx });
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] == 0 && d[i][j] == -1) 
				return -1;
		}
	}

	int res = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] == 0)
			{
				if (res < d[i][j]) res = d[i][j];
			}
		}
	}
	return res;
}

void go(int idx, int cnt)
{
	if (cnt == M)
	{
		memset(d, -1, sizeof(d));
		queue<pos> Q;
		for (int i = 0; i < M; i++)
		{
			pos p = V[sel[i]];
			Q.push({ p.y,p.x });
			d[p.y][p.x] = 0;
		}
		int tmp = bfs(Q);
		if (tmp != -1 && tmp < ans) ans = tmp;
		return;
	}
	for (int i = idx; i < Vsz; i++)
	{
		if (used[i]) continue;
		used[i] = true;
		sel[cnt] = i;
		go(i, cnt + 1);
		used[i] = false;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &A[i][j]);
			if (A[i][j] == 2) V.push_back({ i,j });
		}
	}
	Vsz = V.size();
	go(0, 0);
	if (ans == INF) ans = -1;
	printf("%d", ans);
}