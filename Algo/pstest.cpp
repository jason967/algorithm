#include<cstdio>
#include<algorithm>

using namespace std;

int T, A[3];

int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		for (int i = 0; i < 3; i++) scanf("%d", &A[i]);
		int sum = 0;
		bool isAns = true;
		while (isAns)
		{
			for (int i = 0; i < 3; i++)
			{
				if (A[i] == 1) continue;
				A[i] -= 1;
				sum++;
			}
			if (sum % 7 == 6)
			{
				if (A[0] == 1 && A[1] == 1 && A[2] == 1)
				{
					printf("yes\n");
					isAns = false;
					break;
				}
				else
				{
					bool isWrong = false;
					for (int i = 0; i < 3; i++)
					{
						if (A[i] == 1)
						{
							isWrong = true;
							isAns = false;
							break;
						}
					}
					if (isWrong)
					{
						printf("no\n");
						isAns = false;
						break;
					}
					else
					{
						for (int i = 0; i < 3; i++)
						{
							A[i]--;
						}
					}
				}
			}
			else
			{
				if (A[0] == 1 && A[1] == 1 && A[2] == 1)
				{
					printf("no\n");
					break;
				}
			}
		}
	}
}