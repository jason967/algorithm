#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(string s) {

	int len = s.length();
	int answer = len;

	for (int sz = 1; sz <= (len / 2); sz++)
	{
		string res = "";
		string temp = s.substr(0, sz);
		int cnt = 1;
		for (int i = sz; i <= len; i += sz)
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

		}
		if (len / sz != 0)
		{
			res += s.substr((len / sz)*sz);
		}
		//cout<<res<<"\n";
		if (answer > res.length()) answer = res.length();
	}
	return answer;
}