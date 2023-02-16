#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r; //격자판 행 크기
int c; //격자판 열 크기
int m; //상어 수
int real_ans = 0; // 정답

struct shark_info {

	int speed; //속력
	int dir; //이동방향
	int z; //크기

	bool operator<(shark_info a) {
		return z > a.z;
	}
};

vector<shark_info> arr[101][101]; //격자판
vector<shark_info> tmp[101][101]; //상어가 움직인 후 격자판

int col; //현재 낙시왕 열 정보

int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };

void catch_closet_shark() {
	//낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 
	//상어를 잡으면 격자판에서 잡은 상어가 사라진다.

	for (int row = 1; row <= r; row++) {
		if (arr[row][col].size() > 0) {
			real_ans += arr[row][col][0].z; //잡은 물고기 크기
			arr[row][col].clear();
			break;
		}
	}
}

int change_dir(int dir) {
	if (dir % 2 != 0) {
		dir += 1;
	}
	else {
		dir -= 1;
	}
	return dir;
}

void move(int x, int y) {
	//(x,y)에 있는 상어가 이동한다.
	int dir = arr[x][y][0].dir; //방향
	int speed = arr[x][y][0].speed; //속도
	int size = arr[x][y][0].z; //크기

	int now_x = x; //행
	int now_y = y; //열

	if (dir <= 2) { //위 아래라면

		speed %= ( 2 * r - 2);
	}
	else {
		speed %= (2 * c - 2);
	}

	for (int i = 0; i < speed; i++) {
		int nx = now_x + dx[dir]; //새로운 행
		int ny = now_y + dy[dir]; //새로운 열

		if (1 <= nx && nx <= r && 1 <= ny && ny <= c) {
			now_x = nx;
			now_y = ny;
		}
		else {
			dir = change_dir(dir);
			i--;
		}
	}

	//3, speed = 1인지 확인
	if (tmp[now_x][now_y].size() > 0) {
		int already_shark_size = tmp[now_x][now_y][0].z; //이미 들어있는 상어 사이즈
		if (already_shark_size < size) { //이미 들어있는 상어 사이즈가 지금 상어 사이즈보다 작다면
			tmp[now_x][now_y].clear();
		}
	}
	tmp[now_x][now_y].push_back({ speed, dir,  size });
}


void all_shark_move() {
	// 상어가 이동한다.

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j].size() > 0) {
				move(i, j);
			}
		}
	}
}


void copy() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j].size() > 0) {
				arr[i][j].clear();
			}
			arr[i][j] = tmp[i][j];
			tmp[i][j].clear();
		}
	}
}

void solution() {

	for (col = 1; col <= c; col++) {
		//낚시왕이 오른쪽으로 한 칸 이동한다.
		catch_closet_shark();
		all_shark_move();
		copy();
	}

	cout << real_ans;
}
void input() {

	cin >> r >> c >> m;

	for (int i = 0; i < m; i++) {
		int r, c, s, d, z; //행, 열, 속력, 이동방향, 크기
		cin >> r >> c >> s >> d >> z;
		arr[r][c].push_back({ s,d,z }); //속력, 이동방향, 크기
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}