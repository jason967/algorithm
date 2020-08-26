/*
ACMICPC
문제 번호 : 1753
문제 제목 : 최단경로
풀이 날짜 : 2020-08-25
Solved By Reamer
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> intVec[20001];
int dijk[20001];
bool isSearched[20001];

int main()
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	int V, E;
	int start, from, to, dist;
	vector<pair<int, int>> tmpVec;
	cin >> V >> E;
	cin >> start;

	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> dist;
		intVec[from].push_back({ to, dist });
	}

	for (int i = 1; i <= V; i++)
	{
		if (i == start)
			dijk[i] = 0;
		else
			dijk[i] = INT32_MAX;
	}

	while (true)
	{
		int minDist = INT32_MAX;
		int idx = -1;
		for (int i = 1; i <= V; i++)
		{
			if (!isSearched[i] && minDist > dijk[i])
			{
				minDist = dijk[i];
				idx = i;
			}
		}

		if (idx == -1)
			break;

		isSearched[idx] = true;

		for (int i = 0; i < intVec[idx].size(); i++)
		{
			int nx = intVec[idx][i].first;
			if (!isSearched[nx]) {

				//int dest = tmpVec[i].first;
				dijk[nx] = min(dijk[nx], dijk[idx] + intVec[start][i].second);
			}
		}

		//start = idx;
	}

	for (int i = 1; i <= V; i++)
	{
		if (dijk[i] == INT32_MAX)
			cout << "INF\n";
		else
			cout << dijk[i] << "\n";
	}

	return 0;
}