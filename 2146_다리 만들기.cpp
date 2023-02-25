#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;
int map[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool visited[101][101];
int real_ans = 999999999;
int dist[101][101]; //�Ÿ�

int land_num = 2;

void find_lands(int x, int y) {
	//(x,y)�κ��� ����� ������

	set<pair<int, int>> land; //�ѹ��� ����� ���� (x,y) ����

	queue<pair<int, int>> q;

	q.push({ x,y });
	visited[x][y] = true;
	map[x][y] = land_num;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && map[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				map[nx][ny] = land_num;
			}
		}
	}
}

void find_other_land(int x, int y) {
	//�ٸ� ������ ã��

	memset(visited, false, sizeof(visited));

	queue <pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	dist[x][y] = 0;
	int now_land_num = map[x][y];

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		int now_dist = dist[a][b];

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			pair<int,int> p = { nx,ny };
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && map[nx][ny] != now_land_num) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				dist[nx][ny] = now_dist + 1;

				//�ٸ� �������
				if (map[nx][ny] != 0) {
			//		cout << "now_dist: " << now_dist << "\n";
					real_ans = min(real_ans, now_dist);
					return;
				}
			}
		}
	}
}
void solution() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && !visited[i][j]) { //�����̸�
				find_lands(i, j);
				land_num += 1;
			}
		}
	}


	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0 && !visited[i][j]) { //�����̸�
	//			cout << "i: " << i << " j: " << j << "\n";
				find_other_land(i, j);
			}
		}
	}

	cout << real_ans;
}

void input() {
	cin >> n;

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