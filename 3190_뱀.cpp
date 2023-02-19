#include <iostream>
#include <deque>
#include <set>
#include <map>

using namespace std;

int n; //���� ũ��
int k; //��� ����
int l; //�� ���� ��ȯ Ƚ��

deque<pair<int, int>> snakes; //�� ��ġ
set<pair<int, int>> apples; //��� ��ġ
map<int, char> change_dir_info; //���� ���� ��ȯ ����

//���� ����
// 0 : ������, 1 : �Ʒ���, 2 : ����, 3 : ����
int snake_dir = 0; 
int current_time = 0; //���� �ð�
int snake_x = 1; //�� ���� ��ġ ��
int snake_y = 1; //�� ���� ��ġ ��

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

bool inrange(int x, int y) {
	if (1 <= x && x <= n && 1 <= y && y <= n) {
		return true;
	}
	return false;
}

void finish() {
	cout << current_time;
	exit(0);
}
void snake_move() {

	snake_x += dx[snake_dir];
	snake_y += dy[snake_dir];

	pair<int, int> current_snake_position = { snake_x, snake_y };

	//���� ���� ���� ���ٸ�
	if (!inrange(snake_x, snake_y)) {
		finish();
	}

	//���� �쿡�� �ε����ٸ�
	for (int i = 0; i < snakes.size(); i++) {
		if (snakes[i].first == snake_x && snakes[i].second == snake_y) {
			finish();
		}
	}


	
	snakes.push_back(current_snake_position);

	//���� �̵��� ĭ�� ����� ���ٸ�
	if (apples.find(current_snake_position) == apples.end()) {
		snakes.pop_front();
	}
	else {
		apples.erase(current_snake_position);
	}
}

void change_dir() {
	//������ �ٲ����� ������ ������ �ٲ۴�.

	if (change_dir_info.find(current_time) != change_dir_info.end()) {
		char dir = change_dir_info[current_time];

		if (dir == 'L') {
			//�������� �ٲ۴ٸ�
			if (snake_dir == 0) {
				snake_dir += 3;
				return;
			}
			snake_dir--;
		}
		else {
			//���������� �ٲ۴ٸ�
			if (snake_dir == 3) {
				snake_dir -= 3;
				return;
			}
			snake_dir++;
		}
	}
}


void solution() {

	snakes.push_back({ 1,1 });

	while(true) {
		current_time++;
		snake_move(); //���� �̵��Ѵ�.
		change_dir(); //������ �ٲ� ���� ������ ������ �ٲ۴�.
	}

}
void input() {

	cin >> n >> k;

	//��� ��ġ
	for (int i = 0; i < k; i++) {
		int x, y; //��� ��
		cin >> x >> y;
		apples.insert({ x,y });
	}

	cin >> l;

	// ���� �ٲٱ�
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		change_dir_info.insert({ x,c });
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}