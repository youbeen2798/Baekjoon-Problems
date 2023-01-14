#include <iostream>

using namespace std;

int n, m; //���� ũ��, ���� ũ��
int current_x = 0;
int current_y = 0; //�ֻ��� ���� ���� ��ǥ
int k; //����� ����
int move_dirs[1001]; //����� ���� ��
int dice[6] = { 0,0,0,0,0,0 }; //�ֻ���
int board[21][21]; //����

void copy(int tmp_dice[6], int dice[6]) {
	for (int i = 0; i < 6; i++) {
		dice[i] = tmp_dice[i];
	}
}
void dice_rotation(int move_dir) { //�ֻ��� ȸ��
	int tmp_dice[6];
	if (move_dir == 1) { //�������� �̵��Ѵٸ�
		tmp_dice[0] = dice[0];
		tmp_dice[1] = dice[5];
		tmp_dice[2] = dice[1];
		tmp_dice[3] = dice[2];
		tmp_dice[4] = dice[4];
		tmp_dice[5] = dice[3];
	}
	else if (move_dir == 2) { //�������� �̵��Ѵٸ�
		tmp_dice[0] = dice[0];
		tmp_dice[1] = dice[2];
		tmp_dice[2] = dice[3];
		tmp_dice[3] = dice[5];
		tmp_dice[4] = dice[4];
		tmp_dice[5] = dice[1]; 
	}
	else if (move_dir == 3) { //�������� �̵��Ѵٸ�
		tmp_dice[0] = dice[2];
		tmp_dice[1] = dice[1];
		tmp_dice[2] = dice[4];
		tmp_dice[3] = dice[3];
		tmp_dice[4] = dice[5];
		tmp_dice[5] = dice[0];
	}
	else { //�������� �̵��Ѵٸ�
		tmp_dice[0] = dice[5];
		tmp_dice[1] = dice[1];
		tmp_dice[2] = dice[0];
		tmp_dice[3] = dice[3];
		tmp_dice[4] = dice[2];
		tmp_dice[5] = dice[4];
	}
	copy(tmp_dice, dice); //�̵��ؼ� �ֻ��� ��ġ �ٲٱ�
}

void dice_move(int move_dir) { //�ֻ��� �̵���Ű��
	if (move_dir == 1) { //�������� �̵��Ѵٸ�
		if (current_y + 1 < m) { //�ٱ������� �̵����� �ʴ´ٸ�
			current_y += 1;
		}
		else {
			return;
		}
	}
	else if (move_dir == 2) { //�������� �̵��Ѵٸ�
		if (current_y - 1 >= 0) { //�ٱ������� �̵����� �ʴ´ٸ�
			current_y -= 1;
		}
		else {
			return;
		}

	}
	else if (move_dir == 3) { //�������� �̵��Ѵٸ�
		if (current_x - 1 >= 0) { //�ٱ������� �̵����� �ʴ´ٸ�
			current_x -= 1;
		}
		else {
			return;
		}
	}
	else { //�������� �̵��Ѵٸ�
		if (current_x + 1 < n) { //�ٱ������� �̵����� �ʴ´ٸ�
			current_x += 1;
		}
		else{
			return;
		}
	}
	dice_rotation(move_dir); //�ֻ��� ȸ��
	if (board[current_x][current_y] == 0) { //�ֻ����� �̵��� ĭ�� ���� �ִ� ���� 0�̸�
		board[current_x][current_y] = dice[5]; //�ֻ����� �ٴڸ鿡 ���� �ִ� ���� ����ȴ�
	}
	else { //�ֻ����� �̵��� ĭ�� ���� �ִ� ���� 0�� �ƴϸ�
		dice[5] = board[current_x][current_y]; //ĭ�� ���� �ִ� ���� �ֻ��� �ٴڸ����� ����
		board[current_x][current_y] = 0; //ĭ�� ���� �ִ� ���� 0�� ��
	}
	cout << dice[2] << "\n";
}
void solution() {
	for (int i = 0; i < k; i++) {
		int move_dir = move_dirs[i]; //�̵� ����
		dice_move(move_dir); //�ֻ��� �̵���Ű��
	}
}

void input() {
	
	cin >> n >> m; //���� ũ��, ���� ũ��

	cin >> current_x >> current_y; //�ֻ��� ���� ���� ��ǥ x, y
	cin >> k; //����� ����

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