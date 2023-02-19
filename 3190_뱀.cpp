#include <iostream>
#include <deque>
#include <set>
#include <map>

using namespace std;

int n; //보드 크기
int k; //사과 개수
int l; //뱀 방향 변환 횟수

deque<pair<int, int>> snakes; //뱀 위치
set<pair<int, int>> apples; //사과 위치
map<int, char> change_dir_info; //뱀의 방향 변환 정보

//뱀의 방향
// 0 : 오른쪽, 1 : 아래쪽, 2 : 왼쪽, 3 : 위쪽
int snake_dir = 0; 
int current_time = 0; //현재 시간
int snake_x = 1; //뱀 현재 위치 행
int snake_y = 1; //뱀 현재 위치 열

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

	//만약 범위 내에 없다면
	if (!inrange(snake_x, snake_y)) {
		finish();
	}

	//만약 뱀에게 부딪힌다면
	for (int i = 0; i < snakes.size(); i++) {
		if (snakes[i].first == snake_x && snakes[i].second == snake_y) {
			finish();
		}
	}


	
	snakes.push_back(current_snake_position);

	//만약 이동한 칸에 사과가 없다면
	if (apples.find(current_snake_position) == apples.end()) {
		snakes.pop_front();
	}
	else {
		apples.erase(current_snake_position);
	}
}

void change_dir() {
	//방향을 바꿀일이 있으면 방향을 바꾼다.

	if (change_dir_info.find(current_time) != change_dir_info.end()) {
		char dir = change_dir_info[current_time];

		if (dir == 'L') {
			//왼쪽으로 바꾼다면
			if (snake_dir == 0) {
				snake_dir += 3;
				return;
			}
			snake_dir--;
		}
		else {
			//오른쪽으로 바꾼다면
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
		snake_move(); //뱀이 이동한다.
		change_dir(); //방향을 바꿀 일이 있으면 방향을 바꾼다.
	}

}
void input() {

	cin >> n >> k;

	//사과 위치
	for (int i = 0; i < k; i++) {
		int x, y; //행과 열
		cin >> x >> y;
		apples.insert({ x,y });
	}

	cin >> l;

	// 방향 바꾸기
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