#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string S;
	cin >> S;
	int len = S.length();
	bool isSame = true;
	bool isPal = true;
	for (int i = 0; i < len - 1; i++)
	{
		if (S[i] != S[i + 1])
		{
			isSame = false;
			break;
		}
	}
	for (int i = 0; i < len / 2; i++)
	{
		if (S[i] != S[len - i-1])
		{
			isPal = false;
			break;
		}
	}
	if (isSame)
	{
		printf("-1");
		return 0;
	}
	if (isPal) printf("%d", len - 1);
	else printf("%d", len);
}