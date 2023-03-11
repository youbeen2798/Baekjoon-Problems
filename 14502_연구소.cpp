#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n; //세로 크기
int m; //가로 크기
int map[9][9];
bool visited[9][9];
int ans = 0;

vector<pair<int, int>> walls;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y) {

	queue<pair<int, int>> q;

	visited[x][y] = true;
	q.push({ x,y });

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && map[nx][ny] != 1) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

void check() {
	
	int tmp_ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && !visited[i][j]) {
				tmp_ans++;
			}
		}
	}

	ans = max(ans, tmp_ans);
}
void spread_virus() {

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2 && !visited[i][j]) {
				bfs(i, j);
			}
		}
	}

	check();
}

void combination(vector<pair<int, int>> arr, vector<pair<int, int>> comb, int r, int idx, int depth) {

	if (r == 0) {
	//	cout << "#####" << "\n";
		//선택된 3곳 새로운 벽으로 만들기
		for (int i = 0; i < comb.size(); i++) {
			map[comb[i].first][comb[i].second] = 1;
		}

		spread_virus();
		//벽 다시 빈 칸으로 만들기
		for (int i = 0; i < comb.size(); i++) {
			map[comb[i].first][comb[i].second] = 0;
		}
		return;
	}
	else if (arr.size() == depth) {
		return;
	}
	else {

		comb[idx] = arr[depth];

		combination(arr, comb, r - 1, idx + 1, depth + 1);

		combination(arr, comb, r, idx, depth + 1);
	}
}
void solution() {

	vector<pair<int, int>> comb(3);

	combination(walls, comb, 3, 0, 0);

	cout << ans;
}

void input() {

	cin >> n >> m;

	//0: 빈칸, 1: 벽, 2: 바이러스 위치
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				walls.push_back({ i,j });
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
}