#include <iostream>

using namespace std;

int n, k;
int map[2200][2200];
int result[3];

bool check(int row, int col, int num) {
	int k = map[row][col];

	for (int i = row; i < row + num; i++) {
		for (int j = col; j < col + num; j++) {
			if (map[i][j] != k) {
				return false;
			}
		}
	}
	return true;
}
void divide(int row, int col, int num) {

	if (check(row, col, num)) {
		result[map[row][col]]++;
	}
	else {
		int size = num / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(row + i * size, col + j * size, size);
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
		for (int j = 0; j < n; j++) {
			cin >> k;
			map[i][j] = k + 1;
		}
	}

	divide(0, 0, n);

	cout << result[0] << "\n";
	cout << result[1] << "\n";
	cout << result[2] << "\n";
}