#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int m, n, k;

vector <int> v;
int arr[101][101] = { 1, };
bool visited[101][101] = { 0, };
queue < pair<int, int >> q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y) {
	int cnt = 1;

	q.push(make_pair(x, y));
	visited[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0<= nx && nx < m && 0 <= ny && ny < n && arr[nx][ny] == 1 && visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				cnt++;
				q.push(make_pair(nx, ny));
			}
		}
	}

	v.push_back(cnt);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n >> k;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 1;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		for (int x = b; x < d; x++) {
			for (int y = a; y < c; y++) {
				arr[x][y] = 0;
			}
		}
	}

	
	int cnt2 = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				bfs(i, j);
				cnt2++;
			}
		}
	}

	sort(v.begin(), v.end());
	
	cout << cnt2 << "\n";

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

}