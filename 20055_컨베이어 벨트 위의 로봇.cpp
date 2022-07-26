#include <iostream>
#include <deque>
using namespace std;

int n, k;
int num;

deque <int> naegu;
deque <bool> robot;


void rotate(){  	// �� ĭ ȸ���ϱ�	


	naegu.push_front(naegu.back());
	naegu.pop_back();

	robot.push_front(robot.back());
	robot.pop_back();
	robot[n - 1] = false; //n��ĭ ������

}

void move(){  //��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵�

	for (int i = n - 2; i >= 0; i--) {
		if ((!robot[i + 1]) && (naegu[i + 1] > 0) && (robot[i])) {
			robot[i] = false;
			robot[i + 1] = true;
			naegu[i + 1]--;
		}
	}
	robot[n - 1] = false; //���� �κ��� ������ ��ġ�� �����Ѵٸ�

}

void  put_robot() {
	//�ö󰡴� ��ġ�� �κ��� ���ٸ� �κ��� �ϳ� �ø���.
	if (!robot[0] && naegu[0] > 0) {
		robot[0] = true;
		naegu[0]--;
	}
}

int check() { //�������� 0�� ĭ�� ���� ����
	int count = 0;

	for (int i = 0; i < 2 * n; i++) {
		if (naegu[i] == 0) {
			count++;
		}
	}

	return count;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int step = 1;


	cin >> n >> k;

	//������ �Է¹ޱ�
	for (int i = 0; i < 2 * n; i++) {
		cin >> num;
		naegu.push_back(num);
		robot.push_back(false);
	}


	while (true) {

		rotate();
		move();
		put_robot();

		if (check() >= k) {
			cout << step << "\n";
			break;
		}
		step++;
	}

	return 0;


}