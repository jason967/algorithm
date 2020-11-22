#include <iostream>

using namespace std;

int main()
{
	int n;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while (n--)
	{
		int price;
		cin >> price;
		int c;
		cin >> c;
		int sum = 0;
		for (int i = 0; i < c; i++)
		{
			int n, m;
			cin >> n >> m;
			sum += n * m;
		}
		price += sum;
		cout << price << '\n';
	}
	return 0;
}