#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

vector<int>v;
vector<int>cnt;
deque<pair<int, int>>dq;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		v.clear();
		cnt.clear();
		dq.clear();

		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			v.push_back(num);
			dq.push_back({ i,num });
		}

		sort(v.begin(), v.end());

		while (!dq.empty())
		{
			if (dq.front().second == v.back())
			{
				int temp = dq.front().first;
				cnt.push_back(temp);
				dq.pop_front();
				v.pop_back();
			}
			else if (dq.front().second != v.back())
			{
				dq.push_back({ dq.front().first,dq.front().second });
				dq.pop_front();
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (cnt[i] == m)
				cout << i + 1 << '\n';
		}
	}
}
