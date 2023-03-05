#include <iostream>
#include <vector>


using namespace std;

int n, m;
char arr[9][9];
char copy_arr[9][9];
int ans = 999999;

struct camera {
	int x; //��
	int y; //��
	int type; //Ÿ��
};

camera cameras[9];
int camera_num = 0;
vector<int> camera_dirs[9]; 
//ī�޶� �ٶ� ��ġ�� ��Ƴ��� �迭
//0: �� // 1: �� // 2: �� // 3: ��


void copy() {

	//�迭 ����
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
	//x,y�� �ִ� ī�޶� dir �������� ����.

	if (dir == 0) {
		//��
		up_watch(x, y);
	}
	else if (dir == 1) {
		//��
		down_watch(x, y);
	}
	else if (dir == 2) {
		//��
		left_watch(x, y);
	}
	else if (dir == 3) {
		//��
		right_watch(x, y);
	}
}
void camera_watch(int camera_num, vector<int> camera_dirs) {
	//ī�޶� ��ȣ�� camera_num
	//camera_dirs��ŭ �����Ѵ�.

	int x = cameras[camera_num].x; //ī�޶� ��
	int y = cameras[camera_num].y; //ī�޶� ��

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
			//i��° ī�޶� dirs��ŭ ����.
			camera_watch(i, camera_dirs[i]);
		}
	}

	check_sagakzidae(); //�簢 ���� üũ
}
void permutation(int position) {
	
	if (position == camera_num) {
		
		real_solution();
		return;
	}

	char camera_type = cameras[position].type; //ī�޶� Ÿ��
	if (camera_type == '1') {
		//��
		camera_dirs[position].push_back(0);
		permutation(position + 1);
		camera_dirs[position].clear();

		//��
		camera_dirs[position].push_back(1);
		permutation(position + 1);
		camera_dirs[position].clear();

		//��
		camera_dirs[position].push_back(2);
		permutation(position + 1);
		camera_dirs[position].clear();

		//��
		camera_dirs[position].push_back(3);
		permutation(position + 1);
		camera_dirs[position].clear();
	}
	else if (camera_type == '2') {
		//��, ��
		camera_dirs[position].push_back(0);
		camera_dirs[position].push_back(1);
		permutation(position + 1);
		camera_dirs[position].clear();

		//��, ��
		camera_dirs[position].push_back(2);
		camera_dirs[position].push_back(3);
		permutation(position + 1);
		camera_dirs[position].clear();
	}
	else if (camera_type == '3') {
		//��, ��
		camera_dirs[position].push_back(0);
		camera_dirs[position].push_back(3);
		permutation(position + 1);
		camera_dirs[position].clear();

		//��, ��
		camera_dirs[position].push_back(3);
		camera_dirs[position].push_back(1);
		permutation(position + 1);
		camera_dirs[position].clear();

		//��, ��
		camera_dirs[position].push_back(1);
		camera_dirs[position].push_back(2);
		permutation(position + 1);
		camera_dirs[position].clear();

		//��, ��
		camera_dirs[position].push_back(0);
		camera_dirs[position].push_back(2);
		permutation(position + 1);
		camera_dirs[position].clear();
	}
	else if (camera_type == '4') {
		//�� ����
		camera_dirs[position].push_back(1);
		camera_dirs[position].push_back(2);
		camera_dirs[position].push_back(3);
		permutation(position + 1);
		camera_dirs[position].clear();

		//�� ����
		camera_dirs[position].push_back(0);
		camera_dirs[position].push_back(2);
		camera_dirs[position].push_back(3);
		permutation(position + 1);
		camera_dirs[position].clear();

		//�� ����
		camera_dirs[position].push_back(0);
		camera_dirs[position].push_back(1);
		camera_dirs[position].push_back(3);
		permutation(position + 1);
		camera_dirs[position].clear();

		//�� ����
		camera_dirs[position].push_back(0);
		camera_dirs[position].push_back(1);
		camera_dirs[position].push_back(2);
		permutation(position + 1);
		camera_dirs[position].clear();
	}
	else if (camera_type == '5') {
		//����
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