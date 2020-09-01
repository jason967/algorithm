#include<cstdio>

using namespace std;

int A[500][500], d[500][500];
int N,ans;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= N;
}

int dfs(int y,int x)
{
	if (d[y][x] != 0) return d[y][x];
	d[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (oob(ny, nx)) continue;
		if (A[y][x] < A[ny][nx])
		{
			int res = dfs(ny, nx)+1;
			if (res > d[y][x]) d[y][x] = res;
		}
	}
	if (ans < d[y][x]) ans = d[y][x];
	return d[y][x];
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (d[i][j] == 0)
			{
				dfs(i, j);
			}
		}
	}
	printf("%d", ans);
}