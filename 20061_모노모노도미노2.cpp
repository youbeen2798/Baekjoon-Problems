#include <iostream>

using namespace std;

int n; //블록을 놓은 횟수
bool arr[10][10];
int score = 0;

void blue(int type, int x, int y) {

	if (type == 1) {
		int ny; //열만 이동
		for (int i = 4; i <= 9; i++) {
			if (!arr[x][i]) {
				ny = i;
				continue;
			}
			break;
		}
		arr[x][ny] = true;
	}
	else if (type == 2) {
		int ny; //열만 이동
		for (int i = 4; i <= 8; i++) {
			if (!arr[x][i] && !arr[x][i+1]) {
				ny = i;
				continue;
			}
			break;
		}
		arr[x][ny] = true;
		arr[x][ny + 1] = true;
	}
	else if (type == 3) {
		int ny; //열만 이동
		for (int i = 4; i <= 9; i++) {
			if (!arr[x][i] && !arr[x + 1][i]) {
				ny = i;
				continue;
			}
			break;
		}
		arr[x][ny] = true;
		arr[x + 1][ny] = true;
	}
}

void green(int type, int x, int y) {
	if (type == 1) {
		//t = 1 : 크기가 1 x 1인 블록을 (x,y)에 놓은 경우
		int nx;
		for (int i = 4; i <= 9; i++) {
			if (!arr[i][y]) {
				nx = i;
				continue;
			}
			break;
		}
		arr[nx][y] = true;
	}
	else if (type == 2) {
		//t = 2 : 크기가 1 x 2인 블록을 (x,y), (x,y+1)에 놓은 경우
		int nx;
		for (int i = 4; i <= 9; i++) {
			if (!arr[i][y] && !arr[i][y + 1]) {
				nx = i;
				continue;
			}
			break;
		}
		arr[nx][y] = true;
		arr[nx][y + 1] = true;
	}
	else {
		//t = 3 : 크기가 2 x 1인 블록을 (x,y), (x+1,y)에 놓은 경우
		int nx;
		for (int i = 4; i <= 8; i++) {
			if (!arr[i][y] && !arr[i + 1][y]) {
				nx = i;
				continue;
			}
			break;
		}
		arr[nx][y] = true;
		arr[nx + 1][y] = true;
	}
}

bool check_blue_line() {
	//파란색 열이 쭉 찼는지 체크

	bool flag = false;

	int tmp[4][6] = { 0, };
	int y = 5;
	for (int i = 9; i >= 4; i--) {
		if (arr[0][i] && arr[1][i] && arr[2][i] && arr[3][i]) {
			score++;
			flag = true;
			continue;
		}
		tmp[0][y] = arr[0][i];
		tmp[1][y] = arr[1][i];
		tmp[2][y] = arr[2][i];
		tmp[3][y] = arr[3][i];
		y--;
	}

	for (int i = 0; i <= 3; i++) {
		for (int j = 4; j <= 9; j++) {
			arr[i][j] = tmp[i][j-4];
		}
	}

	if (flag) {
		return true;
	}
	return false;
}

bool check_green_line() {
	//초록색 열이 쭉 찼는지 체크
	
	bool flag = false; //바뀌었는지 체크

	int tmp[6][4] = { 0, };

	int x = 5;
	for (int i = 9; i >= 4; i--) {
		if (arr[i][0] && arr[i][1] && arr[i][2] && arr[i][3]) {
			score++;
			flag = true;
			continue;
		}
		tmp[x][0] = arr[i][0];
		tmp[x][1] = arr[i][1];
		tmp[x][2] = arr[i][2];
		tmp[x][3] = arr[i][3];
		x--;
	}

	for (int i = 9; i >= 4; i--) {
		for (int j = 0; j <= 3; j++) {
			arr[i][j] = tmp[i - 4][j];
		}
	}

	if (flag) {
		return true;
	}
	return false;
}


void little_green_line() {

	int num = 0;
	int tmp[6][4] = { 0, };

	for (int j = 4; j <= 5; j++) {
		if (arr[j][0] || arr[j][1] || arr[j][2] || arr[j][3]) {
			num++;
		}
	}

	int y = 5;
	for (int i = 9 - num; i >= 4; i--) {
		tmp[y][0] = arr[i][0];
		tmp[y][1] = arr[i][1];
		tmp[y][2] = arr[i][2];
		tmp[y][3] = arr[i][3];
		y--;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i + 4][j] = tmp[i][j];
		}
	}
}

void little_blue_line() {

	int num = 0;
	int tmp[4][6] = { 0, };

	for (int j = 4; j <= 5; j++) {
		if (arr[0][j] || arr[1][j] || arr[2][j] || arr[3][j]) {
			num++;
		}
	}

	int y = 5;
	for (int i = 9 - num; i >= 4; i--) {
		tmp[0][y] = arr[0][i];
		tmp[1][y] = arr[1][i];
		tmp[2][y] = arr[2][i];
		tmp[3][y] = arr[3][i];
		y--;
	}
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			arr[i][j + 4] = tmp[i][j];
		}
	}
}
void move(int type, int x, int y) {

	blue(type, x, y);
	green(type, x, y);

	while (true) {
		bool flag = check_blue_line();
		if (!flag) {
			break;
		}
	}

	while (true) {
		bool flag = check_green_line();
		if (!flag) {
			break;
		}
	}
	little_blue_line();
	little_green_line();
}

void output() {

	int blue_ans = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 4; j <= 9; j++) {
			if (arr[i][j]) {
				blue_ans++;
			}
		}
	}

	int green_ans = 0;
	for (int i = 4; i <= 9; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j]) {
				green_ans++;
			}
		}
	}


	cout << score << "\n";

	cout << green_ans + blue_ans<< "\n";
}
void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		int x;
		int y;
		cin >> t >> x >> y;
		move(t, x, y);
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	output();
}