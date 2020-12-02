#include<cstdio>
#include<stack>

using namespace std;
stack<pair<int, int>> s;
int N, A[500001];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

	for (int i = 1; i <= N; i++)
	{
		while (!s.empty() && s.top().first < A[i])s.pop();
		if (s.empty()) printf("0 ");
		else printf("%d ", s.top().second);
		s.push({ A[i],i });
	}
}