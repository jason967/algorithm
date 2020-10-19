#include<iostream>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

int T, A, B;

bool c[10001];
int d[10001];

void setUp()
{
	for (int i = 2; i < 10000; i++)
	{
		if (c[i] == false)
		{
			for (int j = i + i; j < 10000; j += i)
				c[j] = true;
		}
	}
}

int bfs(int st, int dest)
{
	memset(d, -1, sizeof(d));
	queue<int> q;
	q.push(st);
	d[st] = 0;
	while (q.size() > 0)
	{
		int cur = q.front();
		q.pop();
		if (cur == dest)
		{
			return d[cur];
		}
		for (int i = 0; i < 4; i++)
		{
			string curS = to_string(cur);
			for (int j = 0; j <= 9; j++)
			{
				if (i == 0 && j == 0) continue;
				curS[i] = j + '0';
				int nx = stoi(curS);
				if (d[nx] == -1 && !c[nx])
				{
					d[nx] = d[cur] + 1;
					q.push(nx);
				}
			}
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	setUp();
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> A >> B;
		cout<<bfs(A, B)<<"\n";
	}
}