#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	string S;
	cin >> S;
	stack<char> st;
	int len = 0;
	for (int i = 0; i < S.length(); i++)
	{
		//cout << S[i] << '\n';
		if (S[i] == ')')
		{
			int temp = 0;
			while (1)
			{
				if (st.empty()) break;
				char c = st.top();
				st.pop();
				//¿­¸° °ýÈ£
				if (c == '(')
				{
					if (st.empty()) break;

					int K = st.top() - '0';
					st.pop();
					if (temp == 0)
					{
						printf("temp0\n");
						temp = len;
					}
					else {
						//temp += len;
						printf("°ö %d\n",K);
						temp *= K;
						len += temp;
					}
					break;
				}
				//¼ýÀÚ
				else if (c != '(')
				{
					temp++;
				}
			}
			cout << "temp: " << temp << "len: " << len << '\n';
		}
		else st.push(S[i]);
		//cout << st.top() << '\n';
	}
	while (!st.empty())
	{
		len++;
		st.pop();
	}
	cout << len;
}
