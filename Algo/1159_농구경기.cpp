#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<pair<char, int>>v(26);
	char ans[27];
	int cnt = 0;

	int N;
	cin >> N;

	vector<string>s(N);

	for (int i = 0; i < 26; i++)
	{
		v[i].first = i + 'a';
		v[i].second = 0;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
		for (int j = 0; j < 26; j++)
		{
			if (s[i][0] == v[j].first)
				v[j].second += 1;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (v[i].second >= 5)
			ans[cnt++] = v[i].first;
	}

	if (cnt == 0)
		cout << "PREDAJA";

	else {
		for (int i = 0; i < cnt; i++)
			cout << ans[i];
	}
	return 0;
}