#include <iostream>
#include <queue>

using namespace std;

int n;
int m;
int t; //제한 시간

int map[101][101];
int dist[101][101][2]; //0: 무기 있음, 1: 무기 없음
bool visited[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 999999999;

bool inrange(int x, int y) {

	if (1 <= x && x <= n && 1 <= y && y <= m) {
		return true;
	}
	return false;
}

void bfs() {

	//현재 위치, 무기, 거리
	queue<pair<pair<int, int>, pair<bool, int>>> q;
	q.push({ {1,1}, {false, 0} });

	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;

		bool flag = q.front().second.first;
		int d = q.front().second.second;

		if (a == n && b == m && d <= t) {
			ans = min(ans, d);
		}

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			//만약 무기가 있다면
			if (flag) {

				if (inrange(nx, ny) && dist[nx][ny][1] > d + 1) {
					dist[nx][ny][1] = d + 1;
					q.push({ {nx,ny}, {true, d + 1} });
				}
			}
			else {
				//무기가 없다면
				if (inrange(nx, ny) && dist[nx][ny][0] > d + 1 && map[nx][ny] == 0) {
					dist[nx][ny][0] = d + 1;
					q.push({ {nx,ny}, {false, d + 1} });
				}
				else if (inrange(nx, ny) && dist[nx][ny][1] > d + 1 && map[nx][ny] == 2) {
					dist[nx][ny][1] = d + 1;
					q.push({ {nx,ny}, {true, d + 1} });
				}
			}
		}
	}

}
void solution() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dist[i][j][0] = 999999999;
			dist[i][j][1] = 999999999;
		}
	}


	bfs();

	if (ans == 999999999) {
		cout << "Fail";
	}
	else {
		cout << ans;
	}

}

void input() {

	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
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