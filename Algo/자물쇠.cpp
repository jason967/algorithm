#include<cstdio>
#include<cstring>

using namespace std;

int OriginalLock[3][3] = { {1,1,1},{1,1,0},{1,0,1} };
int OriginalKey[3][3] = { {0,0,0},{1,0,0},{0,1,1} };

int A[60][60],CA[60][60];
int CKey[4][20][20];

int M = 3;
int N = 3;

int main()
{
	//LOCK 배열 저장
	int Locked = 0;
	int L = M + (N - 1) * 2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i + M - 1][j + M - 1] = OriginalLock[i][j];
			//if (OriginalLock[i][j] == 0) Locked++;
		}
	}
	/*for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			if (i<M - 1 || i>=M + N-1 || j<M - 1 || j>=M + N-1) A[i][j] = -1;
		}
	}*/
	//KEY 배열 회전
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++) CKey[0][i][j] = OriginalKey[i][j];
	}
	//memcpy(CKey[0], OriginalKey, sizeof(OriginalKey));
	printf("start\n");
	for (int dir = 1; dir < 4; dir++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < M; j++)
				CKey[dir][i][j] = CKey[dir - 1][M - j - 1][i];
		}
	}

	//회전된 KEY 배열 저장 완료

	for (int dir = 0; dir < 4; dir++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < M; j++)
				printf("%d ", CKey[dir][i][j]);
			printf("\n");
		}
		printf("\n");
	}

	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++) printf("%d ", A[i][j]);
		printf("\n");
	}
	printf("L: %d\n", L);
	printf("L-M+1: %d\n", L - N + 1);
	for (int y = 0; y < L-N+1; y++)
	{
		for (int x = 0; x < L-N+1; x++)
		{
		
			for (int dir = 0; dir < 4; dir++)
			{
				memcpy(CA, A, sizeof(CA));
				int cnt = 0;
				bool can = true;
				for (int i = 0; i < M && can; i++)
				{
					for (int j = 0; j < M; j++)
					{
						printf("Y: %d, X: %d\n",y+i,x+ j );
						//if (CKey[dir][i][j] == 1 && A[y + i][x + j] == 0) cnt++;
						if (CKey[dir][i][j] == 1 && A[y + i][x + j] == 1)
						{
							can = false;
							break;
						}
						CA[y + i][x + j] += CKey[dir][i][j];
					}
				}
				if (can)
				{
					for(int i=0;i<)
				}
				printf("cnt: %d\n", cnt);
				if (cnt == Locked)
				{
					printf("%d %d %d cur:%d\n", y, x, dir,A[y][x]);
					for (int i = 0; i < M; i++)
					{
						for (int j = 0; j < M; j++) printf("%d ", A[y + i][x + j]);
						printf("\n");
					}
					
					printf("true\n");
					return 0;
				}
			}
		}
	}
	printf("false\n");


	
}