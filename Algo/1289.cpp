#include<iostream>
#include<string>

using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> N;
	for (int tc = 1; tc <= N; tc++)
	{
		cin >> s;
		int res = 0;
		if (s[0] == '1') res++;
		for (int i = 1; i < s.length(); i++)
		{
			if (s[i - 1] != s[i])res++;
		}
		cout <<"#"<<tc<<" "<< res<<'\n';
	}
}