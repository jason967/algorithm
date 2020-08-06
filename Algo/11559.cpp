#include<cstdio>
#include<vector>
#include<queue>
#define pii pair<int,int>

using namespace std;

const int N = 12;
const int M = 6;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

char A[13][7], CA[13][7];
bool vis[12][6];

int ans;

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}

void moveDown()
{
	bool ismove = false;
	for (int i = 0; i < M; i++)
	{
		for (int j = N-1; j>0; j--)
		{
			if (A[j-1][i] != '.'&&A[j][i] == '.')
			{
				ismove = true;
				swap(A[j - 1][i], A[j][i]);
			}
		}
	}
	if (ismove) moveDown();
}

bool bomb = false;

void bfs(int y, int x, char C)
{
	queue<pii> q;
	vector<pii> cluster;
	vis[y][x] = true;
	q.push({ y,x });
	cluster.push_back({ y,x });
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (oob(ny, nx) || A[ny][nx] != C || vis[ny][nx]) continue;
			vis[ny][nx] = true;
			q.push({ ny,nx });
			cluster.push_back({ ny,nx });
		}
	}
	if (cluster.size() >= 4)
	{
		for (auto p : cluster)
		{
			A[p.first][p.second] = '.';
		}
		bomb = true;
	}
	cluster.clear();
}

void solution()
{
	while (1)
	{
		bomb = false;
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (A[i][j] != '.' && !vis[i][j])
				{
					bfs(i, j, A[i][j]);
				}
			}
		}
		if (!bomb) break;
		moveDown();
		ans++;
	}

}



int main() {
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			scanf(" %c", &A[i][j]);
		}
	}
	solution();
	printf("%d", ans);

}