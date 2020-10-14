#include<cstdio>
#include<queue>

using namespace std;

struct loc
{
	int cost,y,x;
};

struct compare
{
	bool operator()(loc a,loc b)
	{
		return a.cost > b.cost;
	}
};

int INF = 1e9;
int N;
int d[125][125],A[125][125];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };

bool oob(int y, int x) {
	return y < 0 || y >= N || x < 0 || x >= N;
}

void dijkstra()
{
	priority_queue<loc,vector<loc>,compare> pq;
	d[0][0] = A[0][0];
	pq.push({ d[0][0], 0, 0 });
	while (pq.size() > 0)
	{
		loc cur = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			int ncost = cur.cost + A[ny][nx];
			if (oob(ny, nx)||cur.cost>d[ny][nx]) continue;
			if (d[ny][nx] > ncost)
			{
				d[ny][nx] = ncost;
				pq.push({ ncost,ny,nx });
			}
		}
	}
}


int main()
{
	int idx = 1;
	while (1)
	{
		scanf("%d", &N);
		if (N == 0) break;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) d[i][j] = INF;
		dijkstra();
		printf("Problem %d: %d\n", idx++, d[N - 1][N - 1]);
	}
}