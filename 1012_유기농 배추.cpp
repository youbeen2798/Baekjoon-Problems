#include <iostream>
#include <cstring>

using namespace std;

int T;
int M, N;
int K;

int arr[50][50];
bool visited[50][50];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			if (arr[nx][ny] == 1 && visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				dfs(nx, ny);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {

		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));

		cin >> M >> N >> K; //가로 세로

		for (int j = 0; j < K; j++) {
			int a, b;
			cin >> a >> b;

			arr[b][a] = 1;
		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1 && visited[i][j] == false) {
					ans++;
					dfs(i, j);
				}
			}
		}

		cout << ans << "\n";

	}
}