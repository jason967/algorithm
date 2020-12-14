#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int> pq;
int N;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int t;
		scanf("%d", &t);
		pq.push(t);
		if (t == 0)
		{
			printf("%d\n", pq.top());
			pq.pop();
		}
	}
}