#include <iostream>
#include <queue>
using namespace std;

int r, c;
char arr[51][51];
queue<pair<int, int>> water_q;
queue<pair<int, int>> gosum_q;

pair<int, int> biber; //비버위치

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void input() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'D') {
				biber = { i,j }; //비버
			}
			else if (arr[i][j] == 'S') {
				gosum_q.push({ i,j });
			}
			else if (arr[i][j] == '*') {
				water_q.push({ i,j }); //물 위치
			}
		}
	}
}

void bfs() {

	int time = 0;
	while (!gosum_q.empty()) { //고슴도치가 더 이상 갈 길이 없으면
		time++;

		int water_q_size = water_q.size();
		for (int i = 0; i < water_q_size; i++) {
			int water_x = water_q.front().first;
			int water_y = water_q.front().second;

			water_q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = water_x + dx[j];
				int ny = water_y + dy[j];

				if (0 <= nx && nx < r && 0 <= ny && ny < c && arr[nx][ny] == '.') { //범위에 해당하고 빈칸이면
					water_q.push({ nx,ny });
					arr[nx][ny] = '*'; //물 영역으로 표시
				}
			}
		}

		int gosum_q_size = gosum_q.size();
		for (int i = 0; i < gosum_q_size; i++) {
			int gosum_x = gosum_q.front().first;
			int gosum_y = gosum_q.front().second;
			gosum_q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = gosum_x + dx[j]; //고슴도치 새로운 위치
				int ny = gosum_y + dy[j];
				if (0 <= nx && nx < r && 0 <= ny && ny < c) { //범위에 해당하고 
					if (nx == biber.first && ny == biber.second) { //비버를 만나면
						cout << time;
						return;
					}
					else if (arr[nx][ny] == '.') { //빈칸이면
						gosum_q.push({ nx,ny });
						arr[nx][ny] = 'S';
					}
				}
			}
		}
	}
	cout << "KAKTUS";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	bfs();
}