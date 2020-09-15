#include <bits/stdc++.h>
using namespace std;
string par[4][4] = { { "cpp", "java", "python", "-" },
			   { "backend", "frontend","-", "-" },
			   { "junior", "senior", "-" , "-"},
			   { "chicken", "pizza" , "-", "-"} };
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	//�� �������� set�� idx�� �ְ� �ϳ��� ��
	//������ ������ pii�� set�� �ִ´�.
	vector<int> people[4][3][3][3];
	int c[4];
	int n = info.size();
	for (int i = 0; i < info.size(); i++) {
		int cnt = 0;
		string s = "";
		for (int j = 0; j < info[i].size(); j++) {
			if (info[i][j] == ' ') {
				for (int k = 0; k < 4; k++) {
					if (par[cnt][k] == s) {
						c[cnt] = k;
						break;
					}
				}
				cnt++;
				s = "";
			}
			else {
				s += info[i][j];
			}
		}
		int score = stoi(s);
		//4����
		people[c[0]][c[1]][c[2]][c[3]].push_back(score);

		//3����
		people[c[0]][c[1]][c[2]][2].push_back(score);
		people[c[0]][c[1]][2][c[3]].push_back(score);
		people[c[0]][2][c[2]][c[3]].push_back(score);
		people[3][c[1]][c[2]][c[3]].push_back(score);

		//2����
		people[c[0]][c[1]][2][2].push_back(score);
		people[c[0]][2][2][c[3]].push_back(score);
		people[c[0]][2][c[2]][2].push_back(score);
		people[3][2][c[2]][c[3]].push_back(score);
		people[3][c[1]][c[2]][2].push_back(score);
		people[3][c[1]][2][c[3]].push_back(score);
		
		//1����
		people[c[0]][2][2][2].push_back(score);
		people[3][2][c[2]][2].push_back(score);
		people[3][c[1]][2][2].push_back(score);
		people[3][2][2][c[3]].push_back(score);
		
		//0����
		people[3][2][2][2].push_back(score);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					sort(people[i][j][k][l].begin(), people[i][j][k][l].end());
				}
			}
		}
	}

	for (int i = 0; i < query.size(); i++) {
		int cnt = 0;
		string s = "";
		for (int j = 0; j < query[i].size(); j++) {
			if (query[i][j] == ' ') {
				if (s == "and") {
					s = "";
					continue;
				}
				for (int k = 0; k < 4; k++) {
					if (par[cnt][k] == s) {
						c[cnt] = k;
						break;
					}
				}
				cnt++;
				s = "";
			}
			else {
				s += query[i][j];
			}
		}
		int score = stoi(s);
		auto res = lower_bound(people[c[0]][c[1]][c[2]][c[3]].begin(), people[c[0]][c[1]][c[2]][c[3]].end(), score);
		int ans = people[c[0]][c[1]][c[2]][c[3]].size() - (res - people[c[0]][c[1]][c[2]][c[3]].begin());
		answer.push_back(ans);
	}

	return answer;
}