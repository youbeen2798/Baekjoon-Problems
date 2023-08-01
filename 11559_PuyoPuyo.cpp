#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

char map[12][6];
bool visited[12][6];
bool bomb[12][6];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int times = 1;
bool check_bomb = false; //터졌는지 확인

bool inrange(int x, int y) {

	if (0 <= x && x < 12 && 0 <= y && y < 6) {
		return true;
	}
	return false;
}
void bfs(int x, int y) {

	vector<pair<int, int>> v;

	char c = map[x][y];
	queue<pair<int, int>> q; 
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {

		int a = q.front().first;
		int b = q.front().second;
		v.push_back({ a,b });

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (inrange(nx, ny) && !visited[nx][ny] && map[nx][ny] == c) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}

		}
	}

	//같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면
	if (v.size() >= 4) {
		check_bomb = true;
		int size = v.size();
		for (int i = 0; i < size; i++) {
			bomb[v[i].first][v[i].second] = true; //터진다고 표시
		}
	}
}

void down(int x, int y) {
	//밑으로 내려간다.

	char c = map[x][y];
	int nx = x;

	for (int i = x + 1; i < 12; i++) {
		if (map[i][y] == '.') {
			nx = i;
		}
		else {
			break;
		}
	}

	//밑으로 내려갈 만큼 내려가기
	map[x][y] = '.';
	map[nx][y] = c;
}
void gravity() {
	//중력

	for (int j = 0; j < 6; j++) {
		for (int i = 11; i >= 0; i--) {
			if (map[i][j] != '.') {
				down(i, j);
			}
		}
	}

}
void one_time() {

	check_bomb = false;
	memset(visited, false, sizeof(visited));
	memset(bomb, false, sizeof(bomb));

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] != '.' && !visited[i][j]) {
				bfs(i, j);
			}
		}
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (bomb[i][j]) {
				map[i][j] = '.';
			}
		}
	}

	gravity(); //중력

	//안 터졌으면
	if (!check_bomb) {
		cout << times << "\n";
		exit(0);
	}
}
void solution() {


	for (times = 0;; times++) {
		one_time();
	}

}

void input() {

	for (int i = 0; i < 12; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < 6; j++) {
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