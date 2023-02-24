#include <iostream>
#include <deque>
using namespace std;

int n, k;

struct info {
	int negudo; //������
	bool robot; //�κ� ����
};

deque<info> dq;

int times = 0;

void down_robot() {
	if (dq[n - 1].robot) {
		dq[n - 1].robot = false;
	}
}

void rotate() {
	//��Ʈ�� �� ĭ ���� �ִ� �κ��� �Բ� �� ĭ ȸ���Ѵ�.

	info back = dq.back();
	dq.pop_back();
	dq.push_front(back);

	down_robot();
}


void robot_move() {
	//���� ���� ��Ʈ�� �ö� �κ�����, 
	//��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�.
	
	//0���� 2 * n - 1���� ����
	if (dq[2 * n - 1].robot && !dq[0].robot && dq[0].negudo > 0) {
		dq[2 * n - 1].robot = false;
		dq[0].robot = true;
		dq[0].negudo -= 1;
	}

	for (int i = 2 * n - 2; i >= 0; i--) {
		if (dq[i].robot && !dq[i+1].robot && dq[i + 1].negudo > 0) {
			//�κ��� �ְ�, �� ���� �������� 0���� ũ�ٸ�
			dq[i].robot = false;
			dq[i + 1].robot = true;
			dq[i + 1].negudo -= 1; //������ 1 ����
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