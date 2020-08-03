#include<cstdio>
#include<algorithm>
using namespace std;
int N,M;
int arr[100001];

bool binarySearch(int target) {
	int start = 0;
	int last = N - 1;
	int mid;
	while (start <= last)
	{
		mid = (start + last) / 2;
		if (target == arr[mid])
			return true;
		else
		{
			if (target < arr[mid])
			{
				last = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
	}
	
	return false;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	sort(arr, arr + N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int num;
		scanf("%d", &num);
		printf("%d: ", num);
		printf("%d\n", binarySearch(num));
	}
}