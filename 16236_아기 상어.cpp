#include <iostream>
#include <queue>
using namespace std;

int n;
pair<int, int> baby_shark; //�Ʊ� ���
int baby_shark_size = 2; //�Ʊ� ��� ũ��
int stomache = 0; //����Ⱑ ���� ũ��

int arr[21][21];
bool visited[21][21];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int times = 0;

struct position {
	int x; //��
	int y; //��
};

bool compare(pair<int, position> a, pair<int, position> b) {
	if (a.first != b.first) { //�Ÿ��� �ٸ��ٸ�
		return a.first < b.first; //�Ÿ��� ������������
	}
	if (a.second.x != b.second.x) { //���� �ٸ��ٸ�
		return a.second.x < b.second.x; //���� ������������
	}
	return a.second.y < b.second.y; //���� ������������
}

void eat_fish() {
	//���� �� �ִ� ����� ����

	vector<pair<int, position>> can_eat_fish; //���� �� �ִ� ������
	memset(visited, false, sizeof(visited));

	int min_dist = 999999;
	queue<pair<int, position>> q;
	q.push({ 0,{ baby_shark.first, baby_shark.second }});
	visited[baby_shark.first][baby_shark.second] = true;

	while (!q.empty()) {
		int dist = q.front().first; //�Ÿ�
		int x = q.front().second.x; //��ġ ��
		int y = q.front().second.y; //��ġ ��

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && arr[nx][ny] <= baby_shark_size) {
				visited[nx][ny] = true;
				q.push({ dist + 1, {nx,ny} });

				if (arr[nx][ny] == baby_shark_size || arr[nx][ny] == 0) {
					//ũ�Ⱑ ���ų� ��ĭ�̸� �׳� ��������
					continue;
				}
				if (dist + 1 < min_dist) {
					//�ּҰŸ� ���� �� �۴ٸ�
					can_eat_fish.clear();
					min_dist = dist + 1;
					can_eat_fish.push_back({ dist + 1, {nx,ny} });
				}
				else if (dist + 1 == min_dist) {
					//�ּҰŸ��� ���ٸ�
					can_eat_fish.push_back({ dist + 1, {nx,ny} });
				}
			}
		}
	}

	if (can_eat_fish.size() == 0) {
		//���� �� �ִ� ����Ⱑ ���ٸ�
		cout << times;
		exit(0);
	}
	sort(can_eat_fish.begin(), can_eat_fish.end(), compare);

	int eaten_fish_x = can_eat_fish[0].second.x;
	int eaten_fish_y = can_eat_fish[0].second.y;
	int dist = can_eat_fish[0].first;

	arr[baby_shark.first][baby_shark.second] = 0;
	baby_shark = { eaten_fish_x, eaten_fish_y }; //�Ʊ� ��� ��ġ
	arr[eaten_fish_x][eaten_fish_y] = 9; //���� ����� �ڸ��� �Ʊ� �� �̵�
	times += dist;

	if (++stomache == baby_shark_size) {
		baby_shark_size++; //�Ʊ� ��� ũ�� Ŀ��
		stomache = 0;
	}
}

void solution() {

	while (true) {
		memset(visited, false, sizeof(visited));

		eat_fish();
	}
}

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				baby_shark = { i,j }; //�Ʊ� ���
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