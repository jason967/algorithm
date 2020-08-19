#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

int N;
int d[51][11];
bool used[10];
int ans;
int ts[10] = { 1,2,4,0,3,5,8,6,7 };

void simulation()
{
	int ta = 0;
	int score = 0;
	for (int inn = 0; inn < N; inn++)
	{
		int out = 0;
		printf("new INN ta: %d\n", ta);
		queue<int> plate;
		for (int i = 0; i < 3; i++) plate.push(0);
		while (1)
		{
			int res = d[inn][ts[ta]];
			printf("ts: %d res: %d\n", ts[ta],res);
			printf("back: %d\n", plate.back());
			if (res == 0)
			{
				ta++;
				if (ta == 9) ta = 0;
				out++;
				if (out == 3) break;
			}//아웃
			
			else if (res == 1) //안타
			{
				plate.push(1);
				//printf("sz: %d\n", plate.size());
				score += plate.back();
				plate.pop();
				ta++;
				if (ta == 9) ta = 0;
			}
			else if (res == 2)//2루타
			{
				plate.push(0);
				plate.push(1);
				for (int i = 0; i < 2; i++)
				{
					score += plate.back();
					plate.pop();
				}
				ta++;
				if (ta == 9) ta = 0;
			}
			else if (res == 3)//3루타
			{
				plate.push(0);
				plate.push(0);
				plate.push(1);
				for (int i = 0; i < 3; i++) {
					score += plate.back();
					plate.pop();
				}
				ta++;
				if (ta == 9) ta = 0;
			}
			else if (res == 4)//홈런
			{
				printf("B: score:%d\n", score);
				score++;
				for (int i = 0; i < 3; i++)
				{
					score += plate.back();
					plate.pop();
				}
				for (int i = 0; i < 3; i++) plate.push(0);
				ta++;
				if (ta == 9) ta = 0;
				printf("A: score:%d\n", score);
			}
		}
		//ta++;
		//if (ta == 9) ta = 0;
	}
	if (ans < score) ans = score;
	printf("%d\n", score);
}

void go(int cnt)
{
	if (cnt == 3)
	{
		go(cnt + 1);
		return;
	}
	if (cnt == 9)
	{
		for (int i = 0; i < 9; i++) printf("%d ", ts[i]);
		printf("\n");
		simulation();
		return;
	}
	for (int i = 1; i < 9; i++)
	{
		if (used[i]) continue;
		used[i] = true;
		ts[cnt] = i;
		go(cnt + 1);
		used[i] = false;
	}
}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 9; j++) scanf("%d", &d[i][j]);
	}
	//used[3] = true;
	//ts[3] = 0;
	//go(0);
	simulation();
	printf("ans: %d", ans);
}