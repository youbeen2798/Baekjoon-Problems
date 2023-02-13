#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; //체스판 크기
int k; //말 개수
int arr[13][13]; //체스판 정보 (0 - 흰색, 1 - 빨간색, 2 - 파란색)
vector<int> horse_arr[13][13]; //각 자리에 들어있는 말 번호 정보
int tc = 1;

struct info {
	int x; //행
	int y; //열
	int dir; //방향
};
// 1- 오른쪽, 2- 왼쪽, 3- 위쪽, 4- 아래쪽

info horses[11];

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

bool in_round(int x, int y) {
	if (1 <= x && x <= n && 1 <= y && y <= n) {
		return true;
	}
	return false;
}
bool one_horse_move(int horse_num) {
	//리턴 값이 true이면 다시 한번 수행

	int dir = horses[horse_num].dir; // 말 방향
	int x = horses[horse_num].x; //말 행
	int y = horses[horse_num].y; //말 열
	vector<int> horse_nums = horse_arr[x][y]; //원래 자리에 있던 말 정보


	int nx = x + dx[dir]; //움직일 말 행
	int ny = y + dy[dir]; //움직일 말 열

	if (in_round(nx, ny) && arr[nx][ny] == 0) {
		//이동하려는 칸이 흰색이라면
		int horse_idx = find(horse_nums.begin(), horse_nums.end(), horse_num) - horse_nums.begin();

		vector <int> moving_horses;

		int size = horse_arr[x][y].size();
		for (int i = size - 1; i >= horse_idx; i--) {
			int num = horse_arr[x][y].back();
			moving_horses.push_back(num);
			horse_arr[x][y].pop_back();
		}

		reverse(moving_horses.begin(), moving_horses.end());

		for (int i = 0; i < moving_horses.size(); i++) {
			int horse_num = moving_horses[i];
			horse_arr[nx][ny].push_back(horse_num);
			horses[horse_num].x = nx; //말 행
			horses[horse_num].y = ny; //말 열
		}

		if (horse_arr[nx][ny].size() >= 4) {
			cout << tc << "\n";
			exit(0);
		}
	}
	else if (in_round(nx, ny) && arr[nx][ny] == 1) {
		//이동하려는 칸이 빨간색이라면
		int horse_idx = find(horse_nums.begin(), horse_nums.end(), horse_num) - horse_nums.begin();

		vector <int> moving_horses;

		int size = horse_arr[x][y].size();
		for (int i = size - 1; i >= horse_idx; i--) {
			int num = horse_arr[x][y].back();
			moving_horses.push_back(num);
			horse_arr[x][y].pop_back();
		}

		for (int i = 0; i < moving_horses.size(); i++) {
			int horse_num = moving_horses[i];
			horse_arr[nx][ny].push_back(horse_num);
			horses[horse_num].x = nx; //말 행
			horses[horse_num].y = ny; //말 열
		}

		if (horse_arr[nx][ny].size() >= 4) {
			cout << tc << "\n";
			exit(0);
		}
	}
	else {
		//이동하려는 칸이 파란색이라면

		if (dir % 2 == 0) {
			horses[horse_num].dir -= 1;
		}
		else {
			horses[horse_num].dir += 1;
		}

		dir = horses[horse_num].dir; //바꾼 방향

		int nx = x + dx[dir]; //움직일 말 행
		int ny = y + dy[dir]; //움직일 말 열

		//움직일 곳이 체스 안에 파란색이 아니라면
		if (1 <= nx && nx <= n && 1<= ny && ny <= n && arr[nx][ny] != 2) { 
			return true;
		}
	}
	return false;
}

void all_horse_move() {
	for (int i = 1; i <= k; i++) {
		bool again = one_horse_move(i);
		if (again) {
			one_horse_move(i);
		}
	}
}
void solution() {

	for (tc = 1; tc <= 1000 ; tc++) {
		all_horse_move();
	}
	
	cout << -1;
}

void input() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i <= k; i++) {
		int x;
		int y;
		int dir;
		cin >> x >> y >> dir;
		horses[i] = { x,y,dir };
		horse_arr[x][y].push_back(i);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}