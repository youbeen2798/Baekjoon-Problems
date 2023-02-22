#include <iostream>
#include <deque>
using namespace std;

int n, m, t;
deque<int> dq[51];
deque<bool> check_erase[51];
bool erase_flag = false;

void real_rotate(int num, int di, int ki) {
	//번호가 num인 원판을 di 방향으로 ki칸 회전

	if (di == 0) {
		//시계 방향이면
		for (int i = 0; i < ki; i++) {
			int back = dq[num].back();
			dq[num].pop_back();
			dq[num].push_front(back);
		}
	}
	else {
		//반시계 방향이면
		for (int i = 0; i < ki; i++) {
			int front = dq[num].front();
			dq[num].pop_front();
			dq[num].push_back(front);
		}
	}
}
void rotate(int xi, int di, int ki) {
	//번호가 xi의 배수인 원판을 di 방향으로 ki칸 회전
	for (int i = xi; i <= n; i += xi) {
		real_rotate(i, di, ki);
	}
}

void erase_reset() {

	for (int i = 1; i <= n; i++) {
		check_erase[i].clear();
		for (int j = 0; j < m; j++) {
			check_erase[i].push_back(false);
		}
	}

}
void real_left_right_erase(int num) {
	//원판 num에 있는 숫자 확인하고 지우기


	//좌우로 인접
	for (int i = 0; i < dq[num].size() - 1; i++) {
		if (dq[num][i] == dq[num][i + 1] && dq[num][i] != -1) {
			check_erase[num][i] = true;
			check_erase[num][i + 1] = true;
		}
	}

	if (dq[num][dq[num].size() - 1] == dq[num][0] && dq[num][0] != -1) {
		check_erase[num][0] = true;
		check_erase[num][dq[num].size() - 1] = true;
	}
}

void real_top_down_erase(int num) {

	//상하로 인접
	for (int j = 0; j < m; j++) {
		if (dq[num][j] == dq[num + 1][j] && dq[num][j] != -1) {
			check_erase[num][j] = true;
			check_erase[num + 1][j] = true;
		}
	}
}


void erase() {
	//인접한 수 지우기

	erase_reset();

	for (int i = 1; i <= n; i++) {
		real_left_right_erase(i);
	}

	for(int i = 1; i < n; i++){
		real_top_down_erase(i);
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (check_erase[i][j]) {
				erase_flag = true;
				dq[i][j] = -1;
			}
		}
	}
}


void change_with_average() {
	
	//평균으로 맞추기
	if (erase_flag) {
		return;
	}

	double sum = 0;
	double avg;
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (dq[i][j] != -1) {
				sum += dq[i][j];
				cnt++;
			}
		}
	}
	

	avg = sum / (double)cnt; //평균

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (dq[i][j] != -1) {
				if (dq[i][j] > avg) {
					dq[i][j]--;
				}
				else if (dq[i][j] < avg) {
					dq[i][j]++;
				}
			}
		}
	}

}
void solution(int xi, int di, int ki) {
	 
	rotate(xi, di, ki); //회전

	erase_flag = false; //아직 지우지 않았다는 의미
	erase();
	change_with_average(); //평균으로 맞추기
}


void input() {
	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			dq[i].push_back(num);
		}
	}

	for (int i = 0; i < t; i++) {
		int xi, di, ki;
		cin >> xi >> di >> ki;
		solution(xi, di, ki);
	}
}

void output() {
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (dq[i][j] != -1) {
				ans += dq[i][j];
			}
		}
	}

	cout << ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	output();
}