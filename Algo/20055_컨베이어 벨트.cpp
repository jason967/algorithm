#include<cstdio>
#include<algorithm>

using namespace std;

struct box {
	int dur, on;
};

box A[202];

int N, K, time = 1;

void rotate() {
	box temp = A[N * 2];
	for (int i = N * 2; i > 1; i--)
	{
		A[i] = A[i - 1];
	}
	if (A[N].on != 0) A[N].on = 0;
	A[1] = temp;
}

bool checkBox() {
	int cnt = 0;
	for (int i = 1; i <= N * 2; i++)
	{
		if (A[i].dur == 0) cnt++;
		if (cnt >= K)return false;
	}
	return true;
}

bool simulation(int t)
{	
	rotate();
	for (int i = N - 1; i > 0; i--)
	{
		if (A[i].on != 0)
		{
			if (A[i + 1].on == 0 && A[i + 1].dur >= 1) {
				if (i + 1 != N)
				{
					A[i + 1].on = A[i].on;
				}
				A[i + 1].dur--;
				A[i].on = 0;
			}
		}
	}

	if (A[1].on == 0 && A[1].dur >= 1)
	{
		A[1].on = t;
		A[1].dur--;
	}
	
	if (!checkBox()) return false;
	return true;
}

int main() {

	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N * 2; i++) scanf("%d", &A[i].dur);

	while (simulation(time))
	{
		time++;
	}
	printf("%d", time);
}