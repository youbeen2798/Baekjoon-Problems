#include <iostream>
#include <queue>
using namespace std;

int n;
pair<int, int> baby_shark; //아기 상어
int baby_shark_size = 2; //아기 상어 크기
int stomache = 0; //물고기가 먹은 크기

int arr[21][21];
bool visited[21][21];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int times = 0;

struct position {
	int x; //행
	int y; //열
};

bool compare(pair<int, position> a, pair<int, position> b) {
	if (a.first != b.first) { //거리가 다르다면
		return a.first < b.first; //거리를 오름차순으로
	}
	if (a.second.x != b.second.x) { //행이 다르다면
		return a.second.x < b.second.x; //행을 오름차순으로
	}
	return a.second.y < b.second.y; //열을 오름차순으로
}

void eat_fish() {
	//먹을 수 있는 물고기 고르기

	vector<pair<int, position>> can_eat_fish; //먹을 수 있는 물고기들
	memset(visited, false, sizeof(visited));

	int min_dist = 999999;
	queue<pair<int, position>> q;
	q.push({ 0,{ baby_shark.first, baby_shark.second }});
	visited[baby_shark.first][baby_shark.second] = true;

	while (!q.empty()) {
		int dist = q.front().first; //거리
		int x = q.front().second.x; //위치 행
		int y = q.front().second.y; //위치 열

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && arr[nx][ny] <= baby_shark_size) {
				visited[nx][ny] = true;
				q.push({ dist + 1, {nx,ny} });

				if (arr[nx][ny] == baby_shark_size || arr[nx][ny] == 0) {
					//크기가 같거나 빈칸이면 그냥 지나가기
					continue;
				}
				if (dist + 1 < min_dist) {
					//최소거리 보다 더 작다면
					can_eat_fish.clear();
					min_dist = dist + 1;
					can_eat_fish.push_back({ dist + 1, {nx,ny} });
				}
				else if (dist + 1 == min_dist) {
					//최소거리와 같다면
					can_eat_fish.push_back({ dist + 1, {nx,ny} });
				}
			}
		}
	}

	if (can_eat_fish.size() == 0) {
		//먹을 수 있는 물고기가 없다면
		cout << times;
		exit(0);
	}
	sort(can_eat_fish.begin(), can_eat_fish.end(), compare);

	int eaten_fish_x = can_eat_fish[0].second.x;
	int eaten_fish_y = can_eat_fish[0].second.y;
	int dist = can_eat_fish[0].first;

	arr[baby_shark.first][baby_shark.second] = 0;
	baby_shark = { eaten_fish_x, eaten_fish_y }; //아기 상어 위치
	arr[eaten_fish_x][eaten_fish_y] = 9; //먹은 물고기 자리에 아기 상어가 이동
	times += dist;

	if (++stomache == baby_shark_size) {
		baby_shark_size++; //아기 상어 크기 커짐
		stomache = 0;
	}
}

void solution() {

	while (true) {
		memset(visited, false, sizeof(visited));

		eat_fish();
	}
}

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				baby_shark = { i,j }; //아기 상어
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