#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

bool used[12];
map<string, int> couseMenu[12];
vector<string> Order;

void makeCombination(int idx, int guest, int OSize, string menu, int cnt ) {
	//메뉴가 한개이상이면 couseMenu 맵에 넣어주기
	if (cnt > 1) {
		couseMenu[cnt][menu]++;
		return;
	}
	for (int i = idx; i < OSize; i++) {
		if (used[i]) continue;
		used[i] = true;
		menu += Order[guest][i];
		makeCombination(i, guest, OSize, menu, cnt + 1 );
		menu.pop_back();
		used[i] = false;
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	//Order 벡터에 원래 order값 추가
	Order = orders;
	//주문 들어온 수만큼 돌면서 메뉴 조합만들어 주기
	for (int i = 0; i < orders.size(); i++) {
		int OrderSize = Order[i].size();
		//단어가 정렬이 되어있지 않다면 조합이 이상하게 만들어 질 수 있으므로 전처리
		sort(Order[i].begin(), Order[i].end());
		//조합 만들기
		makeCombination(0, i, OrderSize,"", 0);
	}

	for (int i = 0; i < course.size();i++) {
		//최소 몇 명의 손님이 주문했는 지
		int minimumGuest = 0;
		map<string, int> ::iterator iter;
		//course[i]개 메뉴로 구성된 메뉴를 최소 몇 명이 주문했는지 최신화
		for (iter = couseMenu[course[i]].begin(); iter != couseMenu[course[i]].end(); ++iter) {
			if ((*iter).second > minimumGuest) {
				minimumGuest = (*iter).second;
			}
		}
		cout << minimumGuest << '\n';
		//2명보다 적다면 무시
		if (minimumGuest < 2)
			continue;
		//
		for (iter = couseMenu[course[i]].begin(); iter != couseMenu[course[i]].end(); ++iter) {
			if ((*iter).second == minimumGuest) {
				answer.push_back((*iter).first);
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}