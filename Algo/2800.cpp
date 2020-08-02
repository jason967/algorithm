#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>

using namespace std;

string S;

stack<int> st;
vector<pair<int, int>> v;
vector<string> ans;

bool c[11];
int val[11],sz;

void go(int idx,int cnt,int len)
{
	if (cnt == len)
	{	
		string str = S;
		for (int i = 0; i < len; i++)
		{
			str.replace(v[val[i]].first, 1, " ");
			str.replace(v[val[i]].second, 1, " ");
		}
		str.erase(remove(str.begin(), str.end(), ' '), str.end());
		ans.push_back(str);
		return;
	}
	for (int i = idx; i < sz; i++)
	{
		if (c[i]) continue;
		c[i] = true;
		val[cnt] = i;
		go(i, cnt + 1, len);
		c[i] = false;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> S;
	
	for (int i=0;i<S.length();i++)
	{
		if (S[i] == '(') st.push(i);
		else if (S[i] == ')')
		{
			v.push_back({ st.top(),i });
			st.pop();
		}
	}
	sz = v.size();
	for (int i = 1; i <= sz; i++)
	{
		go(0,0,i);
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (string x : ans) cout << x << '\n';
}