#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int INF = 1e9;

int N,total,ans=INF;
int A[21][21],section[21][21],population[5];

void makeSection(int y,int x,int d1,int d2)
{
	memset(section, 0, sizeof(section));
	//case 1:
	for (int i = 0; i <= d1; i++) section[y + i][x - i] = 5;
	//case 2:
	for (int i = 0; i <= d2; i++) section[y + i][x + i] = 5;
	//case 3:
	for (int i = 0; i <= d2; i++) section[y + d1 + i][x - d1 + i] = 5;
	//case 4:
	for (int i = 0; i <= d1; i++) section[y + d2 + i][x + d2 - i] = 5;
}

void fillSection(int y, int x, int d1, int d2)
{
	memset(population, 0, sizeof(population));
	population[4] = total;
	//sec 1:
	for (int i = 1; i < y + d1; i++)
	{
		for (int j = 1; j <= x; j++)
		{
			if (section[i][j] == 5) break;
			population[0] += A[i][j];
			population[4] -= A[i][j];
		}
	}
	//sec 3:
	for (int i = y+d1; i <=N; i++)
	{
		for (int j = 1; j < x-d1+d2; j++)
		{
			if (section[i][j] == 5) break;
			population[2] += A[i][j];
			population[4] -= A[i][j];
		}
	}
	//sec 2:
	for (int i = 1; i <= y+d2; i++)
	{
		for (int j = N; j > x; j--)
		{
			if (section[i][j] == 5) break;
			population[1] += A[i][j];
			population[4] -= A[i][j];
		}
	}
	//sec 4:
	for (int i = y+d2+1; i <=N ; i++)
	{
		for (int j = N; j >= x-d1+d2; j--)
		{
			if (section[i][j] == 5) break;
			population[3] += A[i][j];
			population[4] -= A[i][j];
		}
	}
	sort(population, population + 5);
	int diff = population[4] - population[0];
	if (ans > diff) ans = diff;
}


int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &A[i][j]);
			total += A[i][j];
		}
	}

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			for (int d1 = 1; d1 <= N; d1++)
			{
				for (int d2 = 1; d2 <= N; d2++)
				{
					if (y + d1 + d2 <= N && x - d1 >= 1 && x + d2 <= N)
					{					
						makeSection(y, x, d1, d2);
						fillSection(y, x, d1, d2);					
					}
				}
			}
		}
	}
	printf("%d", ans);
}