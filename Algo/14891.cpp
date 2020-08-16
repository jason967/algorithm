#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int A[4][8];
int K;

void print(int arr[4][8])
{
	printf("\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++) printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}

void rotate(int num, int dir, int arr[4][8])
{
	if (dir == 1)
	{
		int temp = arr[num][7];
		for (int i = 7; i >= 1; i--) arr[num][i] = arr[num][i - 1];
		arr[num][0] = temp;
	}
	else if (dir == -1)
	{
		int temp = arr[num][0];
		for (int i = 0; i < 7; i++) arr[num][i] = arr[num][i + 1];
		arr[num][7] = temp;
	}
}

void move(int num, int dir)
{
	int idx = 0;
	bool touch[3];
	for (int i = 0; i < 3; i++)
	{
		if (A[i][2] == A[i + 1][6]) touch[idx++] = true;
		else touch[idx++] = false;
	}
	if (num == 1)
	{
		rotate(0, dir, A);
		if (!touch[0])
		{
			rotate(1, dir*-1, A);
			if (!touch[1])
			{
				rotate(2, dir, A);
				if (!touch[2]) rotate(3, dir*-1, A);
			}
		}
	}
	else if (num == 2)
	{
		if (!touch[0]) rotate(0, dir*-1, A);
		rotate(1, dir, A);
		if (!touch[1])
		{
			rotate(2, dir*-1, A);
			if (!touch[2]) rotate(3, dir, A);
		}
	}
	else if (num == 3)
	{
		if (!touch[1])
		{
			rotate(1, dir*-1, A);
			if (!touch[0]) rotate(0, dir, A);
		}
		rotate(2, dir, A);
		if (!touch[2]) rotate(3, dir*-1, A);
	}
	else if (num == 4)
	{
		rotate(3, dir, A);
		if (!touch[2])
		{
			rotate(2, dir*-1, A);
			if (!touch[1])
			{
				rotate(1, dir, A);
				if (!touch[0]) rotate(0, dir*-1, A);
			}
		}
	}
}




int main()
{
	for (int i = 0; i < 4; i++) for (int j = 0; j < 8; j++) scanf("%1d", &A[i][j]);
	//print(A);
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int num, dir;
		scanf("%d %d", &num, &dir);
		move(num, dir);
	}
		print(A);
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		int tmp = 0;
		if (i == 0) tmp = 1;
		else if (i == 1) tmp = 2;
		else if (i == 2) tmp = 4;
		else if (i == 3) tmp = 8;
		ans += A[i][0] * tmp;
	}
	printf("%d", ans);
}