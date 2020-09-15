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
	//�޴��� �Ѱ��̻��̸� couseMenu �ʿ� �־��ֱ�
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
	//Order ���Ϳ� ���� order�� �߰�
	Order = orders;
	//�ֹ� ���� ����ŭ ���鼭 �޴� ���ո���� �ֱ�
	for (int i = 0; i < orders.size(); i++) {
		int OrderSize = Order[i].size();
		//�ܾ ������ �Ǿ����� �ʴٸ� ������ �̻��ϰ� ����� �� �� �����Ƿ� ��ó��
		sort(Order[i].begin(), Order[i].end());
		//���� �����
		makeCombination(0, i, OrderSize,"", 0);
	}

	for (int i = 0; i < course.size();i++) {
		//�ּ� �� ���� �մ��� �ֹ��ߴ� ��
		int minimumGuest = 0;
		map<string, int> ::iterator iter;
		//course[i]�� �޴��� ������ �޴��� �ּ� �� ���� �ֹ��ߴ��� �ֽ�ȭ
		for (iter = couseMenu[course[i]].begin(); iter != couseMenu[course[i]].end(); ++iter) {
			if ((*iter).second > minimumGuest) {
				minimumGuest = (*iter).second;
			}
		}
		cout << minimumGuest << '\n';
		//2���� ���ٸ� ����
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