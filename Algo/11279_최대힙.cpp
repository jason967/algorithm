#include<iostream>
#include<string>
#include<set>
#include<cstring>

using namespace std;

int n, m;
int A[10];
char combA[10];
int order[7];
bool used[7];
bool usedP[7];

set<string> s;




void go(int idx, int point, int len, string str)
{
	if (len == n)
	{

		s.insert(str);
		cout << str << '\n';
		return;
	}

	if (idx == order[point])
	{
		go(idx + 1, point + 1, len + 1, str +combA[point]);
	}

	else
	{
		for (int i = 0; i <= 9; i++)
		{
			go(idx + 1, point, len + 1, str + to_string(i));
		}
	}
}

void comb(int cnt,int idx)
{
	if (cnt == m)
	{
		go(0, 0, 0, "");

		return;
	}
	for (int i = idx; i < n; i++)
	{
		if (used[i]) continue;
		order[cnt] = i;
		used[i] = true;
		comb(cnt + 1,i);
		used[i] = false;
	}
}
void perm(int cnt)
{
	if (cnt == n)
	{
		comb(0, 0);

		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (usedP[i])continue;
		usedP[i] = true;
		combA[cnt] = A[i]+'0';
		perm(cnt + 1);
		usedP[i] = false;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> A[i];
	}
	memset(order, -1, sizeof(order));
	comb(0,0);
	cout << "ans: " << s.size();
}