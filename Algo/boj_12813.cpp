#include<iostream>
#include<string>

using namespace std;

string A, B;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B;

	string ans="";
	for (int j = 0; j < A.length(); j++)
	{
		int tmp = (A[j] - '0')&(B[j] - '0');
		ans += to_string(tmp);
	}
	cout << ans << '\n';
	ans = "";
	for (int j = 0; j < A.length(); j++)
	{
		int tmp = (A[j] - '0')|(B[j] - '0');
		ans += to_string(tmp);
	}
	cout << ans << '\n';
	ans = "";
	for (int j = 0; j < A.length(); j++)
	{
		int tmp = (A[j] - '0')^(B[j] - '0');
		ans += to_string(tmp);
	}
	cout << ans << '\n';
	ans = "";
	for (int j = 0; j < A.length(); j++)
	{
		char tmp = A[j]=='1'?'0':'1';
		ans += tmp;
	}
	cout << ans << '\n';
	ans = "";
	for (int j = 0; j < B.length(); j++)
	{
		char tmp = B[j] == '1' ? '0' : '1';
		ans += tmp;
	}
	cout << ans << '\n';
}