#include <iostream>
#include <queue>
using namespace std;

int n, m;
int c = 0;
int map[8][8];
int tmp[8][8];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int mini_cnt = 65;

void mapCopy(int(*a)[8], int(*b)[8]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = a[i][j];
		}
	}
}

void bfs() {
	int ans[8][8];
	mapCopy(tmp, ans);

	queue <pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans[i][j] == 2) {
				q.push(make_pair(i, j));				
			}			
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int p = 0; p < 4; p++) {
			int nx = x + dx[p];
			int ny = y + dy[p];

			if ((0 <= nx) && (nx < n) && (0 <= ny) && (ny < m) && (ans[nx][ny] == 0)) {
				ans[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans[i][j] == 0) {
				cnt++;
			}
		}
	}

	c = max(c, cnt);
}
void wall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmp[i][j] == 0) {
					tmp[i][j] = 1;
					wall(cnt + 1);
					tmp[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m; //세로 크기 // 가로크기
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				mapCopy(map, tmp); //map -> tmp로 배열 복사
				tmp[i][j] = 1;
				wall(1);
				tmp[i][j] = 0;
			}
		}
	}
	
	cout << c;
}