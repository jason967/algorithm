#include<cstdio>
#include<deque>
#define pii pair<int,int>
#define f(i,N) for(int i=0;i<N;i++)

using namespace std;

int N, K, L,dir,cy,cx;
char D[10001];
int A[101][101];

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

bool oob(int y, int x)
{
	return y<0 || y>=N || x < 0 || x >= N;
}

int main()
{
	deque<pii> dq;
	scanf("%d %d", &N, &K);
	f(i, K)
	{
		int y, x;
		scanf("%d %d", &y, &x);
		A[y - 1][x - 1] = 2;
	}
	scanf("%d", &L);
	f(i,L)
	{
		int t;
		char c;
		scanf("%d %c",&t,&c);
		D[t] = c;
	}
	A[0][0] = 1;
	dq.push_front({ 0,0 });
	int t = 1;
	while(1)
	{
		int ny = cy + dy[dir];
		int nx = cx + dx[dir];
		if (oob(ny, nx) || A[ny][nx]==1)
		{
			printf("%d", t);
			break;
		}
		dq.push_front({ ny,nx });
		if (A[ny][nx] == 0)
		{
			A[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		A[ny][nx] = 1;
		cy = ny, cx = nx;
		if (D[t] == 'D') dir = (dir + 1) % 4;
		else if (D[t] == 'L') dir = (dir + 3) % 4;
		t++;
	}
}