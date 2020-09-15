#include<iostream>
#include<string>
using namespace std;

int NumSize;
string Num;
int n = 73425;

const int INF = 1e9;
int ansCnt = INF;
int ansNum = 0;

void go(int cur, int cnt)
{
	if (cur < 10)
	{
		if (ansCnt > cnt)
		{
			ansCnt = cnt;
			ansNum = cur;
		}
		return;
	}
	string copyNum = Num;
	for (int i = 1; i < NumSize; i++)
	{
		string head = copyNum.substr(0, i);
		string tail = copyNum.substr(i, NumSize);
		int h = stoi(head);
		int t = stoi(tail);
		go(h + t, cnt + 1);
	}
}

int main()
{
	
	Num = to_string(n);
	NumSize = Num.length();


	int temp = n/
}