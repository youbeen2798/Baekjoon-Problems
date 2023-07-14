#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n; //��
int m; //��
int d; //�ü��� ���� �Ÿ� ����

int input_map[20][20]; //0: ��ĭ, 1: ��, 2: ��
int map[20][20];
bool visited[20][20];

vector<pair<int, int>> v; //�� ��ġ
vector<pair<int, int>> catched; //������ �� ����

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool catching = false; //���� ��� �ִ��� check
int ans = 0;
int tmp_ans = 0;

void copy() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map[i][j] = input_map[i][j];
		}
	}
}
bool inrange(int x, int y) {

	if (1 <= x && x <= n && 1 <= y && y <= m) {
		return true;
	}
	return false;
}

void one_gungsu_offset(pair<int, int > p) {
	//p�� ��ġ�� �ִ� �ü��� ���� �����Ѵ�.

	memset(visited, false, sizeof(visited));

	queue<pair<int, int>> q;
	q.push(p);
	visited[p.first][p.second] = true;

	vector<pair<int, int>> tmp; //���� ���� �� �ִ� �� ��ġ ����
	int min_dist = 100;

	while (!q.empty()) {

		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (inrange(nx, ny) && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });

				int dist = abs(p.first - nx) + abs(p.second - ny);

				//���� ���� �Ÿ� �ȿ� �ִٸ�
				if (dist <= d && map[nx][ny] == 1) {

					if (dist < min_dist) {
						tmp.clear();
						tmp.push_back({ ny,nx });
						min_dist = dist;
					}
					else if (dist == min_dist) {
						tmp.push_back({ ny,nx });
					}
				}
			}
		}
	}

	sort(tmp.begin(), tmp.end());

	if (tmp.empty()) {
		return;
	}

	catched.push_back({tmp[0].second, tmp[0].first});
}

bool all_gungsu_offset(vector<pair<int, int>> comb) {

	catched.clear();

	for (int i = 0; i < comb.size(); i++) {
		one_gungsu_offset(comb[i]);
	}

	if (catched.empty()) {
		return false;
	}

	catched.erase(unique(catched.begin(), catched.end()), catched.end());
	//���� ��������.
	for (int i = 0; i < catched.size(); i++) {
		map[catched[i].first][catched[i].second] = 0;
	}

	tmp_ans += catched.size();
	return true;
}

bool all_juck_move() {

	bool finish_flag = true;

	vector<pair<int, int>> tmp_juck;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1) { //���̶��
				map[i][j] = 0;
				if (i + 1 <= n) {
					tmp_juck.push_back({ i + 1, j });
					finish_flag = false;
				}
			}
		}
	}

	for (int i = 0; i < tmp_juck.size(); i++) {
		map[tmp_juck[i].first][tmp_juck[i].second] = 1;
	}

	return finish_flag;
}
void offset(vector<pair<int, int>> comb) {
	//�ü� ��ġ: comb

	catching = false;
	tmp_ans = 0;

	while (true) {
		all_gungsu_offset(comb);

		bool finish_flag = all_juck_move();

		if (finish_flag) { //���� ���ٸ�
			break;
		}
	}


	ans = max(ans, tmp_ans);
	
}
void combination(vector<pair<int, int>> arr, vector<pair<int, int>> comb, int r, int idx, int depth) {

	if (r == 0) {
		copy();
		offset(comb);
		
	}
	else if (arr.size() == depth) {
		return;
	}
	else {
		comb[idx] = arr[depth];

		combination(arr, comb, r - 1, idx + 1, depth + 1);
		combination(arr, comb, r, idx, depth + 1);
	}
}
void solution() {
;

	vector<pair<int, int>> comb(3);
	//�ü� 3�� ��ġ(���� �ִ� ĭ�� ��ġ)

	combination(v, comb, 3, 0, 0);
	cout << ans;
	
}

void input() {

	cin >> n >> m >> d;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m;  j++) {
			cin >> input_map[i][j];
		}
	}

	for (int j = 1; j <= m; j++) {
		v.push_back({ n + 1, j });
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}