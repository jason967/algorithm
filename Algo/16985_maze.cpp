#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

const int N = 5;
struct info
{
	int y, x, z;
};

int A[5][4][5][5];//∆«,πÊ«‚,y,x
int Set[5][5][5];

bool used[5];
int pan[5], Dir[5];

int dy[] = { 0,0,1,-1,0,0 };
int dx[] = { 0,0,0,0,1,-1 };
int dz[] = { 1,-1,0,0,0,0 };

int ans = 1e9;

bool oob(int y, int x, int z)
{
	return y < 0 || y >= N || x < 0 || x >= N || z < 0 || z >= N;
}

int bfs()
{
	int d[5][5][5];
	memset(d, -1, sizeof(d));
	queue<info> q;
	q.push({ 0,0,0 });
	d[0][0][0] = 0;
	while (!q.empty())
	{
		info c = q.front();
		q.pop();
		if (c.y == 4 && c.x == 4 && c.z == 4) return d[4][4][4];
		for (int i = 0; i < 6; i++)
		{
			int ny = c.y + dy[i];
			int nx = c.x + dx[i];
			int nz = c.z + dz[i];
			if (oob(ny, nx, nz) || Set[ny][nx][nz] == 0 || d[ny][nx][nz]!=-1) continue;
			d[ny][nx][nz] = d[c.y][c.x][c.z] + 1;
			q.push({ ny,nx,nz });
		}
	}
	return -1;
}

void print(int arr[5][5][5])
{
	printf("\n");
	for (int k = 0; k < 5; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++) printf("%d ", arr[k][i][j]);
			printf("\n");
		}
	}
	printf("\n");
}

void setDir(int cnt)
{
	if (cnt == 5)
	{
		//pan setting
		for (int k = 0; k < 5; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++) Set[k][i][j] = A[pan[k]][Dir[k]][i][j];
			}
		}
		if (Set[0][0][0] == 0 || Set[4][4][4] == 0) return;
		int res = bfs();
		if (res != -1) if (ans > res) ans = res;
		
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		Dir[cnt] = i;
		setDir(cnt + 1);
	}
}
void setPan(int cnt)
{
	if (cnt == 5)
	{
		setDir(0);
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		if (used[i]) continue;
		used[i] = true;
		pan[cnt] = i;
		setPan(cnt + 1);
		used[i] = false;
	}
}

int main()
{
	for (int k = 0; k < 5; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &A[k][0][i][j]);
	for (int k = 0; k < 5; k++)
	{
		for (int dir = 0; dir <3; dir++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
					A[k][dir+1][i][j] = A[k][dir][N - 1 - j][i];
			}
		}
	}
	setPan(0);
	if (ans == 1e9) ans = -1;
	printf("%d", ans);
}