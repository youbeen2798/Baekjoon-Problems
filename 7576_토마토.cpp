#include <iostream>
#include <queue>
using namespace std;

int m,n;
int arr[1001][1001];
bool visited[1001][1001];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 0;
struct location {
	int x;
	int y;
};
queue <pair<location, int>> q;

int solution() {
	while (!q.empty()) {
		int a = q.front().first.x;
		int b = q.front().first.y;
		int days = q.front().second;

		q.pop();
		ans = max(ans, days);

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]) {
	//			cout << "nx: " << nx << " ny: " << ny << "\n";
				visited[nx][ny] = true;
				arr[nx][ny] = 1;
				q.push({ {nx,ny }, days + 1 });
			}
		}
	}
	return ans;
}
void input() {
	cin >> m >> n;  //가로 칸 수 >> 세로 칸 수

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) { //토마토가 익었다면
				q.push({ { i,j }, 0 });
				visited[i][j] = true;
			}
			else if (arr[i][j] == -1) { //토마토가 들어있지 않다면
				visited[i][j] = true;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << ans;
}