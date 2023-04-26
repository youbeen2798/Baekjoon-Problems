#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n; //공간 크기
int map[21][21];
bool visited[21][21];
int times = 0;

int baby_shark_size = 2; //아기 상어크기
int eaten_fish_cnt = 0;
int baby_shark_x;
int baby_shark_y;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool inrange(int x, int y) {
	if (0 <= x && x < n && 0 <= y && y < n) {
		return true;
	}
	return false;
}

void print() {

	cout << "############" << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

}
void move() {

	int mini_dist = 999;
	memset(visited, false, sizeof(visited));

	//거리와 지나갈 수 있는 물고기들
	queue<pair<int, pair<int, int>>> q; 
	vector<pair<int, int>> can_eat_fish; //먹을 수 있는 물고기들

	q.push({ 0, { baby_shark_x, baby_shark_y } });
	visited[baby_shark_x][baby_shark_y] = true;

	while (!q.empty()) {

		int dist = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//지나갈 수 있으면
			if (inrange(nx, ny) && !visited[nx][ny] && map[nx][ny] <= baby_shark_size) {
				q.push({ dist + 1, { nx,ny } });
				visited[nx][ny] = true;

				//먹을 수 있으면
				if (dist + 1 <= mini_dist && map[nx][ny] < baby_shark_size && map[nx][ny] != 0) {
					can_eat_fish.push_back({ nx,ny });
					mini_dist = dist + 1;
				}
			}
		}
	}


//	cout << "먹을 수 있는 물고기 사이즈: " << can_eat_fish.size() << "\n";
	
	//먹을 수 있는 물고기가 없다면
	if (can_eat_fish.size() == 0) {
		cout <<  times << "\n";
		exit(0);
	}

	times += mini_dist; //물고기 거리만큼 이동

	sort(can_eat_fish.begin(), can_eat_fish.end());
	int eaten_fish_x = can_eat_fish[0].first;
	int eaten_fish_y = can_eat_fish[0].second;

	map[baby_shark_x][baby_shark_y] = 0;
	baby_shark_x = eaten_fish_x;
	baby_shark_y = eaten_fish_y;
	map[baby_shark_x][baby_shark_y] = 9;
	eaten_fish_cnt++;

	if (eaten_fish_cnt == baby_shark_size) {
		eaten_fish_cnt = 0;
		baby_shark_size++;
	}

//	print();
	//물고기 먹는다.

	/*
	for (int i = 0; i < can_eat_fish.size(); i++) {
		cout << can_eat_fish[i].first << " " << can_eat_fish[i].second << "\n";
	}
	*/

}
void solution() {

	while (true) {
		move();
	}

}
void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				baby_shark_x = i;
				baby_shark_y = j;
			}
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