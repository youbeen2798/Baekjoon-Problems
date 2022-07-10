#include <iostream>

using namespace std;

int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int answer = 0;

bool visited[501][501] = { false, };
int arr[501][501];

bool isIn(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= m) {
		return false;
	}
	return true;
}

void dfs(int r, int c, int depth, int sum) {
	if (depth == 3) {
		answer = max(answer, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nR = r + dx[i];
		int nC = c + dy[i];

		if (isIn(nR, nC) == false) {
			continue;
		}
		if (visited[nR][nC] == true) {
			continue;
		}
		visited[nR][nC] = true;
		dfs(nR, nC, depth + 1, sum + arr[nR][nC]);
		visited[nR][nC] = false;
	}
}

void solu1(int r, int c) {
	int sum = 0;
	sum = arr[r][c] + arr[r + 1][c] + arr[r + 2][c] + arr[r + 1][c + 1];

	answer = max(answer, sum);
}

void solu2(int r, int c) {
	int sum = 0;
	sum = arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r - 1][c + 1];
	answer = max(answer, sum);
}

void solu3(int r, int c) {
	int sum = 0;
	sum = arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r + 1][c + 1];
	answer = max(answer, sum);
}

void solu4(int r, int c) {
	int sum = 0;
	sum = arr[r][c] + arr[r][c + 1] + arr[r - 1][c + 1] + arr[r + 1][c + 1];
	answer = max(answer, sum);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m; //세로 //가로

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			dfs(i, j, 0, arr[i][j]);
			visited[i][j] = false;

			if (i < n - 2 && j < m - 1) {
				solu1(i, j);
			}
			if (j < m - 2) {
				solu2(i, j);
			}
			if (i < n - 1 && j < m - 2) {
				solu3(i, j);
			}
			if (i < n - 1 && j < m - 1) {
				solu4(i, j);
			}
		}
	}

	cout <<  answer;
}