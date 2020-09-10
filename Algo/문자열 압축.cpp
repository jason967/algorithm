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
	int ans = len;
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
					res += temp;
				}
				else res += (to_string(cnt) + temp);
				temp = t;
				cnt = 1;
			}
			if (len / sz != 0)
			{
				res += s.substr((len / sz)*sz);
			}
			if (ans > res.length()) ans = res.length();
		}
	}
	
}