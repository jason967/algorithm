#include<iostream>
#include<string> 
using namespace std;

struct _order
{
	int dir, len;
}order[7];
int K,res=1;
int cnt[5];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string ret = "";
	cin >> K;
	for (int i = 0; i < 6; i++)
	{
		cin >> order[i].dir >> order[i].len;
		cnt[order[i].dir]++;
	}
	order[6] = { order[0].dir,order[0].len };
	for (int i = 1; i <= 4; i++) ret += cnt[i] + '0';
	int temp = 0;
	if (ret == "2121")
	{
		for (int i = 0; i < 6; i++)
		{
			if (order[i].dir == 2 || order[i].dir == 4) res *= order[i].len;
			if (order[i].dir == 1 && order[i + 1].dir == 3) temp = order[i].len*order[i + 1].len;
		}
	}
	else if (ret == "1221")
	{
		for (int i = 0; i < 6; i++)
		{
			if (order[i].dir == 1 || order[i].dir == 4) res *= order[i].len;
			if (order[i].dir == 3 && order[i + 1].dir == 2) temp = order[i].len*order[i + 1].len;
		}
	}
	else if (ret == "1212")
	{
		for (int i = 0; i < 6; i++)
		{
			if (order[i].dir == 3 || order[i].dir == 1) res *= order[i].len;
			if (order[i].dir == 2 && order[i + 1].dir == 4) temp = order[i].len*order[i + 1].len;
		}
	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			if (order[i].dir == 2 || order[i].dir == 3) res *= order[i].len;
			if (order[i].dir == 4 && order[i + 1].dir == 1) temp = order[i].len*order[i + 1].len;
		}
	}
	res -= temp;
	cout << res*K;
}