#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };

int N, M, K,ans;

int A[10][10],food[10][10],tempFood[10][10];;

vector<int> board[10][10];

bool oob(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= N;
}

void ss()
{
	//죽지 않고 살아있는 나무들을 저장할 2차원 벡터
	vector<int> temp[10][10];

	//나무가 죽으면서 양분이 되는 경우를 저장하는 배열 + 0으로 초기화
	memset(tempFood, 0, sizeof(tempFood));

	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			int sz = board[i][j].size();
			if (sz > 0)//나무가 해당 좌표에 존재하는 경우
			{
				sort(board[i][j].begin(), board[i][j].end());//어린 나무순 정렬
				for (int k = 0; k < sz; k++)
				{
					int tree = board[i][j][k];
					if (food[i][j]-tree >= 0)//식량이 존재한다면
					{						
						temp[i][j].push_back(tree + 1);//나무나이 한살 증가시켜서 저장
						food[i][j] -= tree;//식량에서 제거
					}
					else//식량이 그 만큼 존재하지 않는다면(여름역할 동시에 진행)
					{
						tempFood[i][j] += tree / 2;
					}
				}
			}
			//해당 위치의 나무과 양분을 최신화
			board[i][j] = temp[i][j];
			food[i][j] += tempFood[i][j];
		}
	}
}

void fw()
{
	//가을
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int sz = board[i][j].size();
			if ( sz> 0)
			{
				for (int k = 0; k < sz; k++)
				{
					if (board[i][j][k] % 5 == 0)
					{
						for (int dir = 0; dir < 8; dir++)
						{
							int ny = i + dy[dir], nx = j + dx[dir]; 
							if (oob(ny, nx)) continue;
							board[ny][nx].push_back(1);
						}
					}
				}
			}
		}
	}

	//겨울
	ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			food[i][j] += A[i][j];
			ans += board[i][j].size();
		}
	}
}

void oneYear()
{
	ss();
	fw();
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &A[i][j]);
			food[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int y, x, age;
		scanf("%d %d %d", &y, &x, &age);
		board[y-1][x-1].push_back(age);
	}
	for (int i = 0; i < K; i++) oneYear();
	printf("%d",ans);
}