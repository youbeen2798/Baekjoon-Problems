#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n; //세로 크기
int m; //가로 크기

char map[51][51];
bool visited[51][51];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void reset() {

	memset(visited, false, sizeof(visited));
}

int bfs(int x, int y) {

	queue<pair<int, pair<int,int>>> q;
	q.push({ 0, { x,y } });
	visited[x][y] = true;

	int maxi_dist = 0;

	while (!q.empty()) {
		int a = q.front().second.first;
		int b = q.front().second.second;
		int dist = q.front().first;
		maxi_dist = max(dist, maxi_dist);

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && map[nx][ny] == 'L') {
				q.push({ dist + 1, { nx,ny } });
				visited[nx][ny] = true;
			}
		}
	}

	return maxi_dist;
}

void solution() {

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				reset();
				ans = max(ans, bfs(i, j));
			}
		}
	}
	cout << ans;
}

void input() {

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < m; j++) {
			map[i][j] = st[j];
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