#include <iostream>
#include <cmath>
using namespace std;

char map[100][100];
bool visited[100][100] = { 0, };

int n, m;
int cnt = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int blue_cnt = 0;
int white_cnt = 0;
char hi;

void dfs(int x, int y) {
	cnt++;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < m && 0 <= ny && ny < n
			&& visited[nx][ny] == 0 && map[nx][ny] == hi) {
			dfs(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m; //열크기 >> 행크기

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				hi = map[i][j];
				dfs(i, j);
				if (hi == 'W') {
					white_cnt += pow(cnt, 2);
				}
				else if (hi == 'B') {
					blue_cnt += pow(cnt, 2);
				}
				cnt = 0;
			}
		}
	}
	cout << white_cnt << " " << blue_cnt << "\n";

}