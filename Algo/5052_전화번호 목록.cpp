#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int T, N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<string> S(N);
		for (int i = 0; i < N; i++) cin >> S[i];
		sort(S.begin(), S.end());
		bool flag = true;
		for (int i = 0; i < N-1; i++)
		{
			int len = S[i].length();
			if (len > S[i + 1].length()) continue;
			if (S[i] == S[i + 1].substr(0, len))
			{
				cout << "NO" << '\n';
				flag = false;
				break;
			}
		}
		if (flag)cout << "YES" << '\n';
	}
}