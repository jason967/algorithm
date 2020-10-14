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
		//���� ������ �Ѿ
		if (fish[fi].state == 0) continue;
		info &cur = fish[fi];
		for (int i = 0; i < 8; i++)
		{
			int ndir = (cur.dir + i) % 8;
			int ny = cur.y + dy[ndir],nx = cur.x + dx[ndir];

			//���� ������ ����ų� ����� ���
			if (oob(ny, nx) || sea[ny][nx] == -1) continue;

			if (sea[ny][nx] == 0)
			{
				//�̵� �� ĭ 0���� ��ü
				sea[cur.y][cur.x] = 0;
				//�̵� �� ĭ ����� ��ȣ�� ��ü
				sea[ny][nx] = fi;
				//����� �ֽ�ȭ
				cur = { ny,nx,ndir,1 };
				break;
			}
			else
			{
				int target = sea[ny][nx];
				//����� ���� �ֽ�ȭ
				cur.dir = ndir;
				//�ٴ��� ����� ��ġ ����
				swap(sea[ny][nx], sea[cur.y][cur.x]);
				//�� ����� ��ȯ
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
	//������ ������
	fishMove();
	memcpy(tF, fish, sizeof(fish));
	memcpy(tS, sea, sizeof(sea));
	//������ ������, ���� temp�� ����

	for (int dist = 1; dist <= 4; dist++)
	{
		int ny = y + dy[dir] * dist;
		int nx = x + dx[dir] * dist;
		//������ ����� üũ
		if (oob(ny, nx))
		{
			if (sum > ans) ans = sum;
			return;
		}
		//����Ⱑ �׾��ִ� ��� ���
		if (sea[ny][nx] == 0) continue;

		int target = sea[ny][nx];
		int ndir = fish[target].dir;

		sea[y][x] = 0;
		sea[ny][nx] = -1;
		fish[target].state = 0;

		go(ny, nx, ndir, sum+target);

		//�ٽ� �� �����̱� ������ ����(�����鸸 ������ ����)
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

	//��� ����
	sea[0][0] = -1;
	for (int i = 1; i <= 16; i++)
	{
		if (fish[i].y == 0 && fish[i].x == 0)
		{
			//����� ���
			fish[i].state = 0;
			go(0, 0, fish[i].dir,i);
			break;
		}
	}
	printf("%d", ans);
}