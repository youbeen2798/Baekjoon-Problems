#include <iostream>

using namespace std;

int n, m, k;
int board[21][21];
pair<int, int> smell[21][21];

//위 아래 왼쪽 오른쪽
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };

struct Shark {
	bool dead;
	int x;
	int y;
	int dir;
	int Rank[5][4];
};

Shark shark[401];

bool valid(int x, int y) {
	if (0 <= x && x < n && 0 <= y && y < n) {
		return true;
	}
	return false;
}

void remove_smell() {


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			//이번에 생긴 냄새 빼고 다 냄새 마이너스하기!
			if (smell[i][j].second != 0 && board[i][j] == 0) {
				if (smell[i][j].second > 1) {
					smell[i][j].second--;
				}
				else {
					smell[i][j] = { 0,0 };
				}
			}
		}
	}
}
void moving() {

	//모든 상어마다
	for (int i = 1; i <= m; i++) {

		//상어가 죽지 않았을 경우만 이동
		if (!shark[i].dead) {

			//상어의 위치와 방향 
			int x = shark[i].x;
			int y = shark[i].y;
			int dir = shark[i].dir;
			bool found = false;

			//움직인 위치에 냄새가 없다면 이동
			for (int j = 0; j < 4; j++) {
				found = false;
				//우선순위에 따라 이동한 위치와 방향
				int f_dir = shark[i].Rank[dir][j];
				int tx = x + dx[f_dir];
				int ty = y + dy[f_dir];

				//냄새가 없다면
				if (valid(tx, ty) && smell[tx][ty].first == 0) {

					//움직이려고 하는 칸에 상어가 존재한다면
					//냄새가 없는데 상어가 존재한다는 것은, 이번 타임에 이동한 상어임
					//따라서 내가 우선순위가 낮으므로 내가 죽음
					if (board[tx][ty] != 0) {
						board[x][y] = 0;
						shark[i].dead = true;
						found = true;
					}
					else {
						board[x][y] = 0; //원래 있던 위치는 지움
						board[tx][ty] = i;
						shark[i].x = tx; //상어 위치 갱신
						shark[i].y = ty;
						shark[i].dir = f_dir;
						found = true;
					}
					break;
				}
			}
			if (!found) { //위치를 못 찾았다면
				for (int j = 0; j < 4; j++) {

					//우선순위에 따른 방향과 위치
					int f_dir = shark[i].Rank[dir][j];
					int tx = x + dx[f_dir];
					int ty = y + dy[f_dir];

					//나의 냄새가 새겨져 있다면
					if (valid(tx, ty) && smell[tx][ty].first == i) {
						board[x][y] = 0;
						board[tx][ty] = i;
						shark[i].x = tx;
						shark[i].y = ty;
						shark[i].dir = f_dir;
						break;
					}
				}
			}
		}
	}

	//상어들의 냄새 남기기
	for (int i = 1; i <= m; i++) {

		//죽지 않은 상어들에 대해서만
		if (!shark[i].dead) {
			int x = shark[i].x;
			int y = shark[i].y;

			smell[x][y] = { i, k };
		}
	}
}
int simulation() {

	int time = 0;

	while (time <= 1000) {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] != 0 && board[i][j] != 1) { //다른 상어가 있다면
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}

		if (!flag) {
			break;
		}

		//상어를 이동시키고 냄새를 남긴다.
		moving();

		remove_smell();

		time += 1;
	}

	if (time > 1000) {
		return -1;
	}
	else {
		return time;
	}
}
void input() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				shark[board[i][j]].x = i;
				shark[board[i][j]].y = j;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> shark[i].dir;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> shark[i].Rank[j][k];
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		int x = shark[i].x;
		int y = shark[i].y;

		smell[x][y].first = i;
		smell[x][y].second = k;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << simulation();
}
