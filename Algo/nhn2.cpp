#include<cstdio>
#include<algorithm>

using namespace std;

int N;
int width;
int hIdx = 0;
int A[101][101],base[101];

void addCement(int day)
{
	int hi = 0;
	for (int i = 0; i < width; i++)
	{
		base[i] += A[day][i];
		if (hi < base[i])
		{
			hi = base[i];
			hIdx = i;
		}
	}
}

int main()
{
	scanf("%d %d",&N, &width);

	int heighest = 0;
	for (int i = 0; i < N; i++)
	{

		for (int j = 0; j < width; j++)
		{
			scanf("%d", &A[i][j]);
			if (A[i][j] > heighest) {
				heighest = A[i][j];
				//처음 제일 높은 높이 초기화
				hIdx = j;
			}
		}
	}
	
	int cement = 0;
	for (int t = 0; t < N; t++)
	{	
		addCement(t);
		//movo to right
		printf("time: %d\n", t);
		int curH = -1;
		for (int i = 0; i < width; i++)
		{
			if (i == hIdx) break;
			if (base[i] > curH) curH = base[i];
			else if (base[i] < curH)
			{
				//printf("%d %d\n", i, curH - base[i]);
				cement += (curH - base[i]);
				base[i] = curH;
			}
		}
		curH = -1;
		printf("mid\n");
		//move to left
		for (int i = width - 1; i > 0; i--)
		{
			if (i == hIdx) break;
			if (base[i] > curH) curH = base[i];
			else if (base[i] < curH)
			{
				//printf("%d %d\n", i, curH - base[i]);
				cement += (curH - base[i]);
				base[i] = curH;
			}
		}
	}
	printf("%d", cement);
}