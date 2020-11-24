#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct info { int y, x, z; };
int A[5][5][5];
int CA[5][5][5];

bool used[5];

int sel[5], di[5];

int y[] = { 0,0,4,4 };
int x[] = { 0,4,0,4 };

int dy[] = { 0,0,1,-1,0,0 };
int dx[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int dist[5][5][5];
int ans = 987654321;

bool oob(int y, int x, int z)
{
	if ((y < 0 || y >= 5) || (x < 0 || x >= 5) || (z < 0 || z >= 5)) return false;
	return true;
}

void ro(int arr[5][5][5], int f, int cnt)
{
	int temp[5][5];
	memcpy(temp, arr[f], sizeof(temp));
	for (int r = 0; r < cnt; r++) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) temp[i][j] = arr[f][5 - j - 1][i];
		memcpy(arr[f], temp, sizeof(temp));
	}
}

int loc(int d)
{
	if (d == 0) return 3;
	else if (d == 1) return 2;
	else if (d == 2) return 1;
	else if (d == 3) return 0;
}

bool check(int a)
{
	if (CA[4][y[loc(a)]][x[loc(a)]] == 1) return true;
	return false;
}


int bfs(int sy, int sx, int ey, int ex)
{
	memset(dist, -1, sizeof(dist));
	queue<info> Q;
	dist[0][sy][sx] = 0;
	Q.push({ sy,sx,0 });
	while (!Q.empty())
	{
		int cy = Q.front().y;
		int cx = Q.front().x;
		int cz = Q.front().z;
		if (cz == 4 && cy == ey && cx == ex) return dist[4][cy][cx];
		Q.pop();
		for (int i = 0; i < 6; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nz = cz + dz[i];
			if (!oob(ny, nx, nz)) continue;
			if (dist[nz][ny][nx] != -1 || CA[nz][ny][nx] != 1) continue;
			dist[nz][ny][nx] = dist[cz][cy][cx] + 1;
			Q.push({ ny,nx,nz });
		}
	}
	return -1;
}


void go2(int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < 5; i++) ro(CA, i, sel[i]);
		for (int i = 0; i < 4; i++)
		{
			if (CA[0][y[i]][x[i]] == 0) continue;
			if (check(i))
			{
				int res = bfs(y[i], x[i], y[loc(i)], x[loc(i)]);
				if (res != -1) if (ans > res) ans = res;
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		sel[cnt] = i;
		go2(cnt + 1);
	}
}



void go1(int cnt)
{
	if (cnt == 5)
	{
		for (int k = 0; k < 5; k++) for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) CA[k][i][j] = A[di[k]][i][j];
		go2(0);
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		if (used[i]) continue;
		di[cnt] = i;
		used[i] = true;
		go1(cnt + 1);
		used[i] = false;
	}
}



int main()
{
	for (int k = 0; k < 5; k++) for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) scanf("%d", &A[k][i][j]);
	go1(0);
	if (ans == 987654321) ans = -1;
	printf("%d", ans);
}