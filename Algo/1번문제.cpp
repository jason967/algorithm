#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

int boxes[6][2] = { {1, 2},{2, 1},{3, 3},{4, 5},{5, 6},{7, 8} };

map<int, int> mp;

int main()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)	
		{
			printf(" i: %d\n",i, mp.count(boxes[i][j]));
			if (mp.count(boxes[i][j]) != 0)
			{
				printf("here: %d\n", mp.find(boxes[i][j])->second + 1);
				mp.insert({ boxes[i][j], mp.find(boxes[i][j])->second + 1 });
				continue;
			}
			else 
				mp.insert({ boxes[i][j], 1 });
		}
	}
	int cnt = 0;
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		printf("it: %d\n", it->second);
		cnt+= (it->second) /2;
	}
	printf("%d", 6 - cnt);
}