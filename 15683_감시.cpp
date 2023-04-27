#include <iostream>
#include <vector>


using namespace std;

struct camera {
	int x;
	int y;
	int carmera_num;
};

vector<camera> cameras;

int map[9][9];
int input_map[9][9];

int n; //세로 크기
int m; //가로 크기
int ans = 100;
vector<int> camera_dirs[65]; //카메라 방향들 위치

void check() {

	cout << "###############" << "\n";
	for (int i = 0; i < cameras.size(); i++) {
		cout << i << " 번 카메라" << "\n";
		for (int j = 0; j < camera_dirs[i].size(); j++) {
			cout << camera_dirs[i][j] << " ";
		}
		cout << "\n";
	}
}

void up(int x, int y) {

	for (int i = x - 1; i >= 1; i--) {
		if (input_map[i][y] == 0) {
			input_map[i][y] = -1;
			continue;
		}
		if (input_map[i][y] == 6) {
			break;
		}
	}

}
void right(int x, int y) {

	for (int j= y +  1; j <= m; j++) {
		if (input_map[x][j] == 0) {
			input_map[x][j] = -1;
			continue;
		}
		if (input_map[x][j] == 6) {
			break;
		}
	}
}
void down(int x, int y) {

	for (int i = x + 1; i <= n; i++) {
		if (input_map[i][y] == 0) {
			input_map[i][y] = -1;
			continue;
		}
		if (input_map[i][y] == 6) {
			break;
		}
	}
}
void left(int x, int y) {

	for (int j = y - 1; j >= 1; j--) {
		if (input_map[x][j] == 0) {
			input_map[x][j] = -1;
			continue;
		}
		if (input_map[x][j] == 6) {
			break;
		}
	}

}
void one_camera_watch(int x, int y, vector<int> dirs) {
//	cout << "x: " << x << " y: " << y << "\n";

	for (int i = 0; i < dirs.size(); i++) {
	//	cout << "dir: " << dirs[i] << "\n";
		if (dirs[i] == 1) {
			up(x, y);
		}
		else if (dirs[i] == 2) {
			right(x, y);
		}
		else if (dirs[i] == 3) {
			down(x, y);
		}
		else if (dirs[i] == 4) {
			left(x, y);
		}

	}
}

void print() {

	cout << "-----------print-------------" << "\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << input_map[i][j] << " ";
		}
		cout << "\n";
	}
}
void all_camera_watch() {
	//모든 카메라가 감시한다.
	for (int i = 0; i < cameras.size(); i++) {
		int x = cameras[i].x;
		int y = cameras[i].y;
		vector<int> dirs = camera_dirs[i];
		one_camera_watch(x, y, dirs);
	}

//	print();
}

void copy() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			input_map[i][j] = map[i][j];
		}
	}
}

void sakak_check() {
	//사각지대를 체크한다.

	int sakak_zidae_num = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (input_map[i][j] == 0) {
				sakak_zidae_num++;
			}
		}
	}

	ans = min(ans, sakak_zidae_num);
}
void permutation(int pos, int cnt) {

	if (pos == cnt){
		copy();
	//	check();
	//	cout << "감시전" << "\n";
	//	print();
		all_camera_watch();
	//	cout << "감시후" << "\n";
	//	print();
		sakak_check();
		return;
	}

	if (cameras[pos].carmera_num == 1) {
		camera_dirs[pos].push_back(1); //오른쪽
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();


		camera_dirs[pos].push_back(2); //아래
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();

		camera_dirs[pos].push_back(3); //왼쪽
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();

		camera_dirs[pos].push_back(4); //위
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();

	}
	else if (cameras[pos].carmera_num == 2) {
		camera_dirs[pos].push_back(1); //오른쪽
		camera_dirs[pos].push_back(3); //왼쪽
		permutation(pos + 1, cnt);		
		camera_dirs[pos].clear();


		camera_dirs[pos].push_back(2); //위쪽
		camera_dirs[pos].push_back(4); //아래쪽
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();

	}
	else if (cameras[pos].carmera_num == 3) {
		camera_dirs[pos].push_back(1); //오른쪽
		camera_dirs[pos].push_back(2); //
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();


		camera_dirs[pos].push_back(2); 
		camera_dirs[pos].push_back(3); 
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();


		camera_dirs[pos].push_back(3); 
		camera_dirs[pos].push_back(4); 
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();


		camera_dirs[pos].push_back(4);
		camera_dirs[pos].push_back(1); 
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();


	}
	else if (cameras[pos].carmera_num == 4) {
		camera_dirs[pos].push_back(1);
		camera_dirs[pos].push_back(2);
		camera_dirs[pos].push_back(3);
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();

		camera_dirs[pos].push_back(2);
		camera_dirs[pos].push_back(3);
		camera_dirs[pos].push_back(4);
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();

		camera_dirs[pos].push_back(3);
		camera_dirs[pos].push_back(4);
		camera_dirs[pos].push_back(1);
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();

		camera_dirs[pos].push_back(4);
		camera_dirs[pos].push_back(1);
		camera_dirs[pos].push_back(2);
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();
	}
	else if (cameras[pos].carmera_num == 5) {
		camera_dirs[pos].push_back(1);
		camera_dirs[pos].push_back(2);
		camera_dirs[pos].push_back(3);
		camera_dirs[pos].push_back(4);
		permutation(pos + 1, cnt);
		camera_dirs[pos].clear();
	}
}
void solution() {

	permutation(0, cameras.size());
}

void input() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			input_map[i][j] = map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cameras.push_back({ i,j, map[i][j] });
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
	cout <<  ans;
}