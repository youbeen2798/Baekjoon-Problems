#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int m; //����� ��
int s; //���� ���� Ƚ��

vector<int> fish_arr[11][11]; //����� ������ �����
vector<int> original[11][11]; //��� �����س���

int smell[11][11];

int shark_x; //��� ��
int shark_y; //��� ��

int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 }; //��
int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 }; //��

//�� �� �� ��
int shark_dx[4] = { -1, 0, 1,0 };
int shark_dy[4] = {  0, -1, 0,1 };

struct info {
	string s; //��� �̵� ����
	int fish_cnt; //����� ����

	int start_x; //ó�� ���� ��
	int start_y; //ó�� ���� ��
};

void fish_real_move(int current_x, int current_y, int current_dir) {

	//���� �� : x, y, dir

	for (int dir = current_dir; dir >= 1; dir--) {
		int nx = current_x + dx[dir];
		int ny = current_y + dy[dir];

		//��� ��ġ�� �ƴϸ鼭 ���� ���̶��
		if (1 <= nx && nx <= 4 && 1 <= ny && ny <= 4 && !(nx == shark_x && ny == shark_y) && smell[nx][ny] == 0) {
			fish_arr[nx][ny].push_back(dir);
			return;
		}
	}

	for (int dir = 8; dir > current_dir; dir--) {
		int nx = current_x + dx[dir];
		int ny = current_y + dy[dir];

		//��� ��ġ�� �ƴϸ鼭 ���� ���̶��
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
			//i,j�� �ִ� ����Ⱑ ��� �̵��Ѵ�.
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
				smell[i][j]++; //���� �ð� ����
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
	//�� �̵��Ѵ�.
	
	//������ ��ġ�� ������� �̵�����
	queue <pair<pair<int, int>, info>> q;
	
	string s = "";
	q.push({ {shark_x, shark_y}, {s, 0, -1,-1} });

	string shark_move_info = ""; //��� �̵� ����
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
				//�� ���� �� �ִ� ����� ������ �ִ���
				shark_move_info = tmp_s;
				shark_can_eat_fish_max_num = fish_cnt;
			}
			if (fish_cnt == shark_can_eat_fish_max_num && (shark_move_info.size() == 0 || shark_move_info > tmp_s)) {
				//��� ������ ������ ���� ���ų� ���ŵɸ��ϸ�
				shark_move_info = tmp_s;
			}
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + shark_dx[i];
			int ny = y + shark_dy[i];

			//���ڸ� ����� �ʰ� ���� ũ�Ⱑ �ƴϸ�
			if (1 <= nx && nx <= 4 && 1 <= ny && ny <= 4) {

				char c = i + '0';
				tmp_s += c;
				int current_fish_cnt = fish_arr[nx][ny].size(); //���� ����� ��

				//���� ó�� ���� �Ÿ�, start_x, start_y�� nx,ny�� ����

				//ó�� ���°� �ƴ϶��, nx�� start_x, ny�� starty�� ���ؼ�
				//������ �׳� fish_cnt, �ٸ��� fish_cnt + current_fish_cnt

				if (tmp_s.size() == 1) {
					//ó�� ���� �Ŷ��
					q.push({ {nx,ny}, {tmp_s, fish_cnt + current_fish_cnt, nx,ny} });
				}
				else {
					//��ġ�� �ʴ´ٸ�
					if (!(start_x == nx && start_y == ny)) {
						q.push({ {nx, ny}, {tmp_s, fish_cnt + current_fish_cnt, start_x, start_y} });
					}
					else {
						//��ģ�ٸ�
						q.push({ {nx, ny}, {tmp_s, fish_cnt, start_x, start_y} });
					}
				}
				

				tmp_s.pop_back();
			}
		}
	}

	for (int i = 0; i < shark_move_info.size(); i++) {
		int dir = shark_move_info[i] - '0';

		shark_x += shark_dx[dir]; //��� ��ġ �� ����
		shark_y += shark_dy[dir]; //��� ��ġ �� ����

		if (fish_arr[shark_x][shark_y].size() > 0) {
			fish_arr[shark_x][shark_y].clear(); //����� ���ֱ�
			smell[shark_x][shark_y] = 1; //�������� �ϱ�
		}
	}
}

void erase_smell() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (smell[i][j] == 3) { //2�ʰ� ������
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
		int x, y, d; //����� ��, ��, ��ġ
		cin >> x >> y >> d;
		fish_arr[x][y].push_back(d);
	}

	cin >> shark_x >> shark_y; //��� ��, ��
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}