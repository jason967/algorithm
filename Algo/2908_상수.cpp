#include <iostream>
#include <vector>

using namespace std;

int a, b, c;

int main()
{
	vector<pair<int, int>>s(2);


	for (int i = 0; i < 2; i++)
	{
		cin >> s[i].first;
		a = s[i].first / 100;
		b = (s[i].first % 100) / 10;
		c = s[i].first % 10;
		s[i].second = c * 100 + b * 10 + a;
	}

	if (s[0].second > s[1].second)
		cout << s[0].second;
	else
		cout << s[1].second;
}
