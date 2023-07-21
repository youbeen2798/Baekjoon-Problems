#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;
int m;

char map[1001][1001];
int dist[1001][1001][2];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 99999999;

bool inrange(int x, int y) {

	if (1 <= x && x <= n && 1 <= y && y <= m) {
		return true;
	}
	return false;
}
void bfs() {


	queue<pair<pair<int,int>, pair<int, bool>>> q;

	q.push({ {1,1}, {1, false} });
	dist[1][1][0] = 0; //아직 뿌수지 않음


	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int d = q.front().second.first;
		bool hit = q.front().second.second;

		if (a == n && b == m) {
			ans = min(ans, d); 
		}

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			//1. 아직 뿌수지 않았는데 벽이 아니라면
			if (inrange(nx, ny) && !hit && map[nx][ny] == '0' && dist[nx][ny][0] > d + 1) {
				dist[nx][ny][0] = d + 1;
				q.push({ {nx,ny}, {d + 1, false} });
			} //2. 아직 뿌수지 않았는데 벽이라면
			else if (inrange(nx, ny) && !hit && map[nx][ny] == '1' && dist[nx][ny][1] > d + 1) {
				dist[nx][ny][1] = d + 1;
				q.push({ {nx,ny}, {d + 1, true} });
			} //3.뿌쉈는데 벽이 아니라면 
			else if (inrange(nx, ny) && hit && map[nx][ny] == '0' && dist[nx][ny][1] > d + 1) {
				dist[nx][ny][1] = d + 1;
				q.push({ {nx,ny}, {d + 1, true} });
			}
		}
	}	

}
void solution() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 2; k++) {
				dist[i][j][k] = 99999999;
			}
		}
	}

	bfs();
	
	if (ans == 99999999) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}

void input() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string st;
		cin >> st;

		for (int j = 0; j < m; j++) {
			map[i][j + 1] = st[j];
		}
	}
}
int main() {

	input();
	solution();

}