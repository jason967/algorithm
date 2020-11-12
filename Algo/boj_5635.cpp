#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

struct student {
	string name;
	int year;
	int month;
	int day;
};

bool cmp(const student &a, const student &b)
{
	if (a.year < b.year)
		return true;
	else if (a.year == b.year)
	{
		if (a.month < b.month)
			return true;
		else if (a.month == b.month)
		{
			if (a.day < b.day)
				return a.name > b.name;
		}
	}
	return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	vector<student>s(N);

	for (int i = 0; i < N; i++)
		cin >> s[i].name >> s[i].day >> s[i].month >> s[i].year;

	stable_sort(s.begin(), s.end(), cmp);

	cout << s[N - 1].name << '\n';
	cout << s[0].name;
}