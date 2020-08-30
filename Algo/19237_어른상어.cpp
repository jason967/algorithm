#include<cstdio>
#include<cstring>
#include<vector>
#define pii pair<int,int>

using namespace std;

struct _shark {
	int num,y, x,dir,life;
}shark[401];

struct _sc
{
	int num, rest;
}sc[20][20];

int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,-1,1 };

int N,M,K,t;

int A[20][20];
int dir[401][4][4];

bool oob(int y, int x)
{
	return y<0 ||y>=N || x<0 || x>=N;
}

int selectDir(vector<int> &V,int num,int cdir)
{
	int ndir = cdir;
	bool flag = true;
	for (int Dir = 1; Dir <= 4 && flag; Dir++)
	{
		for (int cz = 0; cz < V.size(); cz++)
		{
			if (dir[num][cdir][Dir] == V[cz])
			{
				ndir = V[cz];
				flag = false;
				break;
			}
		}
	}
	return ndir;
}

void simulation()
{
	_sc copy_sc[20][20];
	memcpy(copy_sc, sc, sizeof(sc));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {

			if (sc[i][j].rest > 0)
			{
				copy_sc[i][j].rest--;
				if (copy_sc[i][j].rest == 0)
				{
					copy_sc[i][j].num = 0;
				}
			}
		}
	}
	for (int i = 1; i <= M; i++)
	{
		_shark s = shark[i];
		//죽은 상어는 안봄
		if (s.life == 0) continue;
		vector<int> can;
		for (int Dir = 1; Dir <= 4; Dir++)
		{
			int ny = s.y + dy[Dir];
			int nx = s.x + dx[Dir];
			if (oob(ny, nx)) continue;
			if (sc[ny][nx].rest != 0) continue;
			can.push_back(Dir);
		}
		int ndir = s.dir;
		//갈 곳이 없는 경우
		if (can.size() == 0)
		{
			for (int Dir = 1; Dir <= 4; Dir++)
			{
				int ny = s.y + dy[Dir];
				int nx = s.x + dx[Dir];
				if (oob(ny, nx)) continue;
				if (sc[ny][nx].num == i) can.push_back(Dir);
			}
			ndir = selectDir(can, i, s.dir);
			int ny = s.y + dy[ndir];
			int nx = s.x + dx[ndir];
			A[s.y][s.x] = 0;
			A[ny][nx] = i;
			shark[i] = { i,ny,nx,ndir,1 };
			copy_sc[ny][nx] = { i,K };
		}
		//갈 곳이 존재 하는 경우
		else
		{
			ndir = selectDir(can, i, s.dir);
			int ny = s.y + dy[ndir];
			int nx = s.x + dx[ndir];
			//그 자리에 상어가 존재하면
			if (A[ny][nx] != 0)
			{
				//자기보다 번호가 크면
				if (A[ny][nx] > i)
				{
					shark[A[ny][nx]].life = 0;
					A[s.y][s.x] = 0;
					A[ny][nx] = i;
					shark[i] = { i,ny,nx,ndir,1 };
					copy_sc[ny][nx] = { i,K };
				}
				else
				{
					shark[i].life = 0;
					copy_sc[s.y][s.x].num = 0;
					A[s.y][s.x] = 0;
				}
			}
			else
			{
				A[s.y][s.x] = 0;
				A[ny][nx] = i;
				shark[i] = { i,ny,nx,ndir,1 };
				copy_sc[ny][nx] = { i,K };
			}
		}
	}
	memcpy(sc, copy_sc, sizeof(sc));
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &A[i][j]);
			if (A[i][j] != 0)
			{
				shark[A[i][j]] = {A[i][j], i,j,0,1 };
				sc[i][j] = { A[i][j],K };
			}
		}
	}
	for (int i = 1; i <= M; i++) scanf("%d", &shark[i].dir);
	
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int Dir = 1; Dir <= 4; Dir++)
			{
				scanf("%d", &dir[i][j][Dir]);
			}
		}
	}
	while (1)
	{
		if (t > 1000)
		{
			t = -1;
			break;
		}
		int lived = 0;
		for (int i = 1; i <= M; i++)
		{
			if (shark[i].life == 1) lived++;
		}
		if (lived == 1) break;
		simulation();
		t++;
	}
	printf("%d", t);
}
