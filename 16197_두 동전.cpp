#include <iostream>
#include <vector>

using namespace std;

int n; //���� ũ��
int m; //���� ũ��

char input_map[21][21];
char map[21][21];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int gusul1_x;
int gusul1_y;
bool gusul1_fall;

int gusul2_x;
int gusul2_y;
bool gusul2_fall;

vector<pair<int, int>> gusuls;
//�� : 1
//�� : 2
//�� : 3
//�� : 4

vector<int> dirs;

bool inrange(int x, int y) {

	if (1 <= x && x <= n && 1 <= y && y <= m) {
		return true;
	}
	return false;
}
void copy() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map[i][j] = input_map[i][j];
		}
	}
}
void up() { //��

	//����1�� ���� �������� �ʾҴٸ�
	if (!gusul1_fall) {
		//����1 ���� ���� �ȿ� �ְ�, ���� �ƴ϶��
		if (inrange(gusul1_x - 1, gusul1_y) && map[gusul1_x - 1][gusul1_y] != '#') {
			gusul1_x -= 1;
		}
		else if (!inrange(gusul1_x - 1, gusul1_y)) { //ĭ�� ������
			gusul1_fall = true; //�ٱ����� ��������.
		}
	}

	//����2�� ���� �������� �ʾҴٸ�
	if (!gusul2_fall) {
		//����1 ���� ���� �ȿ� �ְ�, ���� �ƴ϶��
		if (inrange(gusul2_x - 1, gusul2_y) && map[gusul2_x - 1][gusul2_y] != '#') {
			gusul2_x -= 1;
		}
		else if (!inrange(gusul2_x - 1, gusul2_y)) { //ĭ�� ������
			gusul2_fall = true; //�ٱ����� ��������.
		}
	}

}
void down() { //��

	//����1�� ���� �������� �ʾҴٸ�
	if (!gusul1_fall) {
		//����1 ���� ���� �ȿ� �ְ�, ���� �ƴ϶��
		if (inrange(gusul1_x + 1, gusul1_y) && map[gusul1_x + 1][gusul1_y] != '#') {
			gusul1_x += 1;
		}
		else if (!inrange(gusul1_x + 1, gusul1_y)) { //ĭ�� ������
			gusul1_fall = true; //�ٱ����� ��������.
		}
	}

	//����2�� ���� �������� �ʾҴٸ�
	if (!gusul2_fall) {
		//����1 ���� ���� �ȿ� �ְ�, ���� �ƴ϶��
		if (inrange(gusul2_x + 1, gusul2_y) && map[gusul2_x + 1][gusul2_y] != '#') {
			gusul2_x += 1;
		}
		else if (!inrange(gusul2_x + 1, gusul2_y)) { //ĭ�� ������
			gusul2_fall = true; //�ٱ����� ��������.
		}
	}
}
void left() { //��

	//����1�� ���� �������� �ʾҴٸ�
	if (!gusul1_fall) {
		//����1 ���� ���� �ȿ� �ְ�, ���� �ƴ϶��
		if (inrange(gusul1_x, gusul1_y - 1) && map[gusul1_x][gusul1_y - 1] != '#') {
			gusul1_y -= 1;
		}
		else if (!inrange(gusul1_x, gusul1_y - 1)) { //ĭ�� ������
			gusul1_fall = true; //�ٱ����� ��������.
		}
	}

	//����2�� ���� �������� �ʾҴٸ�
	if (!gusul2_fall) {
		//����1 ���� ���� �ȿ� �ְ�, ���� �ƴ϶��
		if (inrange(gusul2_x, gusul2_y - 1) && map[gusul2_x][gusul2_y - 1] != '#') {
			gusul2_y -= 1;
		}
		else if (!inrange(gusul2_x, gusul2_y - 1)) { //ĭ�� ������
			gusul2_fall = true; //�ٱ����� ��������.
		}
	}
}
void right() { //��

	//����1�� ���� �������� �ʾҴٸ�
	if (!gusul1_fall) {
		//����1 ���� ���� �ȿ� �ְ�, ���� �ƴ϶��
		if (inrange(gusul1_x , gusul1_y + 1) && map[gusul1_x][gusul1_y + 1] != '#') {
			gusul1_y += 1;
		}
		else if (!inrange(gusul1_x, gusul1_y + 1)) { //ĭ�� ������
			gusul1_fall = true; //�ٱ����� ��������.
		}
	}

	//����2�� ���� �������� �ʾҴٸ�
	if (!gusul2_fall) {
		//����1 ���� ���� �ȿ� �ְ�, ���� �ƴ϶��
		if (inrange(gusul2_x, gusul2_y + 1) && map[gusul2_x][gusul2_y + 1] != '#') {
			gusul2_y += 1;
		}
		else if (!inrange(gusul2_x, gusul2_y + 1)) { //ĭ�� ������
			gusul2_fall = true; //�ٱ����� ��������.
		}
	}
}

void reset() {


	gusul1_x = gusuls[0].first;
	gusul1_y = gusuls[0].second;
	gusul1_fall = false;

	gusul2_x = gusuls[1].first;
	gusul2_y = gusuls[1].second;
	gusul2_fall = false;

}
void check() {

	reset();
	for (int i = 0; i < dirs.size(); i++) {
		if (dirs[i] == 1) {
			up();
		}
		else if (dirs[i] == 2) {
			down();
		}
		else if (dirs[i] == 3) {
			left();
		}
		else {
			right();
		}
	}

	if (gusul1_fall && !gusul2_fall) {

		cout << dirs.size();
		exit(0);
	}

	if (!gusul1_fall && gusul2_fall) {
		cout << dirs.size();
		exit(0);
	}
}
void mini_solution(int cnt, int times) {
	//times��ŭ �̵���Ų��.

	if (cnt == times) {
		check();

		return;
	}

	dirs.push_back(1);
	mini_solution(cnt + 1, times);
	dirs.pop_back();

	dirs.push_back(2);
	mini_solution(cnt + 1, times);
	dirs.pop_back();

	dirs.push_back(3);
	mini_solution(cnt + 1, times);
	dirs.pop_back();

	dirs.push_back(4);
	mini_solution(cnt + 1, times);
	dirs.pop_back();


}
void solution() {

	gusul1_x = gusuls[0].first;
	gusul1_y = gusuls[0].second;
	gusul2_x = gusuls[1].first;
	gusul2_y = gusuls[1].second;

	for (int times = 1; times <= 10; times++) {
		dirs.clear();
		mini_solution(0, times);
	}

	cout << -1;
}
void input() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string st;
		cin >> st;
		for (int j = 1; j <= m; j++) {
			map[i][j] = st[j - 1];
			if (map[i][j] == 'o') {
				gusuls.push_back({ i,j });
			}
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