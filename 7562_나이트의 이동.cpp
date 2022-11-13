#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int t;
int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };
int num;
int startx, starty;
int endx, endy;
int arr[301][301];
bool visited[301][301];

struct location {
	int x;
	int y;
};

queue<pair<location, int>> q;

int ans;
int solution() {
	ans = 900000;
	while (!q.empty()) {
		int a = q.front().first.x;
		int b = q.front().first.y;
		int cnt = q.front().second;

		q.pop();
		if (a == endx && b == endy) {
			ans = min(ans, cnt);
		}

		for (int i = 0; i < 8; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (0 <= nx && nx < num && 0 <= ny && ny < num && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ {nx,ny}, cnt + 1 });
			}
		}
	}

	return ans;
}

void reset() {
	memset(visited, false, sizeof(visited));
	while (!q.empty()) {
		q.pop();
	}
}
void input() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		reset();
		cin >> num; //한 변의 길이
		//시작 x, 시작 y, 끝 x, 끝 y
		cin >> startx >> starty >> endx >> endy; //0 0 30 50
		q.push({ { startx, starty },0 });
		visited[startx][starty] = true;
		cout << solution() << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}