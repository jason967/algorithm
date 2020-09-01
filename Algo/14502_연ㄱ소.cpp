#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

struct pos
{
	int y, x;
};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int N, M,ans,Esz;

int A[8][8], sel[8 * 8];
bool infected[8][8], used[8 * 8];

vector<pos> E;
queue<pos> Q;

bool oob(int y, int x)
{
	return y<0 || y>=N || x < 0 || x >= M;
}

int bfs()
{
	int res = 0;
	bool vis[8][8];
	memcpy(vis, infected, sizeof(vis));
	queue<pos> q = Q;
	while (!q.empty())
	{
		pos c = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = c.y + dy[i];
			int nx = c.x + dx[i];
			if (oob(ny, nx) || vis[ny][nx]) continue;
			if (A[ny][nx] == 0)
			{
				vis[ny][nx] = true;
				q.push({ ny,nx });
				res++;
			}
		}
	}
	return Esz - res-3;
}

void go(int idx, int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < 3; i++) A[E[sel[i]].y][E[sel[i]].x] ^= 1;
		int res = bfs();
		for (int i = 0; i < 3; i++) A[E[sel[i]].y][E[sel[i]].x] ^= 1;
		if (res > ans) ans = res;
		return;
	}
	for (int i = idx; i < Esz; i++)
	{
		if (used[i])continue;
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
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &A[i][j]);
			if (A[i][j] == 0) E.push_back({ i,j });
			else if (A[i][j] == 2)
			{
				Q.push({ i,j });
				infected[i][j] = true;
			}
		}
	}
	Esz = E.size();
	go(0, 0);
	printf("%d", ans);
}