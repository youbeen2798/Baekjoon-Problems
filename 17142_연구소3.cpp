#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n; //연구소 크기
int m; //바이러스 개수
int map[51][51];
bool visited[51][51];
int dist_arr[51][51];
int ans = 9999999;

//0: 빈칸, 1: 벽, 2: 바이러스 위치
vector<pair<int, int>> virus;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool inrange(int x, int y) {
	if (0 <= x && x < n && 0 <= y && y < n) {
		return true;
	}
	return false;
}

bool check() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist_arr[i][j] != 5000 || map[i][j] == 1) {
			}
			else {
				return false;
			}
		}
	}

	return true;
}
void spread(vector<pair<int, int>> virus) {

	int tmp_ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist_arr[i][j] = 5000;
		}
	}
	queue<pair<int, int>> q;

	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i].first, virus[i].second });
		dist_arr[virus[i].first][virus[i].second] = 0;
	}

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		int dist = dist_arr[a][b];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (inrange(nx,ny) && dist_arr[nx][ny] > dist + 1) {
				if (map[nx][ny] == 0) {
					q.push({ nx,ny });
					dist_arr[nx][ny] = dist + 1;
					tmp_ans = max(tmp_ans, dist_arr[nx][ny]);
				}
				else if (map[nx][ny] == 2) {
					q.push({ nx,ny });
					dist_arr[nx][ny] = dist + 1;
				}
			}
		}
	}

	if (check()) {
		ans = min(ans, tmp_ans);
	}
}
void combination(vector<pair<int, int>> arr, vector<pair<int, int>> comb, int r, int idx, int depth) {

	if (r == 0) {
		for (int i = 0; i < comb.size(); i++) {
			map[comb[i].first][comb[i].second] = -1; //바이러스 표시
		}
		spread(comb);
		for (int i = 0; i < comb.size(); i++) {
			map[comb[i].first][comb[i].second] = 2; //바이러스 표시
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

	vector<pair<int, int>> real_virus(m); //고를 바이러스 m개

	combination(virus, real_virus, m, 0, 0);

	if (ans == 9999999) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}
void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
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