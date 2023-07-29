#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n; //동굴 크기
int tc = 1; //테스트 케이스

int map[126][126];
int dist[126][126];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool inrange(int x, int y) {

	if (1 <= x && x <= n && 1 <= y && y <= n) {
		return true;
	}
	return false;
}
void solution() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = 9999999;
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ {1,1}, map[1][1]});
	dist[1][1] = map[1][1];

	while (!q.empty()) {

		int a = q.front().first.first;
		int b = q.front().first.second;
		int d = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (inrange(nx, ny)) {
				int new_d = d + map[nx][ny];
				if (new_d < dist[nx][ny]) {
					dist[nx][ny] = new_d;
					q.push({ {nx,ny}, new_d });
				}
			}
		}
	}

	cout << "Problem " << tc << ": " << dist[n][n] << "\n";
}

void input() {

	while (true) {
		cin >> n;

		if (n == 0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
			}
		}

		solution();
		tc++;
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}