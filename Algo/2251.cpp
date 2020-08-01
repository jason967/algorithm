#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define f(i,N) for(int i=0;i<N;i++)

using namespace std;

struct sz
{
	int A, B, C;
};

vector<int> V;

int bk[3];
bool v[201][201][201];

int df[] = { 2,2,0,0,1,1 };
int dt[] = { 0,1,1,2,0,2, };

void bfs()
{
	queue<sz> Q;
	v[0][0][bk[2]] = true;
	Q.push({ 0,0,bk[2] });
	int nx[3];

	while (!Q.empty())
	{
		sz cur = Q.front();
		Q.pop();
		if (cur.A == 0) V.push_back(cur.C);
		f(i, 6)
		{
			int nx[3] = { cur.A,cur.B,cur.C };
			int fr = df[i], to = dt[i];
			if (nx[fr] + nx[to] >= bk[to])
			{
				int rest = nx[fr] + nx[to] - bk[to];
				nx[to] = bk[to];
				nx[fr] = rest;
			}
			else
			{
				nx[to] += nx[fr];
				nx[fr] = 0;
			}
			if (v[nx[0]][nx[1]][nx[2]]) continue;
			v[nx[0]][nx[1]][nx[2]] = true;
			Q.push({ nx[0],nx[1],nx[2] });
		}
	}

}


int main()
{
	scanf("%d %d %d", &bk[0], &bk[1], &bk[2]);
	bfs();
	sort(V.begin(), V.end());
	f(i, V.size()) printf("%d ", V[i]);
}