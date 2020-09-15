#include <string>
#include <vector>
#include<queue>
#include<deque>
#include<cstring>

using namespace std;

int Ball[] = { 11,2,9,13,24 };
int Order[] = { 9,2,13,24,11 };

bool wait[1000001];

deque<int> ball, order;

int main()
{
	vector<int> Ball,Order;

	for (int i = 0; i < 5; i++)
	{
		ball.push_back(Ball[i]);
		order.push_back(Order[i]);
	}
	vector<int> answer;

	int head = 0;
	int	tail = ball.size() - 1;

	for (int i = 0; i < order.size(); i++)
	{
		if (order[i] == ball[head])
		{
			answer.push_back(ball[head++]);
			while (wait[ball[head]] && head < tail) 
			{
				answer.push_back(ball[head]);
				wait[ball[head++]] = false;
			}
		}
		else if (order[i] == ball[tail]) 
		{
			answer.push_back(ball[tail--]);
			while (wait[ball[tail]] && head < tail)
			{
				answer.push_back(ball[tail]);
				wait[ball[tail--]] = false;
			}
		}
		else 
		{
			wait[order[i]] = true;
		}
	}

	
}