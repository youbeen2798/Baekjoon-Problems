#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int r, c;
int arr[1001][1001];
int fire[1001][1001];
bool visited[1001][1001];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct location {
	int x;
	int y;
};

pair<int, int> jihun;
queue<pair<location, int>> q;

void fire_bfs() {

	//불이 없는 경우 대비
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			fire[i][j] = 999999999;
		}
	}

	while (!q.empty()) {
		int a = q.front().first.x;
		int b = q.front().first.y;
		int cnt = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < r && 0 <= ny && ny < c && !visited[nx][ny])
			{
				q.push({ {nx,ny}, cnt + 1 });
				visited[nx][ny] = true;
				fire[nx][ny] = cnt + 1;
			}
		}
	}
}

void jihun_bfs() {

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == '#' || arr[i][j] == 'F') {
				visited[i][j] = true;
			}
		}
	}

	q.push({ {jihun.first, jihun.second}, 0 });
	visited[jihun.first][jihun.second] = true;

	while (!q.empty()) {
		int a = q.front().first.x;
		int b = q.front().first.y;
		int cnt = q.front().second;

		q.pop();

		if (a == 0 || b == 0 || a == r - 1 || b == c - 1) {
			cout << cnt + 1;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < r && 0 <= ny && ny < c && !visited[nx][ny]) {
				if (cnt + 1 < fire[nx][ny]) {
					q.push({ {nx,ny}, cnt + 1 });
					visited[nx][ny] = true;
				}
			}
		}
	}

	cout << "IMPOSSIBLE";

}

void input() {
	cin >> r >> c; //행의 개수, 열의 개수

	for (int i = 0; i < r; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < c; j++) {
			arr[i][j] = st[j];
			if (arr[i][j] == 'J') {
				jihun = { i,j };
			}
			else if (arr[i][j] == 'F') {
				q.push({ { i,j },0 });
				visited[i][j] = true;
				fire[i][j] = 0;
			}
			else if (arr[i][j] == '#') {
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
	fire_bfs();
	jihun_bfs();
}