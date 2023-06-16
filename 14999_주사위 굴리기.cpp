#include <iostream>
#include <vector>

using namespace std;

int n; //���� ũ��
int m; //���� ũ��

int map[21][21];
vector<int> v;

int x; //�ֻ��� ��
int y; //�ֻ��� ��
int k; //����� ����

int dice[6] = { 0,0,0,0,0,0 }; //�ֻ���

bool inrange(int x, int y) {

	if (0 <= x && x < n && 0 <= y && y < m) {
		return true;
	}

	return false;
}
void rotate(int dir) {

	int nx = x;
	int ny = y;

	if (dir == 1) { //��
		ny++;

		if (!inrange(nx, ny)) { //�ٱ����� �̵��Ѵٸ�
			return;
		}

		x = nx;
		y = ny;

		int new_dice[6] = { dice[0], dice[5], dice[1], dice[2], dice[4], dice[3] };

		for (int i = 0; i < 6; i++) {
			dice[i] = new_dice[i];
		}
	}
	else if (dir == 2) { //��
		ny--;

		if (!inrange(nx, ny)) {
			return;
		}

		x = nx;
		y = ny;

		int new_dice[6] = { dice[0], dice[2], dice[3], dice[5], dice[4], dice[1] };


		for (int i = 0; i < 6; i++) {
			dice[i] = new_dice[i];
		}
	}
	else if (dir == 3) { //��
		nx--;

		if (!inrange(nx, ny)) {
			return;
		}

		x = nx;
		y = ny;

		int new_dice[6] = { dice[2], dice[1], dice[4], dice[3], dice[5], dice[0] };
		
		for (int i = 0; i < 6; i++) {
			dice[i] = new_dice[i];
		}
	}
	else { //��
		nx++;

		if (!inrange(nx, ny)) {
			return;
		}

		x = nx;
		y = ny;

		int new_dice[6] = { dice[5], dice[1], dice[0], dice[3], dice[2], dice[4] };

		for (int i = 0; i < 6; i++) {
			dice[i] = new_dice[i];
		}
	}

	if (map[x][y] == 0) { //�̵��� ĭ�� �����ִ� ���� 0�̸�
		map[x][y] = dice[5]; //�ֻ����� �ٴڿ� �ִ� ���� ĭ�� �����
	}
	else {
		dice[5] = map[x][y]; //ĭ�� �����ִ� ���� �ֻ����� �ٴ����� �����
		map[x][y] = 0;
	}

	cout << dice[2] << "\n";

}
void solution() {

	for (int i = 0; i < k; i++) {
		rotate(v[i]);
	}

}

void input() {

	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}