#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int N, res;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int A[26];
		memset(A, 0, sizeof(A));
		string s;
		cin >> s;
		A[s[0] - 'a'] = 1;
		for (int j = 1; j < s.length(); j++)
		{
			if (s[j - 1] != s[j])
			{
				if (A[s[j] - 'a'] != 0)
				{
					res++;
					break;
				}
				else
				{
					A[s[j] - 'a']++;
				}
			}
			else A[s[j] - 'a']++;
		}
	}
	cout << N - res;
}