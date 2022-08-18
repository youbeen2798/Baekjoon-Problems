#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, k;
int map[21][21];
int order[1001];

vector <int> dice(7);

int dx[5] = {0, 0, 0, -1, 1}; //1.동 2.서 3.북 4.남
int dy[5] = {0, 1, -1, 0, 0};

void rollEast() {
	dice = { 0,dice[4], dice[2], dice[1], dice[6], dice[5], dice[3] };
}
void rollWest() {
	dice = { 0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4] };
}
void rollSouth() {
	dice = { 0,dice[2], dice[6], dice[3], dice[4], dice[1], dice[5] };
}
void rollNorth() {
	dice = { 0,dice[5], dice[1], dice[3], dice[4], dice[6], dice[2] };
}

void solve() {

	for (int i = 0; i < k; i++) {

		int mx = x + dx[order[i]];
		int my = y + dy[order[i]];

		if (mx < 0 || mx >= n || my < 0 || my >= m) {
			continue;
		}

		x = mx;
		y = my;

		if (order[i] == 1) { //동쪽
			rollEast();
		}
		else if (order[i] == 2) { //서쪽
			rollWest();
		}
		else if(order[i] == 3){ //북쪽
			rollNorth();
		}
		else if (order[i] == 4) { //남쪽
			rollSouth();
		}

		cout <<  dice[1] << "\n";

		if (map[x][y] == 0) {
			map[x][y] = dice[6];
		}
		else {
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
	}
}
void input() {

	cin >> n >> m >> x >> y >> k; // 세로 크기(행) >> 가로크기(열) >> 주사위 x좌표 >> y좌표 >> 명령개수

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> order[i];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input(); //입력받기
	solve();
}