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
	//���� �ʰ� ����ִ� �������� ������ 2���� ����
	vector<int> temp[10][10];

	//������ �����鼭 ����� �Ǵ� ��츦 �����ϴ� �迭 + 0���� �ʱ�ȭ
	memset(tempFood, 0, sizeof(tempFood));

	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			int sz = board[i][j].size();
			if (sz > 0)//������ �ش� ��ǥ�� �����ϴ� ���
			{
				sort(board[i][j].begin(), board[i][j].end());//� ������ ����
				for (int k = 0; k < sz; k++)
				{
					int tree = board[i][j][k];
					if (food[i][j]-tree >= 0)//�ķ��� �����Ѵٸ�
					{						
						temp[i][j].push_back(tree + 1);//�������� �ѻ� �������Ѽ� ����
						food[i][j] -= tree;//�ķ����� ����
					}
					else//�ķ��� �� ��ŭ �������� �ʴ´ٸ�(�������� ���ÿ� ����)
					{
						tempFood[i][j] += tree / 2;
					}
				}
			}
			//�ش� ��ġ�� ������ ����� �ֽ�ȭ
			board[i][j] = temp[i][j];
			food[i][j] += tempFood[i][j];
		}
	}
}

void fw()
{
	//����
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

	//�ܿ�
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