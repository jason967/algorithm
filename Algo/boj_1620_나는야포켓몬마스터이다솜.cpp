#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	map<string, int> m;
	vector<string> V;
	V.push_back("temp");
	for (int i = 1; i <= N; i++)
	{
		string S;
		cin >> S;
		m.insert({ S,i });
		V.push_back(S);
	}
	for (int i = 1; i <= M; i++)
	{
		string s;
		cin >> s;
		if (s[0] >= '0'&&s[0] <= '9') cout << V[stoi(s)] << '\n';
		else cout << m[s] << "\n";
	}
}