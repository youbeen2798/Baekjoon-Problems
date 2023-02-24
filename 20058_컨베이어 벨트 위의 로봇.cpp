#include <iostream>
#include <deque>
using namespace std;

int n, k;

struct info {
	int negudo; //내구도
	bool robot; //로봇 유무
};

deque<info> dq;

int times = 0;

void down_robot() {
	if (dq[n - 1].robot) {
		dq[n - 1].robot = false;
	}
}

void rotate() {
	//벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.

	info back = dq.back();
	dq.pop_back();
	dq.push_front(back);

	down_robot();
}


void robot_move() {
	//가장 먼저 벨트에 올라간 로봇부터, 
	//벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.
	
	//0부터 2 * n - 1까지 있음
	if (dq[2 * n - 1].robot && !dq[0].robot && dq[0].negudo > 0) {
		dq[2 * n - 1].robot = false;
		dq[0].robot = true;
		dq[0].negudo -= 1;
	}

	for (int i = 2 * n - 2; i >= 0; i--) {
		if (dq[i].robot && !dq[i+1].robot && dq[i + 1].negudo > 0) {
			//로봇이 있고, 그 다음 내구도가 0보다 크다면
			dq[i].robot = false;
			dq[i + 1].robot = true;
			dq[i + 1].negudo -= 1; //내구도 1 감소
		}

		down_robot();
	}
}

void put_robot() {
	if (dq[0].negudo > 0 && !dq[0].robot) {
		dq[0].robot = true;
		dq[0].negudo -= 1;
	}
}

void check() {
	
	int negudo_zero_cnt = 0;

	for (int i = 0; i <=  2 * n - 1; i++) {
		if (dq[i].negudo == 0) {
			negudo_zero_cnt++;
		}
	}

//	cout << times << ": " << negudo_zero_cnt << "\n";

	if (negudo_zero_cnt >= k) {
		cout << times;
		exit(0);
	}
}
void solution() {

	for (times = 1; ; times++) {
		rotate();
		robot_move();
		put_robot();
		check();
	}
	

}

void input() {
	cin >> n >> k;

	for (int i = 0; i < 2 * n; i++) {
		int num;
		cin >> num;
		dq.push_back({ num, false });
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}