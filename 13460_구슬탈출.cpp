#include <iostream>

using namespace std;

int n, m;
char map[11][11];
int arr[11];
char copymap[11][11];
bool total_red = false;
bool total_blue = false;

void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copymap[i][j] = map[i][j];
		}
	}
}

void left() {

	for (int i = 0; i < n; i++) {
		bool red = false;
		bool blue = false;
		for (int j = 2; j <= m - 2; j++) {
			char c = copymap[i][j];
			int idx = j;
			if (c == 'R' || c == 'B') { //빨간 구슬 혹은 파란 구슬이면
				for (int k = j - 1; k >= 0; k--) {
					if (copymap[i][k] == '.') {
						idx = k;
						continue;
					}
					else if (copymap[i][k] == 'O') {
						if (c == 'R') {
							total_red = true;
							red = true;
						}
						else if (c == 'B') {
							total_blue = true;
							blue = true;
						}
						continue;
					}
					break;
				}
				copymap[i][j] = '.';
				if (!red && !blue) { //빨간 구슬과 파란 구슬 둘다 통과를 못했으면
					copymap[i][idx] = c;
				}
			}
		}
	}
}

void right() {

	for (int i = 0; i < n; i++) {
		bool red = false;
		bool blue = false;
		for (int j = m - 2; j >= 1; j--) {
			char c = copymap[i][j];
			int idx = j;
			if (c == 'R' || c == 'B') {
				for (int k = j + 1; k < m; k++) {
					if (copymap[i][k] == '.') {
						idx = k;
						continue;
					}
					else if (copymap[i][k] == 'O') {
						if (c == 'R') {
							total_red = true;
							red = true;
						}
						else if (c == 'B') {
							total_blue = true;
							blue = true;
						}
						continue;
					}
					break;
				}

				copymap[i][j] = '.';

				if (!red && !blue) {
					copymap[i][idx] = c;
				}
			}	
		}
	}
}

void up() {

	for (int j = 0; j < m; j++) {
		bool red = false;
		bool blue = false;
		for (int i = 1; i <= n - 2; i++) {
			char c = copymap[i][j];
			int idx = i;
			if (c == 'R' || c == 'B') {
				for (int k = i - 1; k >= 1; k--) {
					if (copymap[k][j] == '.') {
						idx = k;
						continue;
					}
					else if (copymap[k][j] == 'O') {
						if (c == 'R') {
							total_red = true;
							red = true;
						}
						else if (c == 'B') {
							total_blue = true;
							blue = true;
						}
						continue;
					}
					break;
				}
				
				copymap[i][j] = '.';

				if (!red && !blue) {
					copymap[idx][j] = c;
				}
			}
		}
	}
}

void down() {


	for (int j = 0; j < m; j++) {
		bool red = false;
		bool blue = false;
		for (int i = n - 2; i >= 1; i--) {
			char c = copymap[i][j];
			int idx = i;
			if (c == 'R' || c == 'B') {
				for (int k = i + 1; k <= n - 2; k++) {
					if (copymap[k][j] == '.') {
						idx = k;
						continue;
					}
					else if (copymap[k][j] == 'O') {
						if (c == 'R') {
							total_red = true;
							red = true;
						}
						else if (c == 'B') {
							total_blue = true;
							blue = true;
						}
						continue;
					}
					break;
				}

				copymap[i][j] = '.';

				if (!red && !blue) {
					copymap[idx][j] = c;
				}
			}
		}
	}
}
void rotate(int num) {
	if (num == 1) {
		//왼쪽
		left();
	}
	else if (num == 2) {
		//오른쪽
		right();
	}
	else if (num == 3) {
		//위쪽
		up();
	}
	else {
		//아래쪽
		down();
	}
}
void subset(int position, int cnt) {

	if (position == cnt) {
		copy();

		total_red = false;
		total_blue = false;
		for (int i = 0; i < cnt; i++) {
			rotate(arr[i]);
		}
		if (total_red && !total_blue) {
			cout <<  cnt << "\n";
			exit(0);
		}
		return;
	}
	for (int i = 1; i <= 4; i++) {
		arr[position] = i;
		subset(position + 1, cnt);
	}
}
void solution() {

	for (int i = 1; i <= 10; i++) {
		subset(0, i);
	}

	cout << -1;
}

void input() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < m; j++) {
			map[i][j] = st[j];
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

