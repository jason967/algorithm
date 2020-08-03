#include <cstdio>
#include <algorithm>
#include<vector>

using namespace std;
int N,num;
vector<int> v;

int main()
{
	scanf("%d", &N);
	vector<int>::iterator low;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		if (v.empty() || v.back() < num) v.push_back(num);
		else
		{
			low = lower_bound(v.begin(), v.end(), num);
			*low = num;
		}
	}
	printf("%d", v.size());
}