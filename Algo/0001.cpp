#include<vector>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAX = 2e9;
vector<int> S;
vector<int> answer;
int sz;
int Len[101], Count[101];

int LIS(int start)
{

	int &result = Len[start + 1];

	if (result != -1)
		return result;

	result = 1;

	for (int nx = start + 1; nx < sz; nx++)
		if (start == -1 || S[start] < S[nx])
			result = max(result, LIS(nx) + 1);
	return result;

}

int count(int start)
{

	if (LIS(start) == 1)
		return 1;

	int &result = Count[start + 1];

	if (result != -1)
		return result;
	result = 0;

	for (int nx = start + 1; nx < sz; nx++)
		if ((start == -1 || S[start] < S[nx]) && LIS(start) == LIS(nx) + 1)
			result = min<long long>(MAX, (long long)result + count(nx));
	return result;
}

void calLIS(int start, int skip, vector<int> &lis)
{

	if (start != -1)

		lis.push_back(S[start]);


	vector<pair<int, int>> V;

	for (int nx = start + 1; nx < sz; nx++)
		if ((start == -1 || S[start] < S[nx]) && LIS(start) == LIS(nx) + 1)
			V.push_back(make_pair(S[nx], nx));

	sort(V.begin(), V.end()); //Á¤·Ä

	for (int i = 0; i < V.size(); i++)
	{
		int idx = V[i].second;
		int cnt = count(idx);
		if (cnt <= skip)
			skip -= cnt;
		else
		{
			calLIS(idx, skip, lis);
			break;
		}
	}

}

vector<int> solution(vector<int> cookies, int k)
{
	S = cookies;
	int K = k;
	sz = S.size();
	memset(Count, -1, sizeof(Count));
	memset(Len, -1, sizeof(Len));
	vector<int> res;
	calLIS(-1, K - 1, res);
	for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
	return res;
}