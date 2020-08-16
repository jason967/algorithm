#include<iostream>
#include<string>

using namespace std;

char str[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string A, B;
	cin >> A >> B;

	int lenA = A.length();
	int lenB = B.length();

	int pivot = 0;

	for (int i = 0; i < lenA; i++)
	{
		str[pivot++] = A[i];
		if (str[pivot-1] == B[lenB-1])
		{
			bool can = true;
			if (pivot < lenB) continue;
			int here = pivot-1;
			for (int j = lenB-1; j >= 0; j--)
			{
				if (str[here--] != B[j]) can = false;
			}
			if (can)
			{
				pivot -= (lenB);
			}
		}
	}
	if (pivot == 0) cout << "FRULA";
	else for (int i = 0; i < pivot; i++) cout << str[i];
}