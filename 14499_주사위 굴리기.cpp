#include <iostream>

using namespace std;

int n, m; //세로 크기, 가로 크기
int current_x = 0;
int current_y = 0; //주사위 놓은 곳의 좌표
int k; //명령의 개수
int move_dirs[1001]; //명령이 담기는 곳
int dice[6] = { 0,0,0,0,0,0 }; //주사위
int board[21][21]; //지도

void copy(int tmp_dice[6], int dice[6]) {
	for (int i = 0; i < 6; i++) {
		dice[i] = tmp_dice[i];
	}
}
void dice_rotation(int move_dir) { //주사위 회전
	int tmp_dice[6];
	if (move_dir == 1) { //동쪽으로 이동한다면
		tmp_dice[0] = dice[0];
		tmp_dice[1] = dice[5];
		tmp_dice[2] = dice[1];
		tmp_dice[3] = dice[2];
		tmp_dice[4] = dice[4];
		tmp_dice[5] = dice[3];
	}
	else if (move_dir == 2) { //서쪽으로 이동한다면
		tmp_dice[0] = dice[0];
		tmp_dice[1] = dice[2];
		tmp_dice[2] = dice[3];
		tmp_dice[3] = dice[5];
		tmp_dice[4] = dice[4];
		tmp_dice[5] = dice[1]; 
	}
	else if (move_dir == 3) { //북쪽으로 이동한다면
		tmp_dice[0] = dice[2];
		tmp_dice[1] = dice[1];
		tmp_dice[2] = dice[4];
		tmp_dice[3] = dice[3];
		tmp_dice[4] = dice[5];
		tmp_dice[5] = dice[0];
	}
	else { //남쪽으로 이동한다면
		tmp_dice[0] = dice[5];
		tmp_dice[1] = dice[1];
		tmp_dice[2] = dice[0];
		tmp_dice[3] = dice[3];
		tmp_dice[4] = dice[2];
		tmp_dice[5] = dice[4];
	}
	copy(tmp_dice, dice); //이동해서 주사위 위치 바꾸기
}

void dice_move(int move_dir) { //주사위 이동시키기
	if (move_dir == 1) { //동쪽으로 이동한다면
		if (current_y + 1 < m) { //바깥쪽으로 이동하지 않는다면
			current_y += 1;
		}
		else {
			return;
		}
	}
	else if (move_dir == 2) { //서쪽으로 이동한다면
		if (current_y - 1 >= 0) { //바깥쪽으로 이동하지 않는다면
			current_y -= 1;
		}
		else {
			return;
		}

	}
	else if (move_dir == 3) { //북쪽으로 이동한다면
		if (current_x - 1 >= 0) { //바깥쪽으로 이동하지 않는다면
			current_x -= 1;
		}
		else {
			return;
		}
	}
	else { //남쪽으로 이동한다면
		if (current_x + 1 < n) { //바깥쪽으로 이동하지 않는다면
			current_x += 1;
		}
		else{
			return;
		}
	}
	dice_rotation(move_dir); //주사위 회전
	if (board[current_x][current_y] == 0) { //주사위가 이동한 칸에 쓰여 있는 수가 0이면
		board[current_x][current_y] = dice[5]; //주사위의 바닥면에 쓰여 있는 수가 복사된다
	}
	else { //주사위가 이동한 칸에 쓰여 있는 수가 0이 아니면
		dice[5] = board[current_x][current_y]; //칸에 쓰여 있는 수가 주사위 바닥면으로 복사
		board[current_x][current_y] = 0; //칸에 쓰여 있는 수가 0이 됨
	}
	cout << dice[2] << "\n";
}
void solution() {
	for (int i = 0; i < k; i++) {
		int move_dir = move_dirs[i]; //이동 방향
		dice_move(move_dir); //주사위 이동시키기
	}
}

void input() {
	
	cin >> n >> m; //세로 크기, 가로 크기

	cin >> current_x >> current_y; //주사위 놓은 곳의 좌표 x, y
	cin >> k; //명령의 개수

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> move_dirs[i];
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}