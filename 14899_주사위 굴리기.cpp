#include <iostream>

using namespace std;

int n; //세로 크기
int m; //가로 크기
int x, y; //주사위 놓은 곳의 좌표
int k; //명령 개수

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
		//0이 아닌 경우에는
		dice[5] = arr[x][y];
		arr[x][y] = 0;
	}
	cout << dice[2] << "\n";
}
void move_east() {
	//동쪽

	int ny = y + 1;
	if (0 <= ny && ny < m) {
		y = ny;
		int tmp_dice[6] = { dice[0], dice[5], dice[1], dice[2], dice[4], dice[3] };		
		copy(tmp_dice, x, ny);
	}
	
}

void move_west() {
	//서쪽
	int ny = y - 1;
	if (0 <= ny && ny < m) {
		y = ny;
		int tmp_dice[6] = { dice[0], dice[2], dice[3], dice[5], dice[4], dice[1] };
		copy(tmp_dice, x, ny);
	}
}

void move_north() {
	//북쪽
	int nx = x - 1;
	if (0 <= nx && nx < n) {
		x = nx;
		int tmp_dice[6] = { dice[2], dice[1], dice[4], dice[3], dice[5], dice[0] };
		copy(tmp_dice, nx, y);
	}
}


void move_south() {
	//남쪽
	int nx = x + 1;
	if (0 <= nx && nx < n) {
		x = nx;
		int tmp_dice[6] = { dice[5], dice[1], dice[0] ,dice[3], dice[2], dice[4] }; 
		copy(tmp_dice, nx, y);
	}
}
void move(int order_num) {
	if (order_num == 1) {
		//동쪽
		move_east();
	}
	else if (order_num == 2) {
		//서쪽
		move_west();
	}
	else if (order_num == 3) {
		//북쪽
		move_north();
	}
	else {
		//남쪽
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