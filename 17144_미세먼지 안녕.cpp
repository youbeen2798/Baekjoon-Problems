#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int r, c, t;
int map[51][51];

vector <pair<int, int>> cleaner;

void input() {
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				cleaner.push_back({ i,j });
			}
		}
	}
}

void cleaning() {

	int cntt = 0;

	for (auto h : cleaner) {

		if (cntt == 0) {
			int x = h.first; //2
			int y = h.second; //0

			map[x - 1][y] = 0;

			//왼쪽 위에서 아래로
			for (int i = x - 1; i > 0; i--) { //0~1
				map[i][y] = map[i - 1][y];
			}
			//위쪽 오른쪽에서 왼쪽으로
			for (int i = y; i < c - 1; i++) {
				map[0][i] = map[0][i + 1];
			}

			//오른쪽 아래에서 위로
			for (int i = 0; i < x; i++) {
				map[i][c - 1] = map[i + 1][c - 1];
			}

			//아래 오른쪽에서 왼쪽으로
			for (int i = c - 1; i >= y + 2; i--) {
				map[x][i] = map[x][i - 1];
			}

			map[x][y + 1] = 0;

			cntt++;
		}

		else {
			int x = h.first; //3
			int y = h.second; //0
			
			for (int i = x + 1; i < r; i++) {
				map[i][y] = map[i + 1][y];
			}

			for (int i = y; i < c; i++) {
				map[r - 1][i] = map[r - 1][i + 1];
			}

			for (int i = r - 1; i > x; i--) {
				map[i][c - 1] = map[i - 1][c - 1];
			}

			for (int i = c - 1; i >= y + 2; i--) { //7~
				map[x][i] = map[x][i - 1];
			}
			map[x][y + 1] = 0;

		}
		

	}
}
void diffusion() { //얼마나 확산할지

	int diffuse[51][51];

	memset(diffuse, 0, sizeof(diffuse));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != -1 && map[i][j] != 0) {

				int nx, ny;
				int cnt = 0;
				//위
				nx = i - 1;
				ny = j;
				if (0 <= nx && nx < r && 0 <= ny && ny < c && map[nx][ny] != -1) {
					diffuse[nx][ny] += map[i][j] / 5;
					cnt++;

				}

				//아래
				nx = i + 1;
				ny = j;
				if (0 <= nx && nx < r && 0 <= ny && ny < c && map[nx][ny] != -1) {
					diffuse[nx][ny] += map[i][j] / 5;
					cnt++;

				}

				//오른쪽
				nx = i;
				ny = j + 1;
				if (0 <= nx && nx < r && 0 <= ny && ny < c && map[nx][ny] != -1) {
					diffuse[nx][ny] += map[i][j] / 5;
					cnt++;
	
				}

				//왼쪽
				nx = i;
				ny = j - 1;
				if (0 <= nx && nx < r && 0 <= ny && ny < c && map[nx][ny] != -1) {
					diffuse[nx][ny] += map[i][j] / 5;
					cnt++;

				}
				//자기자신
				diffuse[i][j] += ( map[i][j] / 5 * cnt ) * -1;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] += diffuse[i][j];
		}
	}
}

void answering() {
	int answer = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == -1) {
				continue;
			}
			answer += map[i][j];
		}
	}
	cout << answer;

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	
	for (int i = 0; i < t; i++) {
		diffusion();
		cleaning();
	}
	answering();
}