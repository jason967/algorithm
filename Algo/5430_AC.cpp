#include<iostream>
#include<deque>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {

		bool flag = false;
		bool err = false;

		deque<int> dq;

		string p, x;
		int n;
		cin >> p>>n>>x;
		
		int x_len = (int)x.size();

		string temp;

		for (int i = 0; i < x_len; i++) {

			if (x[i] == '[') continue;
			else if (isalnum(x[i]))
				temp += x[i];
			else if (!isalnum(x[i])) {
				if (!temp.empty()) {
					dq.push_back(stoi(temp));
					temp = "";
				}
			}
		}


		int p_len = (int)p.size();

		for (int i = 0; i < p_len; i++)
		{
			if (p[i] == 'R')
				flag = flag ^ 1;

			else if (p[i] == 'D') {
				if (dq.empty()) {
					err = true;
					break;
				}
				if (!flag)
					dq.pop_front();

				else if (flag)
					dq.pop_back();

			}

		}
		int dq_size = (int)dq.size();

		if (err) cout << "error" << '\n';
		else if (!err) {
			cout << '[';
			if (!flag)
			{

				for (int i = 0; i < dq_size; i++) {
					if (!(i == dq_size - 1))
						cout << dq[i] << ',';
					else
						cout << dq[i];
				}
			}
			else if (flag) {
				reverse(dq.begin(), dq.end());
				for (int i = 0; i < dq_size; i++) {
					if (i == dq_size - 1)
						cout << dq[i];
					else
						cout << dq[i] << ',';
				}
			}
			cout << ']' << '\n';
		}
	}
}
