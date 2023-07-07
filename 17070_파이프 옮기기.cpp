#include <iostream>

using namespace std;

int n; //���� ũ��
int map[17][17];

struct info {
	int end_x;
	int end_y;
	int type; //1: ����, 2: ����, 3: �밢��
};
int ans = 0;

bool inrange(int x, int y) {
	if (1 <= x && x <= n && 1 <= y && y <= n) {
		return true;
	}
	return false;
}
void connect(info i) {
	int end_x = i.end_x;
	int end_y = i.end_y;
	int type = i.type;

	if (!inrange(end_x, end_y)) {
		return;
	}

	if (end_x == n && end_y == n) {
		ans++;
	}

	if (type == 1) { //���ζ��

		//���ο��� ����
		if (map[end_x][end_y + 1] == 0) {
			connect({ end_x, end_y + 1, 1 });
		}

		//���ο��� �밢��
		if (map[end_x][end_y + 1] == 0 && map[end_x + 1][end_y] == 0 && map[end_x + 1][end_y + 1] == 0) {
			connect({ end_x + 1, end_y + 1, 3 });
		}

	}
	else if (type == 2) { //���ζ��

		if (map[end_x + 1][end_y] == 0) {
			connect({ end_x + 1, end_y, 2 });
		}

		if (map[end_x + 1][end_y] == 0 && map[end_x][end_y + 1] == 0 && map[end_x + 1][end_y + 1] == 0) {
			connect({ end_x + 1, end_y + 1, 3 });
		}
	}
	else if (type == 3) { //�밢���̶��

		//�밢������ ����
		if (map[end_x][end_y + 1] == 0) {
			connect({ end_x, end_y + 1, 1 });
		}

		//�밢������ ����
		if (map[end_x + 1][end_y] == 0) {
			connect({ end_x + 1, end_y, 2 });
		}

		//�밢������ �밢��
		if (map[end_x + 1][end_y] == 0 && map[end_x][end_y + 1] == 0 && map[end_x + 1][end_y + 1] == 0) {
			connect({ end_x + 1, end_y + 1, 3 });
		}
	}
}
void solution() {

	info i = { 1, 2, 1 };
	connect(i);
	cout << "ans: " << ans;

}

void input() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}