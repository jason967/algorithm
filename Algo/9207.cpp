#include<cstdio>
using namespace std;

const int M = 9;
const int N = 5;
const int INF = 1e9;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

char A[5][9];

int ansM = INF;
int ansF = INF;

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}
void go(int y, int x,int move, int fin)
{
	if (fin < ansF)
	{
		ansF = fin;
		ansM = move;
	}
	else if (fin == ansF)
	{
		if (ansM > move) ansM = move;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] == '#') continue;
			else if (A[i][j] == 'o')
			{
				for (int dir = 0; dir < 4; dir++)
				{
					int ny = i + dy[dir];
					int nx = j + dx[dir];
					if (oob(ny, nx)) continue;
					if (A[ny][nx] == 'o')
					{
						int nny = ny + dy[dir];
						int nnx = nx + dx[dir];
						if (oob(nny, nnx) || A[nny][nnx] != '.') continue;
						A[i][j] = '.';
						A[ny][nx] = '.';
						A[nny][nnx] = 'o';
						go(nny, nnx, move + 1, fin - 1);
						A[i][j] = 'o';
						A[ny][nx] = 'o';
						A[nny][nnx] = '.';
					}

				}
			}
		}
	}
}
int main()
{
	int T = 0;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		int start = 0;
		ansF = INF;
		ansM = INF;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				scanf(" %c", &A[i][j]);
				if (A[i][j] == 'o') start++;
			}

		go(0, 0, 0, start);
		printf("%d %d\n", ansF, ansM);
	}
}