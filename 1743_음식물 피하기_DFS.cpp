#include <iostream>

using namespace std;

int n, m, k;
int r, c;
bool map[101][101];
bool visited[101][101] = { 0, };
int cnt = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y) {
	visited[x][y] = 1; 
	cnt++; 

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (1 <= nx && nx <= n && 1 <= ny && ny <= m
			&& map[nx][ny] == 1 && visited[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		cin >> r >> c; //3 2
		map[r][c] = 1;
	}

	int mx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visited[i][j] == 0 && map[i][j] == 1) {
				dfs(i, j);
				if (mx <= cnt) {
					mx = cnt;
				}
				cnt = 0;
			}

		}
	}
	cout <<  mx << "\n";

}