#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#define pii pair<int,int>
using namespace std;

struct info {
	int n, y, x;
};

int H, W, N, ans;
char A[1500][1500];
int d[1500][1500];

bool cmp(info a, info b) { return a.n < b.n; }

vector<info> V;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int bfs(int s, int e)
{
	queue<pii> q;
	memset(d, -1, sizeof(d));
	d[V[s].y][V[s].x] = 0;
	q.push({ V[s].y,V[s].x });
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		if (cy == V[e].y && cx == V[e].x) return d[cy][cx];
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= H || nx < 0 || nx >= W || d[ny][nx] != -1 || A[ny][nx] == 'X') continue;
			d[ny][nx] = d[cy][cx] + 1;
			q.push({ ny,nx });
		}
	}
	return 0;
}

int main()
{
	scanf("%d %d %d", &H, &W, &N);
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			scanf(" %c", &A[i][j]);
			if (A[i][j] != '.'&&A[i][j] != 'X')
			{
				if (A[i][j] == 'S') A[i][j] = '0';
				V.push_back({ (A[i][j] - '0'), i, j });
			}
		}
	}
	sort(V.begin(), V.end(), cmp);
	for (int i = 0; i < V.size() - 1; i++)
		ans += bfs(i, i + 1);
	printf("%d", ans);
}