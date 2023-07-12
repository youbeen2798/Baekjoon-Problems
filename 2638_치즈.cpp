#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n; //세로 크기
int m; //가로 크기
int map[101][101];
//치즈 있는 부분: 1, 치즈 없는 부분: 0

bool visited[101][101];
int cnt[101][101];
int times = 0;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool inrange(int x, int y) {

	if (1 <= x && x <= n && 1 <= y && y <= m) {
		return true;
	}
	return false;
}

void spread() {

	memset(visited, false, sizeof(visited));
	memset(cnt, 0, sizeof(cnt));

	queue<pair<int, int>> q;
	q.push({ 1,1 });
	visited[1][1] = true;

	while (!q.empty()) {

		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (inrange(nx, ny) && map[nx][ny] == 0 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });

				for (int k = 0; k < 4; k++) {
					int nx2 = nx + dx[k];
					int ny2 = ny + dy[k];

					if (inrange(nx2, ny2) && map[nx2][ny2] == 1) {
						cnt[nx2][ny2]++;
					}
				}
			}
		}
	}

	bool flag = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1 && cnt[i][j] >= 2) {
				flag = true;
				map[i][j] = 0;
			}
		}
	}

	if (!flag) {
		cout << times;
		exit(0);
	}
}
void solution() {


	for (times = 0; times <= 100; times++) {
		spread();
	}
}

void input() {

	cin >> n >> m;
	
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