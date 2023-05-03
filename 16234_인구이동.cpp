#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int n, l, r;
int map[51][51];
bool visited[51][51];
bool move_flag = false;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool inrange(int x, int y) {

	if (1 <= x && x <= n && 1 <= y && y <= n) {
		return true;
	}
	return false;
}
void move(int x, int y) {

	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	vector<pair<int, int>> countries;
	countries.push_back({ x,y }); //연합을 이루는 나라들
	int country_people_sum = map[x][y];

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			
			if (inrange(nx, ny) && !visited[nx][ny]) {
				int diff = abs(map[nx][ny] - map[a][b]);

				if (l <= diff && diff <= r) {
					move_flag = true; 
					q.push({ nx, ny });
					visited[nx][ny] = true;
					countries.push_back({ nx, ny });
					country_people_sum += map[nx][ny];
				}
			}
		}
	}

	int people_cnt = country_people_sum / countries.size();

	for (int i = 0; i < countries.size(); i++) {
		map[countries[i].first][countries[i].second] = people_cnt;
	}

}

void one_day_move() {


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j]) { //아직 방문하지 않았다면
				move(i, j); //이동
			}
		}
	}
}

void reset() {
	memset(visited, false, sizeof(visited));
	move_flag = false;
}
void solution() {

	for (int days = 0; ; days++) {
		reset();
		one_day_move();
		
		if (!move_flag) {
			cout << days;
			break;
		}
	}


}
void input() {

	cin >> n >> l >> r;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
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