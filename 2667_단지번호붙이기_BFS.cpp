#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
string arr[25];
bool visited[25][25];
int cnt = 0;

vector <int> v;
queue <pair<int, int>> q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y) {
	visited[x][y] = 1;
	cnt++;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (visited[nx][ny] == false && arr[nx][ny] == '1') {
					visited[nx][ny] = 1;
					cnt++;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && arr[i][j] == '1') {
				cnt = 0;
				bfs(i, j);
				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << "\n";

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

}
