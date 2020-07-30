#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;
const int MAX = 100000;
int d[100001],N,K;
bool vis[100001];

int bfs()
{
	queue<int> Q;
	Q.push(N);
	d[N] = 0;
	while (!Q.empty())
	{
		int cur = Q.front();
		if (cur == K) return d[cur];
		Q.pop();
		if (cur * 2 <= MAX && d[cur * 2] == -1)
		{
			d[cur * 2] = d[cur] + 1;
			Q.push(cur * 2);
		}
		if (cur+1 <= MAX && d[cur+1] == -1)
		{
			d[cur +1] = d[cur] + 1;
			Q.push(cur +1);
		}
		if (cur-1>=0 && d[cur-1] == -1)
		{
			d[cur-1] = d[cur] + 1;
			Q.push(cur-1);
		}
	}
	return -1;
}
int main()
{
	scanf("%d %d", &N, &K);
	memset(d, -1, sizeof(d));
	printf("%d", bfs());
}