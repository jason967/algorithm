#include<cstdio>	
#include<vector>
#include<queue>

using namespace std;

struct info {
	int y, x, mass, speed, d;
};

struct VInfo {
	int mass, speed, d;
};

int dy[] = { -1,-1,0,1,1,1,0,-1};
int dx[] = { 0,1,1,1,0,-1,-1,-1};

int dir[2][4] = { {1,3,5,7},{0,2,4,6} };

int N, M, K,ans;

queue<info> Q;

bool check(vector<VInfo> V)
{
	bool isEven = V[0].d %2==0 ? true : false;
	for (int i = 1; i < V.size(); i++)
	{
		if (isEven && V[i].d % 2 != 0) return false;
		if (!isEven && V[i].d % 2 == 0) return false;
	}
	return true;
}

void simulation()
{
	vector<VInfo> V[51][51];
	int qsz = Q.size();
	for (int i = 0; i < qsz; i++)
	{
		info cur = Q.front();
		Q.pop();
		int speed = cur.speed%N;
		int ny = ((cur.y + dy[cur.d] * speed) + N) % N;
		int nx = ((cur.x + dx[cur.d] * speed) + N) % N;
		V[ny][nx].push_back({ cur.mass,cur.speed,cur.d });
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (V[i][j].size() >= 2)
			{
				int VSz = V[i][j].size();
				int sumM = 0;
				int sumS = 0;
				for (int sz = 0; sz < VSz; sz++)
				{
					sumM += V[i][j][sz].mass;
					sumS += V[i][j][sz].speed;
				}
				sumS /= VSz;
				sumM /= 5;
				if (sumM == 0) continue;
				bool ret = check(V[i][j]);
				sumS %= N;				
				for (int d = 0; d < 4; d++)
				{
					Q.push({ i,j,sumM,sumS,dir[ret][d]});				
				}
			}
			else if(V[i][j].size()==1)
			{
				Q.push({ i,j,V[i][j][0].mass,V[i][j][0].speed,V[i][j][0].d });
			}
		}
	}
	
}


int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++)
	{
		int y, x, m, s, d;
		scanf("%d %d %d %d %d", &y, &x, &m, &s, &d);
		Q.push({ y-1,x-1,m,s,d });
	}

	for(int i=0;i<K;i++) simulation();
	
	while (!Q.empty())
	{
		ans += Q.front().mass;
		Q.pop();
	}
	printf("%d\n", ans);
}