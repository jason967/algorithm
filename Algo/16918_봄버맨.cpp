#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int R, C, N;
char A[201][201];
char CA[201][201];
int B[200][200];
int CB[200][200];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void check() { for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if (B[i][j] != 0) B[i][j]--; }
void setup()
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (A[i][j] == '.') A[i][j] = 'O';
			if (B[i][j] == 0) B[i][j] = 3;
		}
}
void boom()
{
	memcpy(CA, A, sizeof(A));
	memcpy(CB, B, sizeof(B));
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (A[i][j] == 'O'&&B[i][j] == 0)
			{
				CA[i][j] = '.';
				CB[i][j] = 0;
				for (int dir = 0; dir < 4; dir++)
				{
					int ny = i + dy[dir];
					int nx = j + dx[dir];
					if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
					CA[ny][nx] = '.';
					CB[ny][nx] = 0;
				}
			}
		}
	memcpy(A, CA, sizeof(A));
	memcpy(B, CB, sizeof(B));
}
int main()
{
	scanf("%d %d %d", &R, &C, &N);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			scanf(" %c", &A[i][j]);
			if (A[i][j] == 'O') B[i][j] = 3;
		}
	for (int t = 1; t <= N; t++)
	{
		if (t == 1) check();
		if (t % 2 == 0)
		{
			check();
			setup();
		}
		else if (t % 2 != 0 && t != 1)
		{
			check();
			boom();
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++) printf("%c", A[i][j]);
		printf("\n");
	}
}