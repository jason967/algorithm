#include<cstdio>
#include<stack>
#define ll long long
using namespace std;

int A[80000],N;
stack<ll> s;
ll ans;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	for (int i = 0; i < N; i++)
	{
		while (1)
		{
			if (s.size() == 0) break;
			if (s.top() > A[i]) break;
			s.pop();
		}
		ans += s.size();
		s.push(A[i]);
	}
	printf("%lld", ans);
}