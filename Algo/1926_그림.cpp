#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct Node
{
	int y, x;
};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int N, M,ans;

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}

int A[501][501];
bool used[501][501];

Node queue[250001];

int bfs(int y, int x)
{
	int cnt = 1;
	memset(queue, 0, sizeof(queue));
	int head = 0, tail = 1;
	queue[0] = { y,x };
	used[y][x] = true;
	while (head != tail)
	{
		Node now = queue[head++];
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (oob(ny, nx) || used[ny][nx]||A[ny][nx]!=1) continue;
			used[ny][nx] = true;
			queue[tail++] = { ny,nx };
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	int cnt = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &A[i][j]);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!used[i][j] && A[i][j]==1)
			{
				int ret = bfs(i, j);
				if (ans < ret) ans = ret;
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	printf("%d",ans);
}
