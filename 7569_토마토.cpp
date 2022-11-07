#include <iostream>
#include <queue>
using namespace std;

int n, m, h;
int arr[101][101][101];
bool visited[101][101][101];
int ans = 0;

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

struct types {
	int x, y, z, cnt;
};

queue<types> q;

void input() {
	cin >> m >> n >> h;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push({ i,j,k,0 });
					visited[i][j][k] = true;
				}
				else if (arr[i][j][k] == -1) {
					visited[i][j][k] = true;
				}
			}
		}
	}
}

void solution(){
	while (!q.empty()) {
		types a = q.front();
		q.pop();
		int x = a.x;
		int y = a.y;
		int z = a.z;
		int cnt = a.cnt;
		ans = max(cnt, ans);

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && 0 <= nz && nz < h && !visited[nx][ny][nz]) {
				visited[nx][ny][nz] = true;
				q.push({ nx,ny,nz,cnt + 1});
			}
		}
	}

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j][k]) {
					cout << -1;
					return;
				}
			}
		}
	}

	cout << ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

}