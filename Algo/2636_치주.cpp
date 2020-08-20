#include<cstdio>
#include<cstring>
#include<queue>

#define pii pair<int,int>
using namespace std;

int N, M,A[100][100],CA[100][100],d[100][100];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
bool fin;

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}

bool check(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (oob(ny, nx)) continue;
		if (A[ny][nx] == 0) return true;
	} 
	return false;
}


void melt()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] == 1)
			{
				if (check(i, j)) CA[i][j] = 0;
			}
		}
	}
}

void bfs(int y, int x,int com)
{
	queue<pii> q;
	q.push({ y,x });
	d[y][x] = com;
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (oob(ny, nx)) continue;
			if (A[ny][nx] == 1 || d[ny][nx] != 0) continue;
			d[ny][nx] = com;
			q.push({ ny,nx });
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &A[i][j]);
	int year = 0;
	int ans = 0;
	int com = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] == 0 && d[i][j] == 0)
			{
				bfs(i, j,com++);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) printf("%d ", d[i][j]);
		printf("\n");
	}
	/*while (1)
	{
		bool fin = true;
		memcpy(CA, A, sizeof(A));
		melt();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++) if (CA[i][j] == 1)
			{
				fin = false;
				break;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)printf("%d ", CA[i][j]);
			printf("\n");
		}
		printf("\n");
		year++;
		if (fin)
		{
			for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (A[i][j] == 1) ans++;
			break;
		}
		memcpy(A, CA, sizeof(A));
	}
	printf("%d\n", year);
	printf("%d\n", ans);*/
}