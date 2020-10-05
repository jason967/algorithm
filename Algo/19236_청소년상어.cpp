#include<cstdio>
#include<algorithm>
using namespace std;

struct info
{
	int y, x,dir,state;
};

int dy[] = { -1,-1,0,1,1,1,0,-1 };
int dx[] = { 0,-1,-1,-1,0,1,1,1 };

bool oob(int y, int x)
{
	return y < 0 || y >= 4 || x < 0 || x >= 4;
}

info fish[17];
int sea[4][4];
int ans;

void moveFish(info arr[17], int board[4][4])
{
	for (int i = 1; i <= 16; i++)
	{
		if (arr[i].state == 0 || arr[i].state == 2) continue;
		int fy = arr[i].y, fx = arr[i].x;
		int fdir = arr[i].dir;
		int nfy = fy + dy[fdir], nfx = fx + dx[fdir];
		int target = board[nfy][nfx];
		
		if (!oob(nfy, nfx) && board[nfy][nfx] >= 0)
		{
			if (arr[target].state == 2) continue;
			swap(board[nfy][nfx], board[fy][fx]);
			swap(arr[i].y, arr[target].y);
			swap(arr[i].x, arr[target].x);
			continue;
		}
		
		for (int j = 1; j < 8; j++)
		{
			int ndir = (fdir + j) % 8;
			nfy = fy + dy[ndir], nfx = fx + dx[ndir];
			target = board[nfy][nfx];
			if (!oob(nfy, nfx) && board[nfy][nfx] >= 0 && arr[target].state != 2)
			{
				arr[i].dir = ndir;
				swap(board[nfy][nfx], board[fy][fx]);
				swap(arr[i].y, arr[target].y);
				swap(arr[i].x, arr[target].x);
				break;
			}
		}
		
	}
	
}

void go(int y, int x,int sum)
{
	
	int sdir = 0, cur = 0;;
	for (int i = 1; i <= 16; i++)
	{
		if (fish[i].state == 2)
		{
			y = fish[i].y, x = fish[i].x;
			sdir = fish[i].dir;
			cur = i;
		}
	}
	//printf("cur: %d, y: %d, x: %d dir: %d\n", cur, y, x,sdir);
	for (int i = 1; i <= 4; i++)
	{
		int ny = y + dy[sdir] * i;
		int nx = x + dx[sdir] * i;
		int copySea[4][4];
		info copyFish[17];
		memcpy(copyFish, fish, sizeof(fish));
		memcpy(copySea, sea, sizeof(sea));
		//물고기 이동
		moveFish(fish, sea);
		printf("fishmove\n");
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) printf("%d ", sea[i][j]);
			printf("\n");
		}
		printf("\n");
		if (sea[ny][nx] == 0) continue;
		if (oob(ny, nx))
		{
			printf(" (%d %d) temp: %d\n",ny,nx ,sum);
			if (sum > ans) ans = sum;
			return;
		}
		//선택된 물고기
		int target = sea[ny][nx];
		//상어위치->물고기 죽은 상태인 0으로 교체
		//sea[y][x] = 0;
		//움직인 위치-> 상어위치
		sea[ny][nx] = 0;//맵에 상어 배치
		fish[cur].state = 0;
		fish[target].state = 2;
		//printf("len%d,(%d,%d), %d %d sum:%d\n",i,ny,nx, fish[cur].state, fish[target].state,sum+target);
		go(ny, nx, sum + target);
		memcpy(fish, copyFish, sizeof(fish));
		memcpy(sea, copySea, sizeof(sea));
	}
}



int total;

int main()
{
	int idx = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			fish[a] = { i,j,b-1,1 };
			sea[i][j] = a;
		}
	}
	for (int i = 1; i <= 16; i++)
	{
		if (fish[i].y == 0 && fish[i].x == 0)
		{
			total = sea[fish[i].y][fish[i].x];
			fish[i].state = 2;
			sea[fish[i].y][fish[i].x] = 0;
			break;
		}
	}
	printf("start\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) printf("%d ", sea[i][j]);
		printf("\n");
	}
	printf("\n");
	go(0, 0, total);
	printf("ans: %d", ans);
}

