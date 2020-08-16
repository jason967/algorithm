#include<cstdio>
#include<cstring>

using namespace std;

struct coord
{
	int x, y, d;
};

int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

bool used[101][101];
coord pos[1024];

bool oob(int x, int y)
{
	return x < 0 || x>100 || y < 0 || y>100;
}

void curve(int x, int y, int d, int gen)
{
	pos[0] = { x,y,-1 };
	pos[1] = { x + dx[d],y + dy[d] ,d };
	for (int i = 1; i <= gen; i++)
	{
		int s = (1 << (i - 1));
		int e = (1 << i);
		for (int j = s + 1; j <= e; j++)
		{
			pos[j] = { pos[j - 1].x + dx[(pos[e - j + 1].d + 1) % 4], pos[j - 1].y + dy[(pos[e - j + 1].d + 1) % 4], (pos[e - j + 1].d + 1) % 4 };
		}
	}
	for (int i = 0; i <= (1<<gen); i++)
	{
		if (oob(pos[i].x, pos[i].y)) continue;
		used[pos[i].x][pos[i].y] = true;
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		curve(x, y, d, g);
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (used[i][j] && used[i + 1][j] && used[i][j + 1] && used[i + 1][j + 1]) ans++;
		}
	}
	printf("%d", ans);
}