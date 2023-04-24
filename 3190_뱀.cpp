#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

int n; //보드 크기
int k; //사과 개수
int l; //뱀의 방향 변환 횟수
bool apple[101][101];
int snake_dir = 2;
int snake_x = 1;
int snake_y = 1;

map<int, char> dir_info;
deque<pair<int, int>> snakes;

int times = 1;

bool inrange(int x, int y) {
//	cout << "n :" << n << "\n";
	if (1 <= x && x <= n && 1 <= y && y <= n) {
//		cout << "True" << "\n";
		return true;
	}
	return false;
}

void finish() {

	//cout << "finish" << "\n";
	cout << times;
	exit(0);
}

void check_bomb() {

	for (int i = 0; i < snakes.size(); i++) {
		if (snakes[i].first == snake_x && snakes[i].second == snake_y) {
			finish();
		}
	}

}
void up() {

	if (inrange(snake_x - 1, snake_y)) {
		snake_x -= 1;

		check_bomb();
		snakes.push_front({ snake_x, snake_y });

		if (!apple[snake_x][snake_y]) {
			snakes.pop_back();
		}
		else {
			apple[snake_x][snake_y] = false;
		}
	}
	else {
		finish();
	}

}

void down() {

	if (inrange(snake_x + 1, snake_y)) {
		snake_x += 1;
		check_bomb();

		snakes.push_front({ snake_x, snake_y });

		if (!apple[snake_x][snake_y]) {
			snakes.pop_back();
		}
		else {
			apple[snake_x][snake_y] = false;
		}
	}
	else {
		finish();
	}
}

void left() {

	if (inrange(snake_x, snake_y - 1)) {
		snake_y -= 1;
		check_bomb();
		snakes.push_front({ snake_x, snake_y });

		if (!apple[snake_x][snake_y]) {
			snakes.pop_back();
		}
		else {
			apple[snake_x][snake_y] = false;
		}
	}
	else {
		finish();
	}
}

void right() {

//	cout << "snake_x: " << snake_x << " snake_y: " << snake_y + 1 << "\n";
	if (inrange(snake_x, snake_y + 1)) {
		snake_y += 1;
		check_bomb();
		snakes.push_front({ snake_x, snake_y });

		if (!apple[snake_x][snake_y]) {
			snakes.pop_back();
		}
		else {
			apple[snake_x][snake_y] = false;
		}
	//	cout << "?" << "\n";
	}
	else {
		finish();
	}
}

void change_dir() {
	//방향을 바꾼다.

	if (dir_info.find(times) != dir_info.end()) {
		if (dir_info[times] == 'L') {
			//왼쪽으로 간다면
			if (2 <= snake_dir && snake_dir <= 4) {
				snake_dir--;
			}
			else {
				snake_dir = 4;
			}

		}
		else {
			//오른쪽으로 간다면
			if (1 <= snake_dir && snake_dir <= 3) {
				snake_dir++;
			}
			else {
				snake_dir = 1;
			}
		}
	}
}
void move() {
	//뱀이 이동한다.


//	cout << "dir: " << snake_dir << "\n";
	if (snake_dir == 1) { //상
		up();
	}
	else if (snake_dir == 2) { //우
		right();
	}
	else if (snake_dir == 3) { //하
		down();
	}
	else { //좌
		left();
	}

	change_dir();

}

void print() {

//	cout << "times: " << times << " -------- - print----------" << "\n";
	for (int i = 0; i < snakes.size(); i++) {
		cout << snakes[i].first << " " << snakes[i].second << "\n";
	}
}
void solution() {

	snakes.push_back({ 1,1 });

	for (times = 1;; times++) {
		move();
	//	print();
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
		int x;
		char c;
		cin >> x >> c;
		dir_info.insert({ x,c });
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}