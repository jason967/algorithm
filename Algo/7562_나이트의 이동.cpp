#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int visit[300][300];

int dy[8] = { -2,-2,-1,-1,1,1,2,2 };
int dx[8] = { 1,-1,2,-2,2,-2,1,-1 };

int I;
int cur_y, cur_x;
int fin_y, fin_x;

int bfs(int cur_y, int cur_x)
{
	queue<pair<int, int>> Q;
	Q.push({ cur_y,cur_x });
	visit[cur_y][cur_x] = 0;
	while (!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		if (y == fin_y && x == fin_x) return visit[fin_y][fin_x];

		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
			if (visit[ny][nx] != 0) continue;
			Q.push({ ny,nx });
			visit[ny][nx] = visit[y][x] + 1;
		}
	}
	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &I);
		scanf("%d %d", &cur_y, &cur_x);
		scanf("%d %d", &fin_y, &fin_x);
		printf("%d\n", bfs(cur_y, cur_x));
		memset(visit, 0, sizeof(visit));
	}
}
