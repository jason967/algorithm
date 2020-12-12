#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int N, M, K,ans;

int dy[] = { -1,-1,0,1,1,1,0,-1 };
int dx[] = { 0,1,1,1,0,-1,-1,-1 };

int all[] = { 0,2,4,6 };
int none[] = { 1,3,5,7 };

struct info {
	int row,col,mass, speed,dir;
};

struct VInfo {
	int mass, dir, speed;
};

bool check(vector<VInfo> V)
{
	bool isEven = V[0].dir % 2 == 0 ? true : false;
	for (int i = 1; i < V.size(); i++)
	{
		if ((V[i].dir % 2 == 0 && !isEven) || V[i].dir % 2 != 0 && isEven) return false;
	}
	return true;
}

queue<info> Q;

void simulation()
{
	
	int temp = 0;
	vector<VInfo> V[51][51];
	int qsz = Q.size();
	for (int i = 0; i < qsz; i++)
	{
		info cur = Q.front();
		Q.pop();
		int speed = cur.speed%N;
		int ny = (cur.row + (dy[cur.dir] * speed)+N)%(N);
		int nx = (cur.col + (dx[cur.dir] * speed)+N)%(N);
		printf("%d %d\n", ny, nx);
		V[ny][nx].push_back({ cur.mass,cur.dir,cur.speed });
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (V[i][j].size() == 1) temp += V[i][j][0].mass;
			if (V[i][j].size() >= 2)
			{
				int sz = V[i][j].size();
				bool isAll = check(V[i][j]);
				int sumMass = 0;
				int sumSpeed = 0;
				for (int t = 0; t < sz; t++)
				{
					sumMass+= V[i][j][t].mass;
					sumSpeed += V[i][j][t].speed;
				}

				sumMass /= 5;
				sumSpeed /= sz;
				sumSpeed %= N;
				if (sumMass == 0) continue;

				for (int dir = 0; dir < 4; dir++)
				{
					int ndir = 0;
					if(isAll) ndir = all[dir];
					else ndir = none[dir];
					int ny = (i + (dy[ndir]*sumSpeed)+N)%(N);
					int nx = (j + (dx[ndir]*sumSpeed)+N)%(N);
					printf("->%d %d\n", ny, nx);
					int debug = 1;

					Q.push({ ny,nx,sumMass,sumSpeed,ndir });

				}				
			}
		}
	}

	printf("%d\n", temp);
	
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++)
	{
		int r, c, m, s, d;
		scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);
		Q.push({ r,c,m,s,d });
	}
	
	simulation();

	
	printf("%d", ans);
}