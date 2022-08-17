#include <iostream>

using namespace std;

int row;
int col;
int CAM_SIZE = 0;
int office[8][8];

int answer = 100;
struct CAM {
	int x, y, type;
};

CAM cam[8];

int rotation[5] = { 4,2,4,4,1 };

void update(int dir, CAM c) {

	dir %= 4;

	if (dir == 0) { //오른쪽
		for (int y = c.y + 1; y < col; y++) {
			if (office[c.x][y] == 6) {
				break;
			}
			office[c.x][y] = -1;
		}
	}
	else if (dir == 1) { //위쪽
		for (int x = c.x - 1; x >= 0; x--) {
			if (office[x][c.y] == 6) {
				break;
			}
			office[x][c.y] = -1;
		}
	}
	else if (dir == 2) { //왼쪽
		for (int y = c.y - 1; y >= 0; y--) {
			if (office[c.x][y] == 6) {
				break;
			}
			office[c.x][y] = -1;
		}
	}
	else if (dir == 3) { //아래쪽
		for (int x = c.x + 1; x < row; x++) {
			if (office[x][c.y] == 6) {
				break;
			}
			office[x][c.y] = -1;
		}
	}
}

void copy(int backup[8][8], int origin[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			backup[i][j] = origin[i][j];
		}
	}
}

void solve(int cam_idx) {
	

	if (cam_idx == CAM_SIZE) {

		int w = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (office[i][j] == 0) {
					w++;
				}
			}
		}

		if (answer > w) {
			answer = w;
		}
		return;
	}
	int type = cam[cam_idx].type;
	int backup[8][8];

	for (int dir = 0; dir < rotation[type]; dir++) {

		copy(backup, office);

		cout << "cam_idx: " << cam_idx << "\n";
		cout << "dir: " << dir << "\n";
		cout << "전 backup" << "\n";
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << backup[i][j] << ' ';
			}
			cout << "\n";
		}
		if (type == 0) {
			update(dir, cam[cam_idx]);
		}
		else if (type == 1) {
			update(dir, cam[cam_idx]);
			update(dir + 2, cam[cam_idx]);
		}
		else if (type == 2) {
			update(dir, cam[cam_idx]);
			update(dir + 1, cam[cam_idx]);
		}
		else if (type == 3) {
			update(dir, cam[cam_idx]);
			update(dir +1, cam[cam_idx]);
			update(dir +2, cam[cam_idx]);
		}
		else if (type == 4) {
			update(dir, cam[cam_idx]);
			update(dir + 1, cam[cam_idx]);
			update(dir + 2, cam[cam_idx]);
			update(dir + 3, cam[cam_idx]);
		}

		solve(cam_idx + 1);
		copy(office, backup);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> office[i][j];

			if (office[i][j] != 0 && office[i][j] != 6) {
				cam[CAM_SIZE].x = i;
				cam[CAM_SIZE].y = j;
				cam[CAM_SIZE].type = office[i][j] - 1; //0

				CAM_SIZE++;
			}

		}
	}

	solve(0);

	cout << answer;
}