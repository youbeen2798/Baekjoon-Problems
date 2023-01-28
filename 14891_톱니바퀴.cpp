#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int k;
int arr[5][9];

deque<int> d[5];

vector<pair<int, int>> v; //ȸ����Ų ��Ϲ��� ��ȣ, ����

void rotate(int num, int dir) {

	if (dir == -1) { //�ð����
		int number = d[num].front(); //ù��° ����
		d[num].pop_front();
		d[num].push_back(number);
	}
	else { //�ݽð����
		int number = d[num].back(); //������ ����
		d[num].pop_back();
		d[num].push_front(number);
	}
}

void mini_solution(int num, int dir) {

	vector<pair<int, int>> v;
	v.push_back({ num, dir });

	if (num == 1) { //1�� ��Ϲ����� ȸ����Ű��

		for (int i = 2; i <= 4; i++) {
			if (d[i - 1][2] != d[i][6]) { //���� ���� �ٸ��ٸ�
				dir *= -1;
				v.push_back({ i,dir });
				continue;
			}
			break;
		}
	}
	else if (num == 2) { //2�� ��Ϲ����� ȸ����Ű��

		if (d[1][2] != d[2][6]) { //1�� ������ ����̶��
			v.push_back({ 1, dir * -1 }); 
		}
		if (d[2][2] != d[3][6]) { //3�� ������ ����̶��
			v.push_back({ 3, dir * -1 });

			if (d[3][2] != d[4][6]) { //4�� ����� ����̶��
				v.push_back({ 4,dir });
			}
		}
	}
	else if (num == 3) { //3�� ��Ϲ����� ȸ����Ű��

		if (d[2][2] != d[3][6]) { //2�� ������ ����̶��
			v.push_back({ 2, dir * -1 });
			if (d[1][2] != d[2][6]) {
				v.push_back({ 1, dir });
			}
		}
		
		if (d[3][2] != d[4][6]) { //4�� ������ ����̸�
			v.push_back({ 4,dir * -1 }); 
		}
	}
	else if (num == 4) { //4�� ��Ϲ����� ȸ����Ű��

		for (int i = 3; i >= 1; i--) {
			if (d[i][2] != d[i + 1][6]) {
				dir *= -1;
				v.push_back({ i,dir });
				continue;
			}
			break;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		rotate(v[i].first, v[i].second);
	}
}

int get_score() {
	int score = 0;

	
	if (d[1][0] == 1) {
		score += 1;
	}
	if (d[2][0] == 1) {
		score += 2;
	}
	if (d[3][0] == 1) {
		score += 4;
	}
	if (d[4][0] == 1) {
		score += 8;
	}
	return score;
}
void input() {
	for (int i = 1; i <= 4; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < 8; j++) {
			int num = s[j] - '0';
			d[i].push_back(num);
		}
	}

	cin >> k;

	for (int i = 0; i < k; i++) {
		int num, dir;
		cin >> num >> dir;
		mini_solution(num, dir);
	}

	cout << get_score();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}