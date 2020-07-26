#include<cstdio>

using namespace std;

int p[201];
int N, M,node;

int find(int n)
{
	if (p[n] == n)return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[a] = b;
}

int main()
{
	
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) p[i] = i;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			
			scanf("%d", &node);
			if (node == 1)
			{
				merge(find(i), find(j));
			}
		}
	}
	scanf("%d", &node);
	int st = find(node);
	for (int i = 1; i < M; i++)
	{
		scanf("%d", &node);
		if (st != find(node)) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}