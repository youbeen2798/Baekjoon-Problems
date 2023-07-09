#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n; //���� ũ��
int k; //��� ����
int l; //���� ���� ��ȯ Ƚ��

bool apple[101][101];
bool snake[101][101];
char dir_change_info[10001];


vector<pair<int, char>> info;
int times = 1;
int snake_dir = 2; //1: ��, 2: ��, 3: ��, 4: ��

deque<pair<int, int>> snakes;

bool inrange(int x, int y) {
	if (1 <= x && x <= n && 1 <= y && y <= n) {
		return true;
	}
	return false;
}
void move() {

	//���� ���� �����̸� �÷� �Ӹ��� ���� ĭ�� ��ġ��Ų��.
	pair<int, int> snake_head = snakes.front();

	int snake_head_x = snake_head.first;
	int snake_head_y = snake_head.second;

	if (snake_dir == 1) { //��

		//������ �ε����� �ʰ�, �ڱ� �ڽ��� ���� �ε������� �ʴ´ٸ�
		if (inrange(snake_head_x - 1, snake_head_y) && !snake[snake_head_x - 1][snake_head_y]) {
			snakes.push_front({ snake_head_x - 1, snake_head_y });
			snake[snake_head_x - 1][snake_head_y] = true;

			snake_head_x -= 1;

		}
		else {
			cout << times;
			exit(0);
		}
	}
	else if (snake_dir == 2) { //��
		//������ �ε����� �ʰ�, �ڱ� �ڽ��� ���� �ε������� �ʴ´ٸ�

		if (inrange(snake_head_x, snake_head_y + 1) && !snake[snake_head_x][snake_head_y + 1]) {
			snakes.push_front({ snake_head_x, snake_head_y + 1 });
			snake[snake_head_x][snake_head_y + 1] = true;

			snake_head_y += 1;
		}
		else {
			cout << times;
			exit(0);
		}

	}
	else if (snake_dir == 3) { //��
		//������ �ε����� �ʰ�, �ڱ� �ڽ��� ���� �ε������� �ʴ´ٸ�
		if (inrange(snake_head_x + 1, snake_head_y) && !snake[snake_head_x + 1][snake_head_y]) {
			snakes.push_front({ snake_head_x + 1, snake_head_y });
			snake[snake_head_x + 1][snake_head_y] = true;

			snake_head_x += 1;

		}
		else {
			cout << times;
			exit(0);
		}
	}
	else if (snake_dir == 4) { //��
		//������ �ε����� �ʰ�, �ڱ� �ڽ��� ���� �ε������� �ʴ´ٸ�
		if (inrange(snake_head_x, snake_head_y - 1) && !snake[snake_head_x][snake_head_y - 1]) {
			snakes.push_front({ snake_head_x, snake_head_y - 1 });
			snake[snake_head_x][snake_head_y - 1] = true;

			snake_head_y -= 1;

		}
		else {
			cout << times;
			exit(0);
		}
	}


	//���� ����� �ִٸ�
	if (apple[snake_head_x][snake_head_y]) {

		//�� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
		apple[snake_head_x][snake_head_y] = false;
	}
	else {
		//���� ����� ���ٸ� �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�.
		pair<int, int> snake_tail = snakes.back();
		snakes.pop_back();
		snake[snake_tail.first][snake_tail.second] = false;
	}
}

void dir_change(char dir) {
	//������ �ٲ۴�.

	if (dir == 'L') {
		if (2 <= snake_dir && snake_dir <= 4) {
			snake_dir -= 1;
		}
		else {
			snake_dir = 4;
		}
	}
	else if (dir == 'D') {
		if (1 <= snake_dir && snake_dir <= 3) {
			snake_dir += 1;
		}
		else {
			snake_dir = 1;
		}
	}
}
void solution() {

	snake[1][1] = true;
	snakes.push_back({ 1,1 });

	for (times = 1;; times++) {
		move();

		if (dir_change_info[times] == 'L' || dir_change_info[times] == 'D') {
			dir_change(dir_change_info[times]);
		}
		
	}
}
void input() {

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int x, y; 
		cin >> x >> y;
		apple[x][y] = true;
	}

	cin >> l;

	for (int i = 0; i < l; i++) {
		int time;
		char dir;
		cin >> time >> dir;
		dir_change_info[time] = dir;
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}