#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int row, col;
int arr[101][101];
bool visited[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue <pair<int, int>> q;
int cheeze_cnt = 0;

vector<int> v;

int bfs() {

	memset(visited, false, sizeof(visited));

	q.push({ 0,0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; //���ο� ��
			int ny = y + dy[i]; //���ο� ��
			if (0 <= nx && nx < row && 0 <= ny && ny < col && !visited[nx][ny]) {
				if (arr[nx][ny] == 0) { //���⸸ �ִٸ�
					q.push({ nx,ny });
					visited[nx][ny] = true;
				}
				else if (arr[nx][ny] == 1) { //ġ� �ִٸ�
					visited[nx][ny] = true;
				}
			}
		}
	}

	int cheeze_cnt = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 1 && visited[i][j]) {
				arr[i][j] = 0;
			}
			else if (arr[i][j] == 1 && !visited[i][j]) {
				cheeze_cnt++;
			}
		}
	}

	return cheeze_cnt;
}

bool check_all_melt() {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void solution() {

	int time = 0;
	while (true) {

		if (check_all_melt()) { 
			//ġ�� �� ��Ҵ��� check
			break;
		}

		v.push_back(bfs());
		time++; //�ð� �þ
	}

	cout << time << "\n";

	cout << v[v.size() - 2] << "\n";
	
}

void input() {
	cin >> row >> col; //���� ����, ���� ����

	int first_cheeze_cnt = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				first_cheeze_cnt++;
			}
		}
	}
	v.push_back(first_cheeze_cnt);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}