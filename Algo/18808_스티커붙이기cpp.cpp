#include<cstdio>
using namespace std;

struct _info
{
	int sy,ey,sx,ex;
} info[100][4];

int N, M, K;
int A[40][40];
int st[100][4][40][40];

bool oob(int y, int x)
{
	return y < 0 || y > N || x < 0 || x > M;
}

bool check(int t,int dir,int y, int x)
{
	int lenY = (info[t][dir].ey - info[t][dir].sy)+1;
	int lenX = (info[t][dir].ex - info[t][dir].sx)+1;
	
	if (oob(y + lenY , lenX + x)) return false;
	
	for (int i = y; i < y+lenY ; i++)
	{
		for (int j = x; j < x + lenX; j++)
		{
			
			if (A[i][j] == 1 && st[t][dir][i - y + info[t][dir].sy][j - x + info[t][dir].sx] == 1) return false;
		}
	}
	
	for (int i = y; i < y+lenY; i++)
	{
		for (int j = x; j < x + lenX; j++)
		{
			if (A[i][j] == 0 && st[t][dir][i - y + info[t][dir].sy][j - x + info[t][dir].sx] == 1)
				A[i][j] = 1;
		}
	}
	
	return true;
}

void solution()
{
	for (int t = 0; t < K; t++)
	{
		bool flag = true;
		for (int dir = 0; dir < 4&&flag; dir++)
		{	
			for (int i = 0; i < N && flag; i++)
			{
				for (int j = 0; j < M && flag; j++)
				{
					if (check(t, dir, i, j))
					{
						flag = false;
						break;
					}
				}
			}//도형하나
		}//방향
	}//도형
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++)
	{
		int y, x;
		scanf("%d %d", &y, &x);
		int len = y > x ? y : x;
		info[i][0] = { 0,y-1,0,x-1 };
		for (int j = 0; j < y; j++) for (int k = 0; k < x; k++) scanf("%d", &st[i][0][j][k]);
		//회전
		for (int dir = 1; dir < 4; dir++)
		{
			for (int j = 0; j < len; j++)
			{
				for (int k = 0; k < len; k++)
				{
					st[i][dir][j][k] = st[i][dir - 1][len - k - 1][j];
				}
			}
		}
		//전처리
		for (int dir = 1; dir < 4; dir++)
		{
			int sy = len, ey = 0;
			int sx = len, ex = 0;
			for (int j = 0; j < len; j++)
			{
				for (int k = 0; k < len; k++)
				{
					if (st[i][dir][j][k] == 1)
					{
						if (j < sy) sy = j;
						if (j > ey) ey = j;
						if (k < sx) sx = k;
						if (k > ex) ex = k;
					}
				}
			}
			info[i][dir] = { sy,ey,sx,ex };
		}
	}
	solution();
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) if (A[i][j] == 1) cnt++;
	}
	printf("%d", cnt);
}