#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int l, r, c;
char arr[31][31][31];
bool visited[31][31][31];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0,  0, 1, -1, 0, 0 };
int dz[6] = { 0,  0, 0, 0, 1, -1 };

struct position {
	int x;
	int y;
	int z;
};

position start;
position endd;

queue <pair<position, int>> q;

void bfs(position start) {

	memset(visited, false, sizeof(visited));

	q.push({ start, 0 });
	visited[start.z][start.x][start.y] = true;

	while (!q.empty()) {
		int x = q.front().first.x;
		int y = q.front().first.y;
		int z = q.front().first.z;
		int time = q.front().second;

		q.pop();


		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (0 <= nx && nx < r && 0 <= ny && ny < c && 0 <= nz && nz < l && (arr[nz][nx][ny] == '.' || arr[nz][nx][ny] == 'E') && !visited[nz][nx][ny]) {
				q.push({ {nx,ny,nz}, time + 1 });
				visited[nz][nx][ny] = true;
				if (nx == endd.x && ny == endd.y && nz == endd.z) {
					cout << "Escaped in " << time + 1 << " minute(s)." << "\n";
					while (!q.empty()) {
						q.pop();
					}
					return;
				}
			}
		}
	}

	cout << "Trapped!" << "\n";
}


void input() {


	while (true) {
		cin >> l >> r >> c; //층 수, 행 수, 열 수

		if (l == 0 && r == 0 && c == 0) {
			break;
		}

		//막혀있어 지나갈 수 없는 칸 "#"
		//비어있는 칸은 "."
		//시작 지점은 "S"
		//탈출할 수 있는 출구는 "E"
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S') {
						start = { j,k,i }; //x y z
					}
					else if (arr[i][j][k] == 'E') {
						endd = { j,k,i };

					}
				}
			}
		}

		bfs(start);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}