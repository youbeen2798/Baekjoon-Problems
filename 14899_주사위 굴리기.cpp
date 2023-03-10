#include <iostream>

using namespace std;

int n; //���� ũ��
int m; //���� ũ��
int x, y; //�ֻ��� ���� ���� ��ǥ
int k; //��� ����

int arr[21][21];

int dice[6] = { 0,0,0,0,0,0 };

void copy(int tmp_dice[6], int x, int y) {

	for (int i = 0; i < 6; i++) {
		dice[i] = tmp_dice[i];
	}

	if (arr[x][y] == 0) {
		arr[x][y] = dice[5];
	}
	else {
		//0�� �ƴ� ��쿡��
		dice[5] = arr[x][y];
		arr[x][y] = 0;
	}
	cout << dice[2] << "\n";
}
void move_east() {
	//����

	int ny = y + 1;
	if (0 <= ny && ny < m) {
		y = ny;
		int tmp_dice[6] = { dice[0], dice[5], dice[1], dice[2], dice[4], dice[3] };		
		copy(tmp_dice, x, ny);
	}
	
}

void move_west() {
	//����
	int ny = y - 1;
	if (0 <= ny && ny < m) {
		y = ny;
		int tmp_dice[6] = { dice[0], dice[2], dice[3], dice[5], dice[4], dice[1] };
		copy(tmp_dice, x, ny);
	}
}

void move_north() {
	//����
	int nx = x - 1;
	if (0 <= nx && nx < n) {
		x = nx;
		int tmp_dice[6] = { dice[2], dice[1], dice[4], dice[3], dice[5], dice[0] };
		copy(tmp_dice, nx, y);
	}
}


void move_south() {
	//����
	int nx = x + 1;
	if (0 <= nx && nx < n) {
		x = nx;
		int tmp_dice[6] = { dice[5], dice[1], dice[0] ,dice[3], dice[2], dice[4] }; 
		copy(tmp_dice, nx, y);
	}
}
void move(int order_num) {
	if (order_num == 1) {
		//����
		move_east();
	}
	else if (order_num == 2) {
		//����
		move_west();
	}
	else if (order_num == 3) {
		//����
		move_north();
	}
	else {
		//����
		move_south();
	}
}
void input() {
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int order_num;
		cin >> order_num;
		move(order_num);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}