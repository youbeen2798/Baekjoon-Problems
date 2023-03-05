#include <iostream>
#include <vector>
using namespace std;

int r, c;
int ans = 0;
char arr[21][21];
bool visited[30];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int tmp_ans;

void bfs(int x, int y) {

	ans = max(ans, tmp_ans);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < r && 0 <= ny && ny < c) {

			int num = arr[nx][ny] - 'A';

			if (!visited[num]) {

				visited[num] = true;
				tmp_ans++;
				bfs(nx, ny);

				visited[num] = false;
				tmp_ans--;
			}
		}
	}
}
void solution() {

	tmp_ans = 1;
	visited[arr[0][0] - 'A'] = true;

	bfs(0, 0);

	cout << ans;
}

void input() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < c; j++) {
			arr[i][j] = st[j];
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