#include<cstdio>
#include<algorithm>

using namespace std;

int N, M,T;
int arr[41];
int student[31][41];
int score[31];

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) scanf("%d", &arr[i]);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++) scanf("%d", &student[i][j]);
		}
		int MAX = 0;
		int MIN = 1e9;
		for (int i = 0; i < N; i++)
		{
			bool flag = false;
			int bonus = 1;
			int sum = 0;
			for (int j = 0; j < M; j++)
			{
				if (student[i][j] == arr[j])
				{
					if (flag)
					{
						bonus++;
					}
					sum += bonus;
					flag = true;
				}
				else
				{
					bonus = 1;
					flag = false;
				}
			}
			if (sum > MAX) MAX = sum;
			if (sum < MIN) MIN = sum;
		}
		printf("#%d %d\n", tc,MAX - MIN);
	}
}