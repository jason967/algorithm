#include<iostream>

using namespace std;
int A[100][100];
struct Node
{
	int y, x;
};

Node queue[100];

void bfs(int dy, int dx)
{
	queue[0] = { dy,dx };
	int head = 0;
	int tail = 1;

	A[dy][dx] = 0;
	int cnt = 1;
	while (head != tail)
	{
		Node now = queue[head++];
		queue[tail++] = { ny,nx };
	}

}
int main()
{
	//단축키 암기
	//브레이크 포인트 / 디버그 모드 진입, 종료
	//freopen("Text.txt", "r", stdin);
	for (int i = 0; i < 100; i++)
	{
		A[i] = i * 12;
		if (i == 9)
		{
			int debug = 1;
		}
		cout << i << '\n';
	}

	return 0;
}