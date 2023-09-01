#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];
int dp[101][101][5];
//1: 동, 2: 서, 3: 남, 4: 북

int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0};

int m; //세로 길이
int n; //가로 길이
int start_x, start_y, start_dir;
int end_x, end_y, end_dir;
int ans = 9999999;

bool inrange(int x, int y) {

	if (1 <= x && x <= m && 1 <= y && y <= n) {
		return true; 
	}
	return false;
}
void solution() {

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= 4; k++) {
				dp[i][j][k] = 999999;
			}
		}
	}

	queue < pair<pair<int, int>, pair<int,int>>> q;
	q.push({ {start_x, start_y}, {start_dir, 0} });
	dp[start_x][start_y][start_dir] = 0;

	while (!q.empty()) {

		int a = q.front().first.first;
		int b = q.front().first.second;
		int dir = q.front().second.first;
		int dist = q.front().second.second;

		q.pop();

		//현재 방향으로 3칸 이동
		for (int i = 1; i <= 3; i++) {
			int nx = a + dx[dir] * i;
			int ny = b + dy[dir] * i;

			if (inrange(nx, ny) && map[nx][ny] == 0) {

				if (dp[nx][ny][dir] > dist + 1) {
					q.push({ {nx,ny}, {dir, dist + 1 } });
					dp[nx][ny][dir] = dist + 1;
				}
				continue;
			}
			break;
		}

		if (dir == 1 || dir == 2) { //동, 서라면
			//남, 북으로

			if (dp[a][b][3] > dist + 1) {
				dp[a][b][3] = dist + 1;
				q.push({ {a,b}, {3, dist + 1} });
			}
			if (dp[a][b][4] > dist + 1) {
				dp[a][b][4] = dist + 1;
				q.push({ {a,b}, {4, dist + 1} });
			}
		}
		else if (dir == 3 || dir == 4) { //남, 북이라면
			//동, 서로

			if (dp[a][b][1] > dist + 1) {
				dp[a][b][1] = dist + 1;
				q.push({ {a,b}, {1, dist + 1} });
			}
			if (dp[a][b][2] > dist + 1) {
				dp[a][b][2] = dist + 1;
				q.push({ {a,b}, {2, dist + 1} });
			}
		}
	}

	cout << dp[end_x][end_y][end_dir];
}

void input() {

	cin >> m >> n; 

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	cin >> start_x >> start_y >> start_dir;
	cin >> end_x >> end_y >> end_dir;
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}