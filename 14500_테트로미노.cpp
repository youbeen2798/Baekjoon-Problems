#include <iostream>

using namespace std;

int n, m;
int graph[500][500];
bool visited[500][500];
int answer;
int sum;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool isInside(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= m) {
		return false;
	}
	return true;
}

void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}
void dfs(int r, int c, int depth, int sum) {
	if (depth == 3) {
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nR = r + dx[i];
		int nC = c + dy[i];

		
		if (!isInside(nR, nC)) {
			continue;
		}
		if (visited[nR][nC]) {
			continue;
		}
		visited[nR][nC] = true;
		dfs(nR, nC, depth + 1, sum + graph[nR][nC]);
		visited[nR][nC] = false;
	}
}

void shape1(int r, int c) {
	int sum = 0;
	sum = graph[r][c] + graph[r][c+1] + graph[r][c + 2] + graph[r-1][c + 1];
	answer = max(answer, sum);
}

void shape2(int r, int c) {
	int sum = 0;
	sum = graph[r][c] + graph[r][c + 1] + graph[r][c + 2] + graph[r + 1][c + 1];
	answer = max(answer, sum);
}

void shape3(int r, int c) {
	int sum = 0;
	sum = graph[r][c] + graph[r + 1][c] + graph[r + 2][c] + graph[r + 1][c + 1];
	answer = max(answer, sum);
}

void shape4(int r, int c) {
	int sum = 0;
	sum = graph[r][c] + graph[r][c+1] + graph[r + 1][c + 1] + graph[r-1][c + 1];
	answer = max(answer, sum);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m; //세로 가로

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			dfs(i, j, 0, graph[i][j]);
			visited[i][j] = false;

			if (0 < i && j < m - 2) {
				shape1(i, j);
			}
			if (i < n - 1 && j < m - 2) {
				shape2(i, j);
			}
			if (i < n - 2 && j < m - 1) {
				shape3(i, j);
			}
			if (i < n - 1 && i > 0 && j < m - 1) {
				shape4(i, j);
			}
		}
	}

	cout <<  answer << "\n";

}