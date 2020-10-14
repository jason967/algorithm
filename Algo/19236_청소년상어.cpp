#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

struct info {
	int y,x,dir, state;
} fish[17];

const int N = 4;

int dy[] = { -1,-1,0,1,1,1,0,-1 };
int dx[] = { 0,-1,-1,-1,0,1,1,1 };

int sea[4][4],ans;

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= N;
}

void fishMove()
{
	for (int fi = 1; fi <= 16; fi++)
	{
		//죽은 물고기면 넘어감
		if (fish[fi].state == 0) continue;
		info &cur = fish[fi];
		for (int i = 0; i < 8; i++)
		{
			int ndir = (cur.dir + i) % 8;
			int ny = cur.y + dy[ndir],nx = cur.x + dx[ndir];

			//옆이 범위를 벗어나거나 상어인 경우
			if (oob(ny, nx) || sea[ny][nx] == -1) continue;

			if (sea[ny][nx] == 0)
			{
				//이동 전 칸 0으로 교체
				sea[cur.y][cur.x] = 0;
				//이동 후 칸 물고기 번호로 교체
				sea[ny][nx] = fi;
				//물고기 최신화
				cur = { ny,nx,ndir,1 };
				break;
			}
			else
			{
				int target = sea[ny][nx];
				//물고기 방향 최신화
				cur.dir = ndir;
				//바다의 물고기 위치 변경
				swap(sea[ny][nx], sea[cur.y][cur.x]);
				//두 물고기 변환
				swap(fish[target].y, cur.y);
				swap(fish[target].x, cur.x);
				break;
			}
		}
	}
}

void go(int y, int x, int dir, int sum)
{
	info tF[17];
	int tS[4][4];
	//물고기들 움직임
	fishMove();
	memcpy(tF, fish, sizeof(fish));
	memcpy(tS, sea, sizeof(sea));
	//움직인 물고기들, 상태 temp에 저장

	for (int dist = 1; dist <= 4; dist++)
	{
		int ny = y + dy[dir] * dist;
		int nx = x + dx[dir] * dist;
		//범위를 벗어나면 체크
		if (oob(ny, nx))
		{
			if (sum > ans) ans = sum;
			return;
		}
		//물고기가 죽어있는 경우 통과
		if (sea[ny][nx] == 0) continue;

		int target = sea[ny][nx];
		int ndir = fish[target].dir;

		sea[y][x] = 0;
		sea[ny][nx] = -1;
		fish[target].state = 0;

		go(ny, nx, ndir, sum+target);

		//다시 상어가 움직이기 전으로 복귀(물고기들만 움직인 상태)
		memcpy(fish, tF, sizeof(fish));
		memcpy(sea, tS, sizeof(sea));
	}
}


int main()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num, dir;
			scanf("%d %d", &num, &dir);
			sea[i][j] = num;
			fish[num] = { i,j,dir - 1,1 };
		}
	}

	//상어 등장
	sea[0][0] = -1;
	for (int i = 1; i <= 16; i++)
	{
		if (fish[i].y == 0 && fish[i].x == 0)
		{
			//물고기 사망
			fish[i].state = 0;
			go(0, 0, fish[i].dir,i);
			break;
		}
	}
	printf("%d", ans);
}