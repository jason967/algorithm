#include<iostream>
#include<string>

using namespace std;
int N;

char A[3] = { '1','2','3' };
int ans = 0;
void go(int len,string S)
{
	if (len == N)
	{
		//ans++;
		cout << S<<'\n';
		return;
	}
	if (len > 0 && S[len - 1] == '1')return;
		go(len + 1, S + '1');
	if (len > 0 && S[len - 1] == '2') return;
		go(len + 1, S + '2');
	if (len > 0 && S[len - 1] == '3') return;
		go(len + 1, S + '3');
}
int main()
{
	cin >> N;
	go(1,"1");
	cout << ans;
}