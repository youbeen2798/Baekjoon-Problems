#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int k;
int arr[5][9];

deque<int> d[5];

vector<pair<int, int>> v; //회전시킨 톱니바퀴 번호, 방향

void rotate(int num, int dir) {

	if (dir == -1) { //시계방향
		int number = d[num].front(); //첫번째 숫자
		d[num].pop_front();
		d[num].push_back(number);
	}
	else { //반시계방향
		int number = d[num].back(); //마지막 숫자
		d[num].pop_back();
		d[num].push_front(number);
	}
}

void mini_solution(int num, int dir) {

	vector<pair<int, int>> v;
	v.push_back({ num, dir });

	if (num == 1) { //1번 톱니바퀴를 회전시키면

		for (int i = 2; i <= 4; i++) {
			if (d[i - 1][2] != d[i][6]) { //서로 극이 다르다면
				dir *= -1;
				v.push_back({ i,dir });
				continue;
			}
			break;
		}
	}
	else if (num == 2) { //2번 톱니바퀴를 회전시키면

		if (d[1][2] != d[2][6]) { //1번 바퀴와 상극이라면
			v.push_back({ 1, dir * -1 }); 
		}
		if (d[2][2] != d[3][6]) { //3번 바퀴와 상극이라면
			v.push_back({ 3, dir * -1 });

			if (d[3][2] != d[4][6]) { //4번 바쿠와 상극이라면
				v.push_back({ 4,dir });
			}
		}
	}
	else if (num == 3) { //3번 톱니바퀴를 회전시키면

		if (d[2][2] != d[3][6]) { //2번 바퀴와 상극이라면
			v.push_back({ 2, dir * -1 });
			if (d[1][2] != d[2][6]) {
				v.push_back({ 1, dir });
			}
		}
		
		if (d[3][2] != d[4][6]) { //4번 바퀴와 상극이면
			v.push_back({ 4,dir * -1 }); 
		}
	}
	else if (num == 4) { //4번 톱니바퀴를 회전시키면

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