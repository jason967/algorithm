#include<cstdio>
#include<algorithm>
using namespace std;
const int INF = 987654321;
int ans = INF;
int N, M;
bool vis[10];
int digit[7] = { 1,2,3,4,5,6 };

void go(int cnt,int len)
{
	if (len < 1) return;
	if (cnt == len)
	{
		int res = len;
		int num = 0;
		for (int i = 0; i < len; i++)
		{
			num = num * 10 + digit[i];
		}
		res += abs(N - num);
		if (res < ans) ans = res;
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (vis[i]) continue;
		digit[cnt] = i;
		go(cnt + 1,len);
	}
}

int main()
{
	
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int num;
		scanf("%d", &num);
		vis[num] = true;
	}
	ans = abs(N - 100);
	int tmp = N, len = 0; 
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	go(0, len - 1);
	go(0, len);
	go(0, len + 1);
	printf("%d", ans);
}