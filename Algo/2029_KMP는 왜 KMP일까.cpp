#include <iostream>
#include <string>

using namespace std;
string s;
char C[101];
int cnt;
int main()
{

	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')
			C[cnt++] = s[i];
	}
	for (int i = 0; i < cnt; i++)
		cout << C[i];
	return 0;
}
