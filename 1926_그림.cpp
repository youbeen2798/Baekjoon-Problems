#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[501][501];
bool visited[501][501];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue <pair<int, int>> q;
int cnt;
int cnt2 = 0;
vector <int> v;

void bfs(int x, int y) {
	cnt++;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (visited[nx][ny] == false && arr[nx][ny] == 1) {
					cnt++;
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				cnt2++;
				cnt = 0;
				bfs(i, j);
				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end());

	if (cnt2 != 0) {
		cout << cnt2 << "\n";
		cout << v[v.size() - 1];
	}
	else {
		cout << 0 << "\n" << 0 << "\n";
	}



}