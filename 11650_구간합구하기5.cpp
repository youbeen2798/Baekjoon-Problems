#include <iostream>

using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int** arr = new int* [n+1];

	for (int i = 0; i < n+1; i++) {
		arr[i] = new int[n+1];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	int** map = new int* [n+1];

	for (int i = 0; i < n+1; i++) {
		map[i] = new int[n+1];
	}

	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < n+1; j++) {
			map[i][j] = 0;
		}
	}

	map[1][1] = arr[1][1];

	
	for (int i = 1; i <= n; i++) {
		map[1][i] = map[1][i - 1] + arr[1][i];
	}

	for (int i = 1; i <= n; i++) {
		map[i][1] = map[i - 1][1] + arr[i][1];
	}
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1] + arr[i][j];
		}
	}
	int x1, y1, x2, y2;

	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		cout << map[x2][y2] - map[x2][y1 - 1] - map[x1 - 1][y2] + map[x1 - 1][y1 - 1] << "\n";

	}
}