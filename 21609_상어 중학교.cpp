#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n; //���� �� ���� ũ��
int m; //���� ����
int map[21][21];
bool visited[21][21];
bool check[21][21];
int ans = 0;

struct info {

	int block_num; //��� ����
	int muzigae_num; //������ ��� ����
	int gizun_block_x; //���� ��� ��
	int gizun_block_y; //���� ��� ��
};

vector<info> v;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool compare(info i1, info i2) {

	if (i1.block_num > i2.block_num) {
		return true;
	}
	else if (i1.block_num == i2.block_num) {
		if (i1.muzigae_num > i2.muzigae_num) {
			return true;
		}
		else if (i1.muzigae_num == i2.muzigae_num) {
			if (i1.gizun_block_x > i2.gizun_block_x) {
				return true;
			}
			else if (i1.gizun_block_x == i2.gizun_block_x) {
				if (i1.gizun_block_y > i2.gizun_block_y) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

}
bool inrange(int x, int y) {
	if (0 <= x && x < n && 0 <= y && y < n) {
		return true;
	}
	return false;
}

void bfs(int x, int y) {

	memset(visited, false, sizeof(visited));

	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	int num = map[x][y];
	check[x][y] = true;

	int tmp_muzigae_num = 0; //������ ��� ����
	
	vector<pair<int, int>> general_blocks; //�Ϲ� ��� ����
	general_blocks.push_back({ x,y });

	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now_x + dx[i];
			int ny = now_y + dy[i];

			if (inrange(nx, ny) && !visited[nx][ny] && map[nx][ny] != -1) {
				visited[nx][ny] = true;

				if (map[nx][ny] == 0) { //������ ����̶��
					tmp_muzigae_num++;
					q.push({ nx,ny });
				}
				else if(map[nx][ny] == num) {
					general_blocks.push_back({ nx,ny });
					check[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}

	sort(general_blocks.begin(), general_blocks.end());

	int this_block_num = tmp_muzigae_num + general_blocks.size();
	int this_gizun_x = general_blocks[0].first;
	int this_gizun_y = general_blocks[0].second;

	if (this_block_num > 1) {
		v.push_back({ this_block_num, tmp_muzigae_num, this_gizun_x, this_gizun_y });
	}
}

void real_bfs(int x, int y) {

	memset(visited, false, sizeof(visited));

	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	int num = map[x][y];

	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;

		map[now_x][now_y] = -2;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now_x + dx[i];
			int ny = now_y + dy[i];

			if (inrange(nx, ny) && !visited[nx][ny] && map[nx][ny] != -1) {
				visited[nx][ny] = true;

				if (map[nx][ny] == 0) { //������ ����̶��
					q.push({ nx,ny });
				}
				else if (map[nx][ny] == num) {
					q.push({ nx,ny });
				}
			}
		}
	}
}
void find_biggest_block_group() {

	v.clear();
	memset(check, false, sizeof(check));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (0 < map[i][j] && !check[i][j]) {
				bfs(i, j);
			}
		}
	}

	sort(v.begin(), v.end() ,compare);

	if (v.size() == 0) {
		cout << ans << "\n";
		exit(0);
	}

	ans += v[0].block_num * v[0].block_num;
	real_bfs(v[0].gizun_block_x, v[0].gizun_block_y);
}

void down(int x, int y) {

	int num = map[x][y];
	int nx = x;
	for (int i = x + 1; i < n; i++) {
		if (map[i][y] == -2) {
			nx = i;
		}
		else {
			break;
		}
	}

	map[x][y] = -2;
	map[nx][y] = num;
}
void zoong_luck() {
	//�߷� �ۿ�

	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (map[i][j] >=  0) {
				down(i, j);
			}
		}
	}
}

void un_clock() {

	int arr2[21][21];

	for (int i = 0;  i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr2[i][j] = map[j][abs(n - 1 - i)];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = arr2[i][j];
		}
	}
}
void one_auto_play() {
	//�� ���� �����÷���

	find_biggest_block_group(); //ũ�Ⱑ ���� ū ��� �׷��� ã�´�.
	zoong_luck(); //�߷� �ۿ�
	un_clock(); //�ݽð� ����
	zoong_luck(); //�߷� �ۿ�
}
void solution() {
	
	for (int i = 1;; i++) {
		one_auto_play();
	}

}

void input() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
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