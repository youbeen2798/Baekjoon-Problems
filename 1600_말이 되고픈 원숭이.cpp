#include <iostream>
#include <queue>

using namespace std;

int k;
int w;
int h;
int map[201][201];
int dist[201][201][31];
int ans = 9999999;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int h_dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int h_dy[8] = { -2,-1,1,2,-2,-1,1,2 };



bool inrange(int x, int y) {

	if (1 <= x && x <= h && 1 <= y && y <= w) {
		return true;
	}
	return false;
}
void bfs() {

	//현재 위치와 k번 cnt, 움직인 cnt
	queue<pair<pair<int, int>, pair<int,int>>> q;
	q.push({ {1,1}, {0,0} });

	while (!q.empty()) {

		int a = q.front().first.first;
		int b = q.front().first.second;
		int k_cnt = q.front().second.first;
		int m_cnt = q.front().second.second;

		if (a == h && b == w){
			ans = min(ans, m_cnt);
		}

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (inrange(nx, ny) && map[nx][ny] == 0 && dist[nx][ny][k_cnt] > m_cnt + 1) {
				dist[nx][ny][k_cnt] = m_cnt + 1;
				q.push({ {nx,ny}, {k_cnt, m_cnt + 1} });
			}
		}

		if (k_cnt <= k) {

			for (int i = 0; i < 8; i++) {
				int nx = a + h_dx[i];
				int ny = b + h_dy[i];

				if (inrange(nx, ny) && map[nx][ny] == 0 && dist[nx][ny][k_cnt + 1] > m_cnt + 1) {
					dist[nx][ny][k_cnt + 1] = m_cnt + 1;
					q.push({ {nx,ny}, {k_cnt + 1, m_cnt + 1} });
				}
			}
		}
	}
}
void solution() {

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			for (int m = 0; m <= k; m++) {
				dist[i][j][m] = 9999999;
			}
		}
	}
	bfs();

	if (ans == 9999999) {
		cout << -1;
	}
	else {
		cout << ans; 
	}
}
void input() {

	cin >> k >> w >> h;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> map[i][j];
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