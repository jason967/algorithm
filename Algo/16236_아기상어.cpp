#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#define pii pair<int,int>

using namespace std;

struct fish
{
	int y, x, dist;
};

struct shark
{
	int y, x, size,stack;
};

int N,time;
int A[20][20];

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= N;
}

bool cmp(fish a, fish b)
{
	if (a.dist == b.dist)
	{
		if (a.y == b.y) return a.x < b.x;
		return a.y < b.y;
	}
	return a.dist < b.dist;
}

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

shark baby;

bool bfs()
{
	int d[20][20];
	memset(d, -1, sizeof(d));
	queue<pii> q;
	vector<fish> F;
	d[baby.y][baby.x] = 0;
	q.push({ baby.y,baby.x });
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (oob(ny, nx) || A[ny][nx] > baby.size || d[ny][nx] != -1) continue;
			d[ny][nx] = d[cy][cx] + 1;
			q.push({ ny,nx });
			if (A[ny][nx] < baby.size && A[ny][nx]!=0)
			{
				F.push_back({ ny,nx,d[ny][nx] });
			}
		}
	}
	if (F.size() == 0) return false;
	sort(F.begin(), F.end(), cmp);
	int fy = F[0].y, fx = F[0].x;
	baby.stack += 1;
	time += F[0].dist;
	if (baby.stack == baby.size)
	{
		baby.size += 1;
		baby.stack = 0;
	}
	A[baby.y][baby.x] = 0;
	baby.y = fy;
	baby.x = fx;
	A[baby.y][baby.x] = 9;
	return true;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &A[i][j]);
			if (A[i][j] == 9) baby = { i,j,2,0 };
		}
	}
	while (bfs()){}
	printf("%d", time);
}