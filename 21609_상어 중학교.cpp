#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int arr[21][21];
bool visited[21][21];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>> q;
vector<pair<int, int>> max_block_group;
int max_block_muzigae_num = 0;
long score = 0;

void input() {
	cin >> n >> m; //���� �� ���� ũ��, ������ ����
	//����� ������ ���, ������ ���, �Ϲ� ���
	//�Ϲ� ����� M���� ������ �ְ�, ���� M������ �ڿ����� ǥ��

	//������ ����� -1, ������ ����� 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}


pair<int, int> find_gizun_block(vector <pair<int,int>> v) {

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		if (arr[x][y] != 0) {
			return { x,y };
		}
	}

}
void bfs(int x, int y) {

	memset(visited, false, sizeof(visited));

	vector<pair<int, int>> tmp;
	int color = arr[x][y];
	int num = 1;
	int tmp_muzigae_num = 0;

	q.push({ x, y });
	visited[x][y] = true;
	tmp.push_back({ x,y });
	if (arr[x][y] == 0) {
		tmp_muzigae_num++;
	}

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n && (!visited[nx][ny] && (arr[nx][ny] == 0 || arr[nx][ny] == color))) {
				//�湮�� �� �ϰ�, ������ ����� �ƴ϶��
				q.push({ nx,ny });
				visited[nx][ny] = true;
				tmp.push_back({ nx,ny });
				num++;

				if (arr[nx][ny] == 0) {
					tmp_muzigae_num++;
				}
			}
		}
	}

	//���� ū ��� �������, 2�̻� �̶��
	if (num > max_block_group.size() && num >= 2) {
		max_block_group = tmp; //����
		max_block_muzigae_num = tmp_muzigae_num;
	}
	else if (num == max_block_group.size() && num >= 2) { //��� �׷��� ���� �����
		if (tmp_muzigae_num > max_block_muzigae_num) { //������ ����� �� ���� �����
			max_block_group = tmp;
			max_block_muzigae_num = tmp_muzigae_num;
		}
		else if (tmp_muzigae_num == max_block_muzigae_num) { //������ ��� ������ ���ٸ�
			//������ ����� ���� ���ٸ�
			pair<int, int> original = find_gizun_block(max_block_group);
			pair<int, int> now = find_gizun_block(tmp);

			//���� ����� ���� �� ũ�ٸ�
			if (now > original) {
				max_block_group = tmp;
			}
		}
	}
}
void find_biggest_block_group() {

	memset(visited, false, sizeof(visited));

	max_block_muzigae_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (1 <= arr[i][j] && arr[i][j] <= 5 && !visited[i][j]) {
				bfs(i, j);
			}
		}
	}

	//�� �̻� ���� ����� ���ٸ�
	if (max_block_group.size() == 0) {
		cout << score;
		exit(0);
	}
}

void one_block_gravity(int x, int y) { //�߷� �ۿ�

	pair<int, int> p = { -100,-100 };

	for (int i = x + 1; i < n; i++) {
		if (arr[i][y] == -2) { //��ĭ�̸�
			p = { i, y };
		}
		else {
			break;
		}
	}

	if (p.first != -100 && arr[x][y] != -1) { //-1 ����� �ƴϸ�
		int num = arr[x][y];
		arr[x][y] = -2; //��ĭ���� �����
		arr[p.first][p.second] = num; //���ڷ� ä���
	}
}

void rotate() {
	int arr2[100][100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr2[i][j] = arr[j][abs(n - 1 - i)];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = arr2[i][j];
		}
	}
}
void gravity() { //�߷� �ۿ�

	for (int j = 0; j < n; j++) { //��
		for (int i = n - 1; i >= 0; i--) {
			one_block_gravity(i, j);
		}
	}
}

void erase() {
	for (int i = 0; i < max_block_group.size(); i++) {
		arr[max_block_group[i].first][max_block_group[i].second] = -2; //����
	}

	score += max_block_group.size() * max_block_group.size();

}
void solution() {
	//��� �׷�(����� ����� ���� - �Ϲ� ��� 1�� �̻�, 
	//������ ����� �����ϸ� �� �ǰ�, 
	//������ ����� �� ��� �ֵ� ��� ����
	//�׷쿡 ���� ����� ������ 2���� ũ�ų� ���ƾ� �ϸ�, 
	//���� ����� ������ ����� �ƴ� ��Ͽ��� ���� ��ȣ�� ���� ���� ���, ���� ��ȣ�� ���� ���� ���

	while (true) {
		max_block_group.clear();
		find_biggest_block_group();
		erase();
		gravity();
		rotate();
		gravity();
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}
