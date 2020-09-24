#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int A[9];
bool used[9];
bool fin;
vector<int> v;
void go(int idx, int cnt,int sum)
{
	if (sum > 100) return;
	if (fin) return;
	if (cnt == 7)
	{
		if (sum == 100)
		{
			sort(v.begin(), v.end());
			for (int i = 0; i < 7; i++) printf("%d\n", v[i]);
			fin = true;
		}
		return;
	}
	for (int i = idx; i < 9; i++)
	{
		if (used[i]) continue;
		used[i] = true;
		v.push_back(A[i]);
		go(i, cnt + 1,sum+A[i]);
		v.pop_back();
		used[i] = false;
	}

}
int main()
{
	for (int i = 0; i < 9; i++) scanf("%d", &A[i]);
	go(0, 0, 0);
}