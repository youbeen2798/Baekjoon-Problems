#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int m; //물고기 수
int s; //마법 연습 횟수

vector<int> fish_arr[11][11]; //물고기 방향이 저장됨
vector<int> original[11][11]; //잠깐 저장해놓음

int smell[11][11];

int shark_x; //상어 행
int shark_y; //상어 열

int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 }; //행
int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 }; //열

//상 좌 하 우
int shark_dx[4] = { -1, 0, 1,0 };
int shark_dy[4] = {  0, -1, 0,1 };

struct info {
	string s; //상어 이동 정보
	int fish_cnt; //물고기 개수

	int start_x; //처음 시작 행
	int start_y; //처음 시작 열
};

void fish_real_move(int current_x, int current_y, int current_dir) {

	//리턴 값 : x, y, dir

	for (int dir = current_dir; dir >= 1; dir--) {
		int nx = current_x + dx[dir];
		int ny = current_y + dy[dir];

		//상어 위치가 아니면서 범위 안이라면
		if (1 <= nx && nx <= 4 && 1 <= ny && ny <= 4 && !(nx == shark_x && ny == shark_y) && smell[nx][ny] == 0) {
			fish_arr[nx][ny].push_back(dir);
			return;
		}
	}

	for (int dir = 8; dir > current_dir; dir--) {
		int nx = current_x + dx[dir];
		int ny = current_y + dy[dir];

		//상어 위치가 아니면서 범위 안이라면
		if (1 <= nx && nx <= 4 && 1 <= ny && ny <= 4 && !(nx == shark_x && ny == shark_y) && smell[nx][ny] == 0) {
			fish_arr[nx][ny].push_back(dir);
			return;
		}
	}

	fish_arr[current_x][current_y].push_back(current_dir);
}

void fish_move(int x, int y) {
	for (int i = 0; i < original[x][y].size(); i++) {
		fish_real_move(x, y, original[x][y][i]);
	}
}
void all_fish_move() {
	
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			//i,j에 있는 물고기가 모두 이동한다.
			fish_move(i, j);
		}
	}
}

void replicate_start() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			original[i][j] = fish_arr[i][j];
			fish_arr[i][j].clear();
			if (smell[i][j] != 0) {
				smell[i][j]++; //냄새 시간 증가
			}
		}
	}
}

void replicate_end() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < original[i][j].size(); k++) {
				fish_arr[i][j].push_back(original[i][j][k]);
			}
			original[i][j].clear();
		}
	}
}

void shark_move() {
	//상어가 이동한다.
	
	//마지막 위치와 현재까지 이동방향
	queue <pair<pair<int, int>, info>> q;
	
	string s = "";
	q.push({ {shark_x, shark_y}, {s, 0, -1,-1} });

	string shark_move_info = ""; //상어 이동 정보
	int shark_can_eat_fish_max_num = 0;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		string tmp_s = q.front().second.s;
		int fish_cnt = q.front().second.fish_cnt;
		int start_x = q.front().second.start_x; 
		int start_y = q.front().second.start_y;

		q.pop();

		if (tmp_s.size() == 3) {

			if (fish_cnt > shark_can_eat_fish_max_num) {
				//상어가 먹을 수 있는 물고기 개수가 최대라면
				shark_move_info = tmp_s;
				shark_can_eat_fish_max_num = fish_cnt;
			}
			if (fish_cnt == shark_can_eat_fish_max_num && (shark_move_info.size() == 0 || shark_move_info > tmp_s)) {
				//상어 움직임 정보가 아직 없거나 갱신될만하면
				shark_move_info = tmp_s;
			}
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + shark_dx[i];
			int ny = y + shark_dy[i];

			//격자를 벗어나지 않고 이전 크기가 아니면
			if (1 <= nx && nx <= 4 && 1 <= ny && ny <= 4) {

				char c = i + '0';
				tmp_s += c;
				int current_fish_cnt = fish_arr[nx][ny].size(); //현재 물고기 수

				//아직 처음 들어온 거면, start_x, start_y를 nx,ny로 갱신

				//처음 들어온게 아니라면, nx와 start_x, ny와 starty를 비교해서
				//같으면 그냥 fish_cnt, 다르면 fish_cnt + current_fish_cnt

				if (tmp_s.size() == 1) {
					//처음 들어온 거라면
					q.push({ {nx,ny}, {tmp_s, fish_cnt + current_fish_cnt, nx,ny} });
				}
				else {
					//겹치지 않는다면
					if (!(start_x == nx && start_y == ny)) {
						q.push({ {nx, ny}, {tmp_s, fish_cnt + current_fish_cnt, start_x, start_y} });
					}
					else {
						//겹친다면
						q.push({ {nx, ny}, {tmp_s, fish_cnt, start_x, start_y} });
					}
				}
				

				tmp_s.pop_back();
			}
		}
	}

	for (int i = 0; i < shark_move_info.size(); i++) {
		int dir = shark_move_info[i] - '0';

		shark_x += shark_dx[dir]; //상어 위치 행 갱신
		shark_y += shark_dy[dir]; //상어 위치 열 갱신

		if (fish_arr[shark_x][shark_y].size() > 0) {
			fish_arr[shark_x][shark_y].clear(); //물고기 없애기
			smell[shark_x][shark_y] = 1; //냄새나게 하기
		}
	}
}

void erase_smell() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (smell[i][j] == 3) { //2초가 지나면
				smell[i][j] = 0;
			}
		}
	}
}
void solution() {


	for (int i = 0; i < s; i++) {
		replicate_start();
		all_fish_move();
		shark_move();
		erase_smell();
		replicate_end();
	}

	int ans = 0;

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			ans += fish_arr[i][j].size();
		}
	}
	cout <<  ans;
}

void input() {

	cin >> m >> s;

	for (int i = 0; i < m; i++) {
		int x, y, d; //물고기 행, 열, 위치
		cin >> x >> y >> d;
		fish_arr[x][y].push_back(d);
	}

	cin >> shark_x >> shark_y; //상어 행, 열
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}