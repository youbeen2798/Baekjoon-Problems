#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int board[21][21];
bool visited[21][21];
int dist[21][21];
int answer = 0;

pair<int, int> shark;
int shark_size = 2;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(int x, int y, int shark_x, int shark_y) { //1 0 3 0

	queue <pair<int, int>> q;
	memset(dist, 0, sizeof(dist));
	memset(visited, 0, sizeof(visited));

	visited[x][y] = true;
	q.push({ x,y }); //1 0
	dist[x][y] = 0;

	while (!q.empty()) {
		int a = q.front().first; //1
		int b = q.front().second; //0

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n && visited[nx][ny] == false) {
				if (board[nx][ny] <= shark_size || board[nx][ny] == 9) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
					dist[nx][ny] = dist[a][b] + 1;

					if (nx == shark_x && ny == shark_y) {
						return dist[nx][ny];
					}
				}
			}
		}
	}

	return 0; //������ �� ���� ��


}
void solve() {

	vector <pair<int, int>> fish;
	int min_fish_dist = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0 && board[i][j] < shark_size) {
				int dist = bfs(i, j, shark.first, shark.second);
				if (dist == 0) { //������ �� ���� ��
					continue;
				}
				if (min_fish_dist == 0) { //���� ó�� �������
					fish.push_back({ i,j }); //����� ���Ϳ� �־���
					min_fish_dist = dist;
				}
				else { //ó�� ����Ⱑ �ƴ϶��
					if (min_fish_dist == dist) { //������ �ִ� ������ �Ÿ��� ���ٸ�
						fish.push_back({ i,j }); //�־���
					}
					else if (min_fish_dist > dist) { //������ ���� ������� �Ÿ��� �� ũ�ٸ�
						fish.clear(); //����� ���� ����
						fish.push_back({ i,j }); //���� ����� �־���
						min_fish_dist = dist;
					}
				}
			}
		}
	}

	if (fish.size() > 0) {
		answer += min_fish_dist;
	}
	else {
		cout << answer;
		exit(0);

	}


	board[fish[0].first][fish[0].second] = 9; //����� �Ծ �����
	board[shark.first][shark.second] = 0; //�� �̵��ϹǷ� ��� ���� ��ġ�� ��ĭ�̵�
	shark.first = fish[0].first;
	shark.second = fish[0].second; //��� ��ġ �ٲٱ�


}
void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				shark.first = i;
				shark.second = j;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	for (int i = 2;; i++) { //����� �����ŭ 
		for (int j = 0; j < i; j++) { //3		
			solve();
		}
		shark_size = i + 1; //4
	}

}