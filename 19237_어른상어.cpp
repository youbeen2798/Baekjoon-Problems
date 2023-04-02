#include <iostream>

using namespace std;

int n;
int m;
int k;

//방향
//1: 위, 2 : 아래, 3 : 왼쪽, 4: 오른쪽

int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };

struct shark {
	int x;
	int y;
	int dir;
	int dirmap[5][5];
	bool die;
};

int map[21][21];

//냄새를 뿌린 상어 번호, 남은 시간
pair<int,int> smell[21][21];

shark sharks[401];

void spread_smell() {
	//맨 처음에는 모든 상어가 자신의 위치에 자신의 냄새를 뿌린다.
	
	for (int i = 1; i <= m; i++) {
		if (!sharks[i].die) {
			smell[sharks[i].x][sharks[i].y] = { i, k };
		}
	}
}

void one_shark_move(int shark_num) {
	//shark_num 상어가 이동한다.

	//사방으로 본다.
	
	//현재 상어 방향
	int now_shark_dir = sharks[shark_num].dir;
	int now_shark_x = sharks[shark_num].x; //현재 상어 행
	int now_shark_y = sharks[shark_num].y; //현재 상어 열

	int next_shark_x = -1; //이동할 상어 행
	int next_shark_y = -1; //이동할 상어 열
	int next_shark_dir = -1; //이동할 상어 방향


	//1.제일 먼저 냄새가 없는 칸으로 이동한다. 
	for (int i = 1; i <= 4; i++) {

		//이동하려는 방향
		int dir = sharks[shark_num].dirmap[now_shark_dir][i];
		int nx = now_shark_x + dx[dir];
		int ny = now_shark_y + dy[dir];

		//냄새가 없고 해당 자리가 비어있으면
		if (1 <= nx && nx <= n && 1 <= ny && ny <= n && smell[nx][ny].first == 0) {
			
			if (map[nx][ny] != 0) {
				sharks[shark_num].die = true; //상어가 죽는다.
				map[now_shark_x][now_shark_y] = 0; //상어가 있던 자리는 없어진다.
				return;
			}
			next_shark_x = nx;
			next_shark_y = ny;
			next_shark_dir = dir;
			break;
		}
	}


	if (next_shark_x != -1) {
		//이동할 수 있다면
		sharks[shark_num].x = next_shark_x;
		sharks[shark_num].y = next_shark_y;
		sharks[shark_num].dir = next_shark_dir;
		
		//이 전 map 삭제
		map[now_shark_x][now_shark_y] = 0;
		map[next_shark_x][next_shark_y] = shark_num;
		return;
	}

	//2. 자신의 냄새가 있는 칸의 방향으로 이동한다.
	for (int i = 1; i <= 4; i++) {

		//이동하려는 방향
		int dir = sharks[shark_num].dirmap[now_shark_dir][i];
		int nx = now_shark_x + dx[dir];
		int ny = now_shark_y + dy[dir];
		if (1 <= nx && nx <= n && 1 <= ny && ny <= n && smell[nx][ny].first == shark_num){
			
			if (map[nx][ny] != 0) {
				sharks[shark_num].die = true; //상어가 죽는다.
				map[now_shark_x][now_shark_y] = 0; //상어가 있던 자리는 없어진다.
				return;
			}
			next_shark_x = nx;
			next_shark_y = ny;
			next_shark_dir = dir;
			break;
		}
	}

	//이동할 수 있다면
	sharks[shark_num].x = next_shark_x;
	sharks[shark_num].y = next_shark_y;
	sharks[shark_num].dir = next_shark_dir;

	//이 전 map 삭제
	map[now_shark_x][now_shark_y] = 0;
	map[next_shark_x][next_shark_y] = shark_num;

}

void all_shark_move() {

	
	for (int i = 1; i <= m; i++) {

		if (sharks[i].die) {
			continue;
		}
		one_shark_move(i);
	}	
}

void smell_minus() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (smell[i][j].first != 0) {
				smell[i][j].second--;

				if (smell[i][j].second == 0) {
					smell[i][j].first = 0;
				}
			}
		}
	}
}

bool finish() {
	//다 죽으면 false

	for (int i = 2; i <= m; i++) {
		if (!sharks[i].die) {
			return false;
		}
	}

	return true;
}
void solution() {

	spread_smell();

	for (int i = 1; i <= 1000; i++) {
		all_shark_move();
		smell_minus();
		spread_smell();

		if (finish()) {
			cout <<  i;
			exit(0);
		}
	}

	cout << -1;


}
void input() {

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				sharks[map[i][j]].x = i;
				sharks[map[i][j]].y = j;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> sharks[i].dir;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				cin >> sharks[i].dirmap[j][k];
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