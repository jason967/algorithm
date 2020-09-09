#include<iostream>
#include<string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int len = s.length();
	for (int sz = 1; sz <= len / 2; sz++)
	{
		string res = "";
		string temp = s.substr(0, sz);
		int cnt = 1;
		for (int i = 0; i < len; i+=sz)
		{
			string t = s.substr(i, sz);
			//압축 1회 진행
			if (temp == t)
			{
				cnt++;
			}
			else
			{
				if (cnt == 1)
				{

				}
			}
			if (i + sz > len || t != s.substr(i + sz, sz))
			{
				if
			}
			string t2 = s.substr(i + sz, sz);

			i += sz;
		}
	}
	int sz = 3;
	for (int i = 0; i < len; i++)
	{
		cout << i << '\n';
		string t1 = s.substr(i, sz);
		string t2 = s.substr(i + sz, sz);
		cout << t1 << '\n';
		cout << t2 << '\n';
		i += (sz+1);
	}
}