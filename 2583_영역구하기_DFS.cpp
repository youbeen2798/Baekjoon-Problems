#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
bool arr[101][101];
bool visited[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int cnt = 1;
int cnt2 = 0;

vector <int> v;

void dfs(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < m && 0 <= ny && ny < n
			&& arr[nx][ny] == 1 && visited[nx][ny] == 0) {
			cnt++;
			dfs(nx, ny);
		}
	}
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

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		for (int x = m - d; x < m - b; x++) {
			for (int y = a; y < c; y++) {
				arr[x][y] = 0;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				cnt = 1;
				dfs(i, j);
				v.push_back(cnt);
				cnt2++;
			}
		}
	}

	cout << cnt2 << "\n";
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}