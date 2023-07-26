#include <iostream>
#include <queue>

using namespace std;

int n;
char map[51][51];
int breaks[51][51];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 9999999;

bool inrange(int x, int y) {

	if (1 <= x && x <= n && 1 <= y && y <= n) {
		return true;
	}
	return false;
}
void solution() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			breaks[i][j] = 99999999;
		}
	}
	queue<pair<pair<int, int>, int>> q;
	q.push({ {1,1}, 0 });

	while (!q.empty()) {

		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;

		if (a == n && b == n) {
			ans = min(ans, c);
		}
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (inrange(nx, ny)) {

				//Èò ¹æÀÌ¶ó¸é
				if (map[nx][ny] == '1' && breaks[nx][ny] > c){
					breaks[nx][ny] = c;
					q.push({ {nx,ny}, c });
				}
				else if (map[nx][ny] == '0' && breaks[nx][ny] > c + 1) {
					breaks[nx][ny] = c + 1;
					q.push({ {nx,ny}, c + 1});
				}
			}
		}
	}

	cout << ans;
}
void input() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		string st;
		cin >> st;
		
		for (int j = 1; j <= n; j++) {
			map[i][j] = st[j - 1];
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