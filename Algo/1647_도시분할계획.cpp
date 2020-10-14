#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
struct info
{
	int from,to, dist;
};
int p[100001];
int N, M;
vector<info> vill;

bool cmp(info a, info b)
{
	return a.dist < b.dist;
}

int find(int n)
{
	if (p[n] == n) return p[n];
	return p[n]=find(p[n]);
}

bool isCycle;

void merge(int a, int b)
{
	isCycle = false;
	a = find(a);
	b = find(b);
	if (a == b) return;
	isCycle = true;
	p[a] = b;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vill.push_back({ a,b,c });
		vill.push_back({ b,a,c });
	}
	for (int i = 1; i <= N; i++) p[i] = i;
	int con = 0, ans = 0;
	sort(vill.begin(), vill.end(), cmp);
	for (int i = 0; i < M; i++)
	{
		
		merge(vill[i].from, vill[i].to);
		if (isCycle)
		{
			ans += vill[i].dist;
			if (con < vill[i].dist) con = vill[i].dist;
		}
	}
	//printf("%d\n", con);
	printf("%d", ans-con);
}