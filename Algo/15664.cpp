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
		if (C[i] || (cnt!=0&&V[cnt-1]>A[i])) continue;
		V.push_back(A[i]);
		C[i] = true;
		go(cnt + 1);
		C[i] = false;
		C[i] = false;
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