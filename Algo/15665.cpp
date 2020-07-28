#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> V;
vector<vector<int>> Ans;
int A[8], N, M;
bool C[8];

void go(int cnt)
{
	if (cnt == M)
	{
		Ans.push_back(V);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		V.push_back(A[i]);
		go(cnt + 1);
		V.pop_back();
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	sort(A, A + N);
	go(0);
	sort(Ans.begin(), Ans.end());
	Ans.erase(unique(Ans.begin(), Ans.end()), Ans.end());
	for (auto x : Ans)
	{
		for (int i = 0; i < x.size(); i++) printf("%d ", x[i]);
		printf("\n");
	}

}