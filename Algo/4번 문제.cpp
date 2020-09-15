#include<cstdio>
#include<queue>

using namespace std;


struct p
{
	int y, x, hand;
};

int maze[4][4] = { {0, 1, 0, 1},{0, 1, 0, 0},{0, 0, 0, 0},{1, 0, 1, 0} };
int vis[4][4];

int dy[] = { 0,1,-1,0 };
int dx[] = { 1,0,0,-1 };

int hy[] = { -1,0,0,1 };
int hx[] = { 0,1,-1,0 };

int N = 4;
int M = 4;

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}

int main()
{
	int cy = 0, cx = 0;
	int cdir = 0;
	queue<p> q;
	int dist = 0;
	q.push({ 0,0,0 });
	while (q.size() > 0)
	{
			p cur = q.front();
			q.pop();
			printf("%d %d %d\n", cur.y, cur.x, cur.hand);
			if (cur.y == N - 1 && cur.x == M - 1)
			{
				printf("%d", dist);
				break;
			}

			int nhy = cur.y + hy[cur.hand];
			int nhx = cur.x + hx[cur.hand];
			{
				if (oob(nhy, nhx) || maze[nhy][nhx] == 1)
				{
					int ny = cur.y + dy[cur.hand];
					int nx = cur.x + dx[cur.hand];
					while (oob(ny, nx) || maze[ny][nx] == 1)
					{
						if (cur.hand == 0) cur.hand = 1;
						else if (cur.hand == 1) cur.hand = 3;
						else if (cur.hand == 2) cur.hand = 0;
						else if (cur.hand == 3) cur.hand = 2;
						ny = cur.y + dy[cur.hand];
						nx = cur.x + dx[cur.hand];
					}
					q.push({ ny,nx,cur.hand });
				}
				else
				{
					if (cur.hand == 0) cur.hand = 2;
					else if (cur.hand == 1) cur.hand = 0;
					else if (cur.hand == 2) cur.hand = 3;
					else if (cur.hand == 3) cur.hand = 1;
					q.push({ nhy,nhx,cur.hand });
				}
			}
			dist++;
		}
	
}