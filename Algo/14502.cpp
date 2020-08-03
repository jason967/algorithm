#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define pii pair<int,int>

using namespace std;

int N, M, A[8][8];
int sel[3] ,Wsize,ans;
bool vis[8][8], used[64];

vector<pii> W;
queue<pii> V;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

bool oob(int y, int x)
{
	return y < 0 || y >= N || x<0 || x>=M;
}

int bfs()
{
	
	memset(vis, false, sizeof(vis));
	queue<pii> q = V;
	int safe = 0;
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (oob(ny, nx) || vis[ny][nx]||A[ny][nx]==1) continue;
			vis[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			if (!vis[i][j] && A[i][j] == 0) safe++;
	}
	return safe;
}

void go(int idx,int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < 3; i++)
			A[W[sel[i]].first][W[sel[i]].second] = 1;
		int temp = bfs();
		if (ans < temp) ans = temp;
		for (int i = 0; i < 3; i++)
			A[W[sel[i]].first][W[sel[i]].second] = 0;
		return;
	}
	for (int i = idx; i < Wsize; i++)
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
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &A[i][j]);
			if (A[i][j] == 0) W.push_back({ i,j });
			else if (A[i][j] == 2) V.push({ i,j });
		}
	}
	Wsize = W.size();
	go(0, 0);
	printf("%d", ans);
}