#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int N, K,num,sz,ans;
string S[51];

bool used[26], cpyUsed[26];
vector<int> can;
bool vis[26];

void go(int idx, int cnt)
{
	//cout << idx << '\n';
	if (cnt == num)
	{
		int res = 0;
		memcpy(cpyUsed, used, sizeof(used));
		for (int i = 0; i < sz; i++)
		{
			if (vis[i]) cpyUsed[can[i]] = true;
		}
		//for (int i = 0; i < 26; i++) if (cpyUsed[i]) cout << i << " ";
		//cout << '\n';
		for (int i = 0; i < N; i++)
		{
			bool isOk = true;
			for (int j = 0; j < S[i].length(); j++)
			{
				//cout << S[i][j]-'a'  << "\n";
				if (!cpyUsed[S[i][j] - 'a'])
				{
					isOk = false;
					break;
				}
			}
			if(isOk) res++;
		}
		if (ans < res) ans = res;
		return;
	}
	for (int i = idx; i < sz; i++)
	{
		if (vis[i]) continue;
		vis[i] = true;
		go(i, cnt+1);
		vis[i] = false;
	}
}

void setUp()
{
	used[0] = used[2] = used[8] = used[13] = used[19] = true;
	sort(can.begin(), can.end());
	can.erase(unique(can.begin(), can.end()), can.end());
	sz = can.size();
	num = K - 5;
	if (num > sz) num = sz;
	//cout << num << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	if (K < 5) {
		cout << 0;
		return 0;
	}
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
		for (int j = 0; j < S[i].length(); j++)
		{
			char temp = S[i][j];
			if (temp == 'a' || temp == 'c' || temp == 'i' || temp == 'n' || temp == 't') continue;
			can.push_back(temp - 'a');
		}
	}
	setUp();
	//for (int i = 0; i < can.size(); i++) cout << can[i] << " ";
	//cout << '\n';
	go(0, 0);
	cout<<ans;

}