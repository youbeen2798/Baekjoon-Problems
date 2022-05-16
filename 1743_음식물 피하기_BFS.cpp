#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int r, c;
bool map[101][101];
bool visited[101][101];

queue <pair<int, int>> q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt = 0;

void bfs(int x, int y) {
	visited[x][y] = 1; //visited[2][2] = 1
	q.push(make_pair(x, y)); //2 2
	cnt++;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (1 <= nx && nx <= n && 1 <= ny && ny <= m
				&& map[nx][ny] == 1 && visited[nx][ny] == 0) {
				
				cnt++;
				visited[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}

		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		map[r][c] = 1;
	}

	int mx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				bfs(i, j);
//				cout << "cnt: " << cnt << "\n";
				if (mx <= cnt)
					mx = cnt;
				cnt = 0;
			}
		}
	}
	cout <<  mx << "\n";


	
}