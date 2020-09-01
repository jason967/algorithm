#include<cstdio>
#include<cstring>
using namespace std;

int N, M, H;
int A[31][11];
bool isSet;
bool check()
{
	for (int i = 1; i <= N; i++)
	{
		int idx = i;
		for (int j = 1; j <= H; j++)
		{
			if (idx - 1 < 0 || idx  > N) continue;
			if (A[j][idx - 1] == 1) idx--;
			else if (A[j][idx] == 1) idx++;
		}
		if (idx != i)return false;
	}
	return true;
}

void makeLadder(int y,int x,int cnt,int target)
{
	if (isSet) return;
	if (cnt == target)
	{
		/*printf("cnt: %d\n", cnt);
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= N; j++) printf("%d ", A[i][j]);
			printf("\n");
		}
		printf("\n");*/
		if (check()) isSet = true;
		return;
	}
	for (int i = y; i <= H; i++)
	{
		for (int j = x; j <= N; j++)
		{
			int px = j - 1;
			int nx = j + 1;
			if (A[i][j]==1 ||px < 0 || nx > N || A[i][px] == 1 || A[i][nx] == 1) continue;
			A[i][j] = 1;
			makeLadder(i,j,cnt + 1, target);
			A[i][j] = 0;
		}
		x = 1;
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &H);
	for (int i = 0; i < M; i++)
	{
		int y, x;
		scanf("%d %d", &y, &x);
		A[y][x] = 1;
	}
	
	for (int i = 0; i <= 3; i++)
	{
		makeLadder(1,1,0, i);
		if (isSet)
		{
			printf("%d", i);
			return 0;
		}
	}
	if (!isSet) printf("-1");
}