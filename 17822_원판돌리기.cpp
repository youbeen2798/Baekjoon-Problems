#include <iostream>
#include <deque>
using namespace std;

int n, m, t;
deque <int> dq[51];
deque <bool> bool_dq[51];

void rotate(int xi, int di, int ki) {

	//��ȣ�� xi�� ����� ������ di�������� kiĭ ȸ��
	for (int i = 1; i <= n; i++) {
		if (i % xi == 0) { //��ȣ�� xi�� ����� ������
			if (di == 0) { //�ð����
				for (int j = 0; j < ki; j++) {
					//1 2 3 4 => 4 1 2 3
					int tmp_num = dq[i].back();
					dq[i].pop_back();
					dq[i].push_front(tmp_num);
				}
			}
			else if (di == 1) { //�ݽð����
				for (int j = 0; j < ki; j++) {
					int tmp_num = dq[i].front();
					dq[i].pop_front();
					dq[i].push_back(tmp_num);
				}
			}

		}
	}

}



void make_bool_dq_false() {
	for (int i = 1; i <= n; i++) {
		bool_dq[i].clear();
		for (int j = 0; j < m; j++) {
			bool_dq[i].push_back(false);
		}
	}
}
void erase() {

	make_bool_dq_false();

	//����
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {

			int num1 = dq[i][j]; //dq[1][2]
			int num2 = dq[i + 1][j]; //dq[2][2]

			if (num1 == num2 && num1 != -1) {
				bool_dq[i][j] = true;
				bool_dq[i + 1][j] = true;
			}
		}
	}

	//�Ʒ���
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int num1 = dq[i][j];
			int num2 = dq[i - 1][j];

			if (num1 == num2 && num1 != -1) {
				bool_dq[i][j] = true;
				bool_dq[i - 1][j] = true;
			}
		}
	}

	//����, ������
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m - 1; j++) {
			int num1 = dq[i][j];
			int num2 = dq[i][j + 1];
			
			if (num1 == num2 && num1 != -1) {
				bool_dq[i][j] = true;
				bool_dq[i][j + 1] = true;
			}
		}
		if (dq[i][0] == dq[i][m - 1] && dq[i][0] != -1) {
			bool_dq[i][0] = true;
			bool_dq[i][m - 1] = true;
		}
	}

	bool flag = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (bool_dq[i][j]) {
				flag = false;
				dq[i][j] = -1;
			}
		}
	}

	if (flag) { // ������ ���� ���ٸ�
		double sum = 0;
		double num = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (dq[i][j] != -1) {
					sum += dq[i][j];
					num++;
				}
			}
		}

		double average = sum / num;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				//��պ��� ũ�ٸ�
				if (average < (double)dq[i][j] && dq[i][j] != -1) {
					dq[i][j] -= 1;
				}
				//��պ��� �۴ٸ�
				else if ((double)dq[i][j] < average && dq[i][j] != -1) {
					dq[i][j] += 1;
				}
			}
		}
	}
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
		//��ȣ�� xi�� ����� ������ di�������� kiĭ ȸ��
		rotate(xi, di, ki);
		erase();
	}
}

void output() {

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (dq[i][j] != -1) {
				answer += dq[i][j];
			}
		}
	}
	cout << answer;
}


int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);

	input();
	output();

	
}