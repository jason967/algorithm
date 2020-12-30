#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#define pii pair<int,int>
using namespace std;
int ji[1002][1002];
int fire[1002][1002];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int R, C;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	vector<string> S(R + 2);
	queue<pii> Q;
	int J_x, J_y;
	for (int i = 0; i < R; i++)
		cin >> S[i];
	memset(ji, -1, sizeof(ji));
	memset(fire, -1, sizeof(fire));
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (S[i][j] == 'F')
			{
				fire[i][j] = 0;
				Q.push({ i,j });
			}
			if (S[i][j] == 'J')
			{
				ji[i][j] = 0;
				J_x = j;
				J_y = i;
			}
		}
	while (!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if (fire[ny][nx] == -1 && S[ny][nx] != '#')
			{
				fire[ny][nx] = fire[y][x] + 1;
				Q.push({ ny,nx });
			}
		}
	}
	Q.push({ J_y,J_x });
	int ans = -1;
	while (!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;
		if (y == 0 || y == R - 1 || x == 0 || x == C - 1)
		{
			ans = ji[y][x];
			break;
		}
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if (S[ny][nx] == '.' && ji[ny][nx] == -1)
			{
				if (fire[ny][nx] == -1 || fire[ny][nx] > ji[y][x] + 1)
				{
					ji[ny][nx] = ji[y][x] + 1;
					Q.push({ ny,nx });
				}
			}
			;
		}
	}
	if (ans != -1) cout << ans + 1;
	else cout << "IMPOSSIBLE";
	return 0;
}