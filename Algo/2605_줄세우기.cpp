#include<cstdio>
#include<algorithm>

using namespace std;

struct _info
{
	int idx, num,i;
}info[101];

bool cmp(_info a, _info b)
{
	return a.idx < b.idx;
}

int N;

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		info[i].idx = i;
		info[i].i = i;
	}
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &info[i].num);
	}
	for (int i = 1; i <= N; i++)
	{
		info[i].idx -= info[i].num;
		printf("before %d %d\n", i, info[i].idx);
		for (int i = 1; i <= N; i++) printf("%d ", info[i].idx);
		printf("\n");
		for (int j = 1; j < i; j++)
		{
			if (info[j].idx >= info[i].idx)
			{
				
				info[j].idx += 1;
			}
		}
		for (int i = 1; i <= N; i++) printf("%d ", info[i].idx);
		printf("\n");
	}
	sort(info+1, info + N+1, cmp);
	for (int i = 1; i <= N; i++) printf("%d ", info[i].i);

	
}