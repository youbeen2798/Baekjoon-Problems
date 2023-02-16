#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r; //������ �� ũ��
int c; //������ �� ũ��
int m; //��� ��
int real_ans = 0; // ����

struct shark_info {

	int speed; //�ӷ�
	int dir; //�̵�����
	int z; //ũ��

	bool operator<(shark_info a) {
		return z > a.z;
	}
};

vector<shark_info> arr[101][101]; //������
vector<shark_info> tmp[101][101]; //�� ������ �� ������

int col; //���� ���ÿ� �� ����

int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };

void catch_closet_shark() {
	//���ÿ��� �ִ� ���� �ִ� ��� �߿��� ���� ���� ����� �� ��´�. 
	//�� ������ �����ǿ��� ���� �� �������.

	for (int row = 1; row <= r; row++) {
		if (arr[row][col].size() > 0) {
			real_ans += arr[row][col][0].z; //���� ����� ũ��
			arr[row][col].clear();
			break;
		}
	}
}

int change_dir(int dir) {
	if (dir % 2 != 0) {
		dir += 1;
	}
	else {
		dir -= 1;
	}
	return dir;
}

void move(int x, int y) {
	//(x,y)�� �ִ� �� �̵��Ѵ�.
	int dir = arr[x][y][0].dir; //����
	int speed = arr[x][y][0].speed; //�ӵ�
	int size = arr[x][y][0].z; //ũ��

	int now_x = x; //��
	int now_y = y; //��

	if (dir <= 2) { //�� �Ʒ����

		speed %= ( 2 * r - 2);
	}
	else {
		speed %= (2 * c - 2);
	}

	for (int i = 0; i < speed; i++) {
		int nx = now_x + dx[dir]; //���ο� ��
		int ny = now_y + dy[dir]; //���ο� ��

		if (1 <= nx && nx <= r && 1 <= ny && ny <= c) {
			now_x = nx;
			now_y = ny;
		}
		else {
			dir = change_dir(dir);
			i--;
		}
	}

	//3, speed = 1���� Ȯ��
	if (tmp[now_x][now_y].size() > 0) {
		int already_shark_size = tmp[now_x][now_y][0].z; //�̹� ����ִ� ��� ������
		if (already_shark_size < size) { //�̹� ����ִ� ��� ����� ���� ��� ������� �۴ٸ�
			tmp[now_x][now_y].clear();
		}
	}
	tmp[now_x][now_y].push_back({ speed, dir,  size });
}


void all_shark_move() {
	// �� �̵��Ѵ�.

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j].size() > 0) {
				move(i, j);
			}
		}
	}
}


void copy() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j].size() > 0) {
				arr[i][j].clear();
			}
			arr[i][j] = tmp[i][j];
			tmp[i][j].clear();
		}
	}
}

void solution() {

	for (col = 1; col <= c; col++) {
		//���ÿ��� ���������� �� ĭ �̵��Ѵ�.
		catch_closet_shark();
		all_shark_move();
		copy();
	}

	cout << real_ans;
}
void input() {

	cin >> r >> c >> m;

	for (int i = 0; i < m; i++) {
		int r, c, s, d, z; //��, ��, �ӷ�, �̵�����, ũ��
		cin >> r >> c >> s >> d >> z;
		arr[r][c].push_back({ s,d,z }); //�ӷ�, �̵�����, ũ��
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}