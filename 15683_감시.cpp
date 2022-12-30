#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[9][9];
bool direct[9][9];
int camera_num = 0; //카메라 개수

int directions[6] = { 0, 4, 2, 4, 4, 1 };

struct camera {
	int camera_type;
	int x;
	int y;
};
camera cameras[8];

int ans = 100;

void input() {
	cin >> n >> m; //세로 크기, 가로 크기

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (1 <= arr[i][j] && arr[i][j] <= 5) {
				cameras[camera_num] = { arr[i][j], i, j };
				camera_num++;
			}
		}
	}
}

void watch(int dir, int x,int y) {
	dir = dir % 4;

	if (dir == 0) { //위쪽
		for (int i = x - 1; i >= 0; i--) {
			if (arr[i][y] == 6) {
				break;
			}
			direct[i][y] = true;
		}
	}
	else if (dir == 1) { //오른쪽
		for (int i = y + 1; i < m; i++) {
			if (arr[x][i] == 6) {
				break;
			}
			direct[x][i] = true;
		}
	}
	else if (dir == 2) { //아래쪽
		for (int i = x + 1; i < n; i++) {
			if (arr[i][y] == 6) {
				break;
			}
			direct[i][y] = true;
		}
	}
	
	else if (dir == 3) { //왼쪽
		for (int i = y - 1; i >= 0; i--) {
			if (arr[x][i] == 6) {
				break;
			}
			direct[x][i] = true;
		}
	}
}

void copy(bool backup[9][9], bool origin[9][9]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			backup[i][j] = origin[i][j];
		}
	}
}
void solution(int num) {

	if (num == camera_num) {
		int w = 0;


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!direct[i][j] && arr[i][j] == 0) {
				//	cout << "i: " << i << " j: " << j << "\n";
					w++; 
				}
			}
		}
	//	cout << "w: " << w << "\n";
		ans = min(w, ans);
		return;
	}

	bool backup[9][9];

	//0번 카메라의 타입
	for (int dir = 0; dir < directions[cameras[num].camera_type]; dir++) {
		int camera_type = cameras[num].camera_type; //1번이라 가정

		copy(backup, direct);
		//0: 위쪽 1:오른쪽 2: 아래쪽 3: 왼쪽
		if (camera_type == 1) {
			watch(dir, cameras[num].x, cameras[num].y); //0, 1, 2, 3
		}
		else if (camera_type == 2) { //0,2 //1,3
			watch(dir, cameras[num].x, cameras[num].y);
			watch(dir + 2, cameras[num].x, cameras[num].y);
		}
		else if (camera_type == 3) { //0,1 //1,2 //2,3 //3,4
			watch(dir, cameras[num].x, cameras[num].y);
			watch(dir + 1, cameras[num].x, cameras[num].y); 
		}
		else if (camera_type == 4) { //0,1,2 //1,2,3 //2,3,0 //3,4,5
			watch(dir, cameras[num].x, cameras[num].y);
			watch(dir + 1, cameras[num].x, cameras[num].y);
			watch(dir + 2, cameras[num].x, cameras[num].y);
		}
		else if (camera_type == 5) {
			watch(dir, cameras[num].x, cameras[num].y);
			watch(dir + 1, cameras[num].x, cameras[num].y);
			watch(dir + 2, cameras[num].x, cameras[num].y);
			watch(dir + 3, cameras[num].x, cameras[num].y);
		}

		solution(num + 1);
		copy(direct, backup);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution(0);
	cout << ans;
}