#include <iostream>
#include <deque>
using namespace std;

int rotatedirection[5]; //������ ��Ϲ����� ȸ����Ų�ٴ� �����Ͽ� ȸ�� ����

bool rotateornot[5];

deque <char> d1;
deque <char> d2;
deque <char> d3;
deque <char> d4;

int k;

void isrotate(int num) { //ȸ����ų�� ���� ����

	if (num == 1) { //ù��° ��Ϲ����� ȸ����Ű��
		rotateornot[1] = true;
		if (d1[2] == d2[6]) {
			rotateornot[2] = false;
			return;
		}
		else {
			rotateornot[2] = true;
			if (d2[2] == d3[6]) {
				rotateornot[3] = false;
				return;
			}
			else {
				rotateornot[3] = true;
				if (d3[2] == d4[6]) {
					rotateornot[4] = false;
				}
				else {
					rotateornot[4] = true;
					return;
				}
			}
		}
	}

	if (num == 2) {
		rotateornot[2] = true;
		if (d1[2] == d2[6]) {
			rotateornot[1] = false;
		}
		else {
			rotateornot[1] = true;
		}

		if (d2[2] == d3[6]) {
			rotateornot[3] = false;
			return;
		}
		else {
			rotateornot[3] = true;
			if (d3[2] == d4[6]) {
				rotateornot[4] = false;
				return;
			}
			else {
				rotateornot[4] = true;
			}
		}
	}

	if (num == 3) {
		rotateornot[3] = true;

		if (d3[2] == d4[6]) {
			rotateornot[4] = false;
		}
		else {
			rotateornot[4] = true;
		}

		if (d2[2] == d3[6]) {
			rotateornot[2] = false;
			return;
		}
		else {
			rotateornot[2] = true;
			if (d1[2] == d2[6]) {
				rotateornot[1] = false;
				return;
			}
			else {
				rotateornot[1] = true;
				return;
			}
		}
	}

	if (num == 4) {
		rotateornot[4] = true;

		if (d3[2] == d4[6]) {
			rotateornot[3] = false;
			return;
		}
		else {
			rotateornot[3] = true;
			if (d2[2] == d3[6]) {
				rotateornot[2] = false;
				return;
			}
			else {
				rotateornot[2] = true;
				if (d1[2] == d2[6]) {
					rotateornot[1] = false;
				}
				else {
					rotateornot[1] = true;
				}
			}
		}
	}
}

void startrotate() { //ȸ����Ű��

	if (rotateornot[1]) {
		if (rotatedirection[1] == 1) { //�ð����
			d1.push_front(d1.back());
			d1.pop_back();
		}
		else {
			d1.push_back(d1.front());
			d1.pop_front();
		}
	}

	if (rotateornot[2]) {
		if (rotatedirection[2] == 1) { //�ð����
			d2.push_front(d2.back());
			d2.pop_back();
		}
		else {
			d2.push_back(d2.front());
			d2.pop_front();
		}
	}

	if (rotateornot[3]) {
		if (rotatedirection[3] == 1) {  //�ð����
			d3.push_front(d3.back());
			d3.pop_back();
		}
		else {
			d3.push_back(d3.front());
			d3.pop_front();
		}
	}

	if (rotateornot[4]) {
		if (rotatedirection[4] == 1) {  //�ð����
			d4.push_front(d4.back());
			d4.pop_back();
		}
		else {
			d4.push_back(d4.front());
			d4.pop_front();
		}
	}


}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 8; i++) {
		char num;
		cin >> num;
		d1.push_back(num);
	}

	for (int i = 0; i < 8; i++) {
		char num;
		cin >> num;
		d2.push_back(num);
	}

	for (int i = 0; i < 8; i++) {
		char num;
		cin >> num;
		d3.push_back(num);
	}

	for (int i = 0; i < 8; i++) {
		char num;
		cin >> num;
		d4.push_back(num);
	}

	cin >> k;

	for (int i = 0; i < k; i++) {
		int num, direction;
		cin >> num >> direction; //ȸ����ų ����� ��ȣ�� ����

		if (num % 2 != 0) {
			rotatedirection[1] = direction;
			rotatedirection[3] = direction;

			rotatedirection[2] = -1 * direction;
			rotatedirection[4] = -1 * direction;
		}
		else {
			rotatedirection[1] = -1 * direction;
			rotatedirection[3] = -1 * direction;

			rotatedirection[2] = direction;
			rotatedirection[4] = direction;
		}

		for (int i = 0; i < 5; i++) {
			rotateornot[i] = false;
		}

		isrotate(num);

		startrotate();

	}

	int answer = 0;
	if (d1[0] == '1') {
		answer += 1;
	}
	if (d2[0] == '1') {
		answer += 2;
	}
	if (d3[0] == '1') {
		answer += 4;
	}
	if (d4[0] == '1') {
		answer += 8;
	}

	cout <<  answer;

}