#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

int n, m;
bool visited[100][100];
char map[100][100];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt;
int blue_cnt = 0;
int white_cnt = 0;
char hi;
queue <pair<int, int>> q;

void bfs(int x, int y) {
	cnt = 0;
	visited[x][y] = 1;
	hi = map[x][y];
	cnt++; // 
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			
			if (0 <= nx && nx < m && 0 <= ny && ny < n
				&& visited[nx][ny] == 0 && map[nx][ny] == hi)
			{
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

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				bfs(i, j);
				if (hi == 'W') {
					white_cnt += pow(cnt,2);
				}
				else if (hi == 'B') {
					blue_cnt += pow(cnt,2);
				}
			}
		}
	}

	cout << white_cnt << " " << blue_cnt;

}