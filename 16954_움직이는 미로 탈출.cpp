#include <iostream>
#include <set>
#include <queue>

using namespace std;

char map[10][10];
set<int> wall_time[10][10];
bool visited[10][10];

int dx[9] = { -1,-1,-1,0,0,0,1,1,1 };
int dy[9] = { 1,0,-1,1,0,-1,1,0,-1 };

bool inrange(int x, int y) {

	if (1 <= x && x <= 8 && 1 <= y && y <= 8) {
		return true;
	}
	return false;
}
void check() {
	//timeÀÏ ¶§ º®

	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (map[i][j] == '#') {
				int time = 0;
				for (int k = i; k <= 8; k++) {
					wall_time[k][j].insert(time++);
				}
			}
		}
	}
}

void run() {

	queue<pair<pair<int,int>, int>> q;
	q.push({ { 8,1 }, 1 });
	visited[8][1] = true;

	int cnt = 0;
	while (!q.empty()) {

		int a = q.front().first.first;
		int b = q.front().first.second;
		int t = q.front().second;


		if (a == 1 && b == 8) {
			cout << "1";
			exit(0);
		}

		q.pop();

		for (int i = 0; i < 9; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (inrange(nx, ny) && (wall_time[nx][ny].find(t) == wall_time[nx][ny].end())
			&& (wall_time[nx][ny].find(t - 1) == wall_time[nx][ny].end())) {
				q.push({ {nx,ny}, t + 1 }); 
			}
		}
	}
	
}
void solution() {

	check();
	run();

	cout << 0;
}
void input() {

	for (int i = 0; i < 8; i++) {
		string st;
		cin >> st;
		
		for (int j = 0; j < 8; j++) {
			map[i + 1][j + 1] = st[j];
		}
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}