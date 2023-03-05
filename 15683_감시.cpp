#include <iostream>
#include <vector>


using namespace std;

int n, m;
char arr[9][9];
char copy_arr[9][9];
int ans = 999999;

struct camera {
	int x; //행
	int y; //열
	int type; //타입
};

camera cameras[9];
int camera_num = 0;
vector<int> camera_dirs[9]; 
//카메라가 바라볼 위치만 담아놓은 배열
//0: 상 // 1: 하 // 2: 좌 // 3: 우


void copy() {

	//배열 복사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy_arr[i][j] = arr[i][j];
		}
	}
}

void up_watch(int x, int y) {

	for (int i = x - 1; i >= 0; i--) {
		if (copy_arr[i][y] != '6') {
			copy_arr[i][y] = '#';
			continue;
		}
		break;
	}
}

void down_watch(int x, int y) {
	for (int i = x + 1; i < n; i++) {
		if (copy_arr[i][y] != '6') {
			copy_arr[i][y] = '#';
			continue;
		}
		break;
	}
}

void left_watch(int x, int y) {

	for (int j = y - 1; j >= 0; j--) {
		if (copy_arr[x][j] != '6') {
			copy_arr[x][j] = '#';
			continue;
		}
		break;
	}
}

void right_watch(int x, int y) {
	for (int j = y + 1; j < m; j++) {
		if (copy_arr[x][j] != '6') {
			copy_arr[x][j] = '#';
			continue;
		}
		break;
	}
}
void real_camera_watch(int x, int y, int dir) {
	//x,y에 있는 카메라가 dir 방향으로 본다.

	if (dir == 0) {
		//상
		up_watch(x, y);
	}
	else if (dir == 1) {
		//하
		down_watch(x, y);
	}
	else if (dir == 2) {
		//좌
		left_watch(x, y);
	}
	else if (dir == 3) {
		//우
		right_watch(x, y);
	}
}
void camera_watch(int camera_num, vector<int> camera_dirs) {
	//카메라 번호가 camera_num
	//camera_dirs만큼 관찰한다.

	int x = cameras[camera_num].x; //카메라 행
	int y = cameras[camera_num].y; //카메라 열

	for (int i = 0; i < camera_dirs.size(); i++) {
		real_camera_watch(x, y, camera_dirs[i]);
	}
}

void check_sagakzidae() {

	int tmp_ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copy_arr[i][j] == '0') {
				tmp_ans++;
			}
		}
	}

	ans = min(ans, tmp_ans);
	
}
void real_solution() {

	copy();

	for (int i = 0; i < camera_num; i++) {
		for (int j = 0; j < camera_dirs[i].size(); j++) {
			//i번째 카메라가 dirs만큼 본다.
			camera_watch(i, camera_dirs[i]);
		}
	}

	check_sagakzidae(); //사각 지대 체크
}
void permutation(int position) {
	
	if (position == camera_num) {
		
		real_solution();
		return;
	}

	char camera_type = cameras[position].type; //카메라 타입
	if (camera_type == '1') {
		//상
		camera_dirs[position].push_back(0);
		permutation(position + 1);
		camera_dirs[position].clear();

		//하
		camera_dirs[position].push_back(1);
		permutation(position + 1);
		camera_dirs[position].clear();

		//좌
		camera_dirs[position].push_back(2);
		permutation(position + 1);
		camera_dirs[position].clear();

		//우
		camera_dirs[position].push_back(3);
		permutation(position + 1);
		camera_dirs[position].clear();
	}
	else if (camera_type == '2') {
		//상, 하
		camera_dirs[position].push_back(0);
		camera_dirs[position].push_back(1);
		permutation(position + 1);
		camera_dirs[position].clear();

		//좌, 우
		camera_dirs[position].push_back(2);
		camera_dirs[position].push_back(3);
		permutation(position + 1);
		camera_dirs[position].clear();
	}
	else if (camera_type == '3') {
		//상, 우
		camera_dirs[position].push_back(0);
		camera_dirs[position].push_back(3);
		permutation(position + 1);
		camera_dirs[position].clear();

		//우, 하
		camera_dirs[position].push_back(3);
		camera_dirs[position].push_back(1);
		permutation(position + 1);
		camera_dirs[position].clear();

		//하, 좌
		camera_dirs[position].push_back(1);
		camera_dirs[position].push_back(2);
		permutation(position + 1);
		camera_dirs[position].clear();

		//좌, 상
		camera_dirs[position].push_back(0);
		camera_dirs[position].push_back(2);
		permutation(position + 1);
		camera_dirs[position].clear();
	}
	else if (camera_type == '4') {
		//상 빼고
		camera_dirs[position].push_back(1);
		camera_dirs[position].push_back(2);
		camera_dirs[position].push_back(3);
		permutation(position + 1);
		camera_dirs[position].clear();

		//하 빼고
		camera_dirs[position].push_back(0);
		camera_dirs[position].push_back(2);
		camera_dirs[position].push_back(3);
		permutation(position + 1);
		camera_dirs[position].clear();

		//좌 빼고
		camera_dirs[position].push_back(0);
		camera_dirs[position].push_back(1);
		camera_dirs[position].push_back(3);
		permutation(position + 1);
		camera_dirs[position].clear();

		//우 빼고
		camera_dirs[position].push_back(0);
		camera_dirs[position].push_back(1);
		camera_dirs[position].push_back(2);
		permutation(position + 1);
		camera_dirs[position].clear();
	}
	else if (camera_type == '5') {
		//사방면
		camera_dirs[position].push_back(0);
		camera_dirs[position].push_back(1);
		camera_dirs[position].push_back(2);
		camera_dirs[position].push_back(3);
		permutation(position + 1);
		camera_dirs[position].clear();
	}
}
void solution() {

	permutation(0);

	cout <<  ans;
}

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
			if ('1' <= arr[i][j] && arr[i][j] <= '5') {
				cameras[camera_num++] = { i,j, arr[i][j] };
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