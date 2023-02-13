#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; //ü���� ũ��
int k; //�� ����
int arr[13][13]; //ü���� ���� (0 - ���, 1 - ������, 2 - �Ķ���)
vector<int> horse_arr[13][13]; //�� �ڸ��� ����ִ� �� ��ȣ ����
int tc = 1;

struct info {
	int x; //��
	int y; //��
	int dir; //����
};
// 1- ������, 2- ����, 3- ����, 4- �Ʒ���

info horses[11];

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

bool in_round(int x, int y) {
	if (1 <= x && x <= n && 1 <= y && y <= n) {
		return true;
	}
	return false;
}
bool one_horse_move(int horse_num) {
	//���� ���� true�̸� �ٽ� �ѹ� ����

	int dir = horses[horse_num].dir; // �� ����
	int x = horses[horse_num].x; //�� ��
	int y = horses[horse_num].y; //�� ��
	vector<int> horse_nums = horse_arr[x][y]; //���� �ڸ��� �ִ� �� ����


	int nx = x + dx[dir]; //������ �� ��
	int ny = y + dy[dir]; //������ �� ��

	if (in_round(nx, ny) && arr[nx][ny] == 0) {
		//�̵��Ϸ��� ĭ�� ����̶��
		int horse_idx = find(horse_nums.begin(), horse_nums.end(), horse_num) - horse_nums.begin();

		vector <int> moving_horses;

		int size = horse_arr[x][y].size();
		for (int i = size - 1; i >= horse_idx; i--) {
			int num = horse_arr[x][y].back();
			moving_horses.push_back(num);
			horse_arr[x][y].pop_back();
		}

		reverse(moving_horses.begin(), moving_horses.end());

		for (int i = 0; i < moving_horses.size(); i++) {
			int horse_num = moving_horses[i];
			horse_arr[nx][ny].push_back(horse_num);
			horses[horse_num].x = nx; //�� ��
			horses[horse_num].y = ny; //�� ��
		}

		if (horse_arr[nx][ny].size() >= 4) {
			cout << tc << "\n";
			exit(0);
		}
	}
	else if (in_round(nx, ny) && arr[nx][ny] == 1) {
		//�̵��Ϸ��� ĭ�� �������̶��
		int horse_idx = find(horse_nums.begin(), horse_nums.end(), horse_num) - horse_nums.begin();

		vector <int> moving_horses;

		int size = horse_arr[x][y].size();
		for (int i = size - 1; i >= horse_idx; i--) {
			int num = horse_arr[x][y].back();
			moving_horses.push_back(num);
			horse_arr[x][y].pop_back();
		}

		for (int i = 0; i < moving_horses.size(); i++) {
			int horse_num = moving_horses[i];
			horse_arr[nx][ny].push_back(horse_num);
			horses[horse_num].x = nx; //�� ��
			horses[horse_num].y = ny; //�� ��
		}

		if (horse_arr[nx][ny].size() >= 4) {
			cout << tc << "\n";
			exit(0);
		}
	}
	else {
		//�̵��Ϸ��� ĭ�� �Ķ����̶��

		if (dir % 2 == 0) {
			horses[horse_num].dir -= 1;
		}
		else {
			horses[horse_num].dir += 1;
		}

		dir = horses[horse_num].dir; //�ٲ� ����

		int nx = x + dx[dir]; //������ �� ��
		int ny = y + dy[dir]; //������ �� ��

		//������ ���� ü�� �ȿ� �Ķ����� �ƴ϶��
		if (1 <= nx && nx <= n && 1<= ny && ny <= n && arr[nx][ny] != 2) { 
			return true;
		}
	}
	return false;
}

void all_horse_move() {
	for (int i = 1; i <= k; i++) {
		bool again = one_horse_move(i);
		if (again) {
			one_horse_move(i);
		}
	}
}
void solution() {

	for (tc = 1; tc <= 1000 ; tc++) {
		all_horse_move();
	}
	
	cout << -1;
}

void input() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i <= k; i++) {
		int x;
		int y;
		int dir;
		cin >> x >> y >> dir;
		horses[i] = { x,y,dir };
		horse_arr[x][y].push_back(i);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}