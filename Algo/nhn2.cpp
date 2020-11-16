#include<cstdio>
#include<algorithm>

using namespace std;

int N;
int width;
int hIdx = 0;
int A[101][101],B[101];

void setUp(int day)
{
	int hi = 0;
	for (int i = 0; i < width; i++)
	{
		B[i] += A[day][i];
		if (hi < B[i])
		{
			hi = B[i];
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
				hIdx = j;
			}
		}
	}
	
	int sum = 0;
	for (int t = 0; t < N; t++)
	{	
		setUp(t);
		//¿À¸¥ÂÊ
		
		int curH = -1;
		for (int i = 0; i < width; i++)
		{
			if (i == hIdx) break;
			if (B[i] > curH) curH = B[i];
			else if (B[i] < curH)
			{
				sum += (curH - B[i]);
				B[i] = curH;
			}
		}
		curH = -1;
		//¿ÞÂÊ
		for (int i = width - 1; i > 0; i--)
		{
			if (i == hIdx) break;
			if (B[i] > curH) curH = B[i];
			else if (B[i] < curH)
			{
				sum += (curH - B[i]);
				B[i] = curH;
			}
		}
	}
	printf("%d", sum);
}