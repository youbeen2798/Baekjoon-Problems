#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
char arr[101][101];
bool visited[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < n; j++) {
			arr[i][j] = st[j];
		}
	}

//	for(int i = 0; i < n; i++){
//		for (int j = 0; j < n; j++) {
//			cout << arr[i][j];
//		}
//		cout << "\n";
//	}
}

void bfs(int x, int y) {
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		char c = arr[a][b];

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			char cc = arr[nx][ny];

			if (0 <= nx && nx < n && 0 <= ny && ny < n && c == cc && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

void bfs2(int x, int y) {
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		char c = arr[a][b];
//		cout << "a: " << a << " b: " << b << " c: " << c << "\n";
//		cout << "q.size(): " << q.size() << "\n";
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			char cc = arr[nx][ny];

			bool rg = false;
			if ((c == 'R' && cc == 'G') || (c == 'G' && cc == 'R')) {
				rg = true;
			}

			if (0 <= nx && nx < n && 0 <= ny && ny < n && (c == cc || rg) && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
void solution() {

	int answer1 = 0;
	int answer2 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				answer1++;
			}
		}
	}

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs2(i, j);
				answer2++;
			}
		}
	}

	cout << answer1 << " ";
	cout << answer2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}