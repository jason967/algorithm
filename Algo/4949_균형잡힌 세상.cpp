#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1)
	{
		string str;
		getline(cin,str);
		if (str == ".") break;
		stack<char> s;
		bool isOk = true;
		for (int i = 0; i < str.length()&& isOk; i++)
		{
			if (str[i] == '(' || str[i] == '[') s.push(str[i]);
			else if (str[i] == ')')
			{
				if (s.empty() || s.top()!='(')
				{
					cout << "no" << '\n';
					isOk = false;
					break;
				}
				else s.pop();				
			}
			else if (str[i] == ']')
			{
				if (s.empty() || s.top() != '[')
				{
					cout << "no" << '\n';
					isOk = false;
					break;
				}
				else s.pop();
			}
		}
		if (!isOk) continue;
		if (s.size() == 0) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
}