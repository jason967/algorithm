#include<cstdio>
#include<queue>
#include<cstring>
#define pii pair<int,int>

using namespace std;

struct guest
{
	int num,sy, sx, ey, ex,dist,life;
} g[401];

struct pos
{
	int num,y,x, dist;
};

struct _taxi
{
	int y, x,fuel;
} taxi;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int A[21][21], d[21][21];
int N, M;

struct cmp
{
	bool operator()(pos a, pos b)
	{
		if (a.dist == b.dist)
		{
			if (a.y == b.y)
			{
				return a.x > b.x;
			}
			return a.y > b.y;
		}
		return a.dist > b.dist;
	}
};

bool oob(int y, int x)
{
	return y <= 0 || y > N || x <= 0 || x > N;
}

int bfs(int state,int sy, int sx, int ey, int ex)
{
	memset(d, -1, sizeof(d));
	queue<pii> q;
	d[sy][sx] = 0;
	q.push({ sy, sx });
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		if (state==1 &&cy == ey && cx == ex)
		{
			return d[cy][cx];
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (oob(ny, nx) || A[ny][nx] == 1 || d[ny][nx] != -1) continue;
			q.push({ ny,nx });
			d[ny][nx] = d[cy][cx] + 1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d %d %d", &N, &M, &taxi.fuel);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) scanf("%d", &A[i][j]);
	scanf("%d %d", &taxi.y, &taxi.x);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d %d %d", &g[i].sy, &g[i].sx, &g[i].ey, &g[i].ex);
		g[i].life = 1;
		g[i].num = i;
	}
	while (1)
	{
		priority_queue<pos, vector<pos>, cmp> pq;
		
		//현재 택시 위치에서 가장 가까운 손님 구하기
		bfs(0,taxi.y, taxi.x,0,0);

		for (int i = 1; i <= M; i++)
		{
			if (g[i].life == 0) continue;
			pq.push({ i,g[i].sy,g[i].sx,d[g[i].sy][g[i].sx] });
		}
		
		if (pq.size() == 0)
		{
			//printf("운행 완료 끝\n");
			printf("%d", taxi.fuel);
			return 0;
		}
		int gNum = pq.top().num;

		if (d[pq.top().y][pq.top().x] == -1)
		{
			//printf("손님한테 못감 [길막혀서]\n");
			printf("-1");
			return 0;
		}
		if (pq.top().dist > taxi.fuel)
		{
			//printf("손님한테 못감 [기름 없어서]\n");
			printf("-1");
			return 0;
		}
		taxi.fuel -= pq.top().dist;
		int taxiToDest = bfs(1,g[gNum].sy, g[gNum].sx, g[gNum].ey, g[gNum].ex);
		if (d[g[gNum].ey][g[gNum].ex] == -1)
		{
			//printf("목적지까지 못감 [길막힘])\n");
			printf("-1");
			return 0;
		}
		if (taxiToDest > taxi.fuel)
		{
			//printf("목적지까지 못감 [기름없음])");
			printf("-1");
			return 0;
		}

		//택시 위치 변경 and 연료 최신화
		taxi.y = g[gNum].ey;
		taxi.x = g[gNum].ex;
		taxi.fuel -= taxiToDest;
		taxi.fuel += taxiToDest * 2;

		//gNum손님 완료
		g[gNum].life = 0;
	}
}