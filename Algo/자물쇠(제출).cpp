#include <string>
#include <vector>

using namespace std;

int A[60][60];
int CKey[4][20][20];

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	int M = key[0].size();
	int N = lock[0].size();

	//LOCK 배열 저장
	int Locked = 0;
	int L = N + (M - 1) * 2;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i + M - 1][j + M - 1] = lock[i][j];
			if (lock[i][j] == 0) Locked++;
		}
	}

	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			if (i < M - 1 || i >= N + M - 1 || j < M - 1 || j >= N + M - 1) A[i][j] = -1;
		}
	}

	//KEY 배열 회전
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++) CKey[0][i][j] = key[i][j];
	}

	for (int dir = 1; dir < 4; dir++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < M; j++)
				CKey[dir][i][j] = CKey[dir - 1][M - j - 1][i];
		}
	}
	//회전된 KEY 배열 저장 완료

	bool answer = false;

	for (int y = 0; y < L - M + 1; y++)
	{
		for (int x = 0; x < L - M + 1; x++)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				int cnt = 0;
				bool can = true;
				for (int i = 0; i < M && can; i++)
				{
					for (int j = 0; j < M; j++)
					{
						if (CKey[dir][i][j] == 1 && A[y + i][x + j] == 1)
						{
							can = false;
							break;
						}
						else if (CKey[dir][i][j] == 1 && A[y + i][x + j] == 0) cnt++;
					}
				}
				if (cnt == Locked) return true;
			}
		}
	}
	return answer;
}