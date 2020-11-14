#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, int> m1;

int main()
{
	int N, M;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int t = 0; t < N; t++)
	{
		cin >> M;
		map<string, int> m;
		for (int i = 0; i < M; i++)
		{
			string name, specis;
			cin >> name >> specis;
			if (m.count(specis) > 0) m[specis]++;
			else m.insert({ specis,1 });
		}
		int ans = 1;
		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			ans *= (*iter).second + 1;
		}
		cout << ans - 1 << '\n';
	}
}