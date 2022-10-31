#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
bool ismelt = false; 
int icecnt[301][301];
int arr[301][301];

bool visited[301][301];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void solution() {

	memset(icecnt, 0, sizeof(icecnt)); //0���� �ʱ�ȭ
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			if (arr[i][j]) { //0�� �ƴϸ�	
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k]; //�� �Ʒ� ���� ������
					int ny = j + dy[k]; //�� �Ʒ� ���� ������
					
					//�ش� ������ ������ �����ϸ鼭 �����̶��
					if (0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] != 0) {
						cnt++;
					}
				}
				icecnt[i][j] = 4 - cnt; //cnt�� �ֺ� ������ ���� ����
			}
		}
	}
}


void melt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0 && icecnt[i][j] > 0) {
				ismelt = true;
				if (arr[i][j] <= icecnt[i][j]) {
					arr[i][j] = 0;
				}
				else {
					arr[i][j] -= icecnt[i][j];
				}
			}
		}
	}
}

//��� �� ��Ҵ��� Ȯ���ϴ� �޼ҵ�
bool allmelted() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] != 0 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
void input() {
	cin >> n >> m; //���� ������ ���� ����

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	int ans = 0;
	while (true) {

		ans++;
		int bfsCnt = 0;

		solution();
		melt();

		//�� ���� ������ Ȯ��
		memset(visited, false, sizeof(visited)); //�湮 ���Ѱɷ� ��� ó��

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0 && !visited[i][j]) { //�湮���� �ʾҰ� ������ �ִٸ�
					bfsCnt++; //bfs�� �Ҹ� Ƚ��
					bfs(i, j);
				}
			}
		}

		cout << "---------------------------" << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}

		//	cout << "���� bfsCnt: " << bfsCnt << " ans: " << ans << "\n";

		if (bfsCnt >= 2) {
			break;
		}
		else if (allmelted()) { //�� ��Ҵµ� �и����� �ʾ�
			cout << "0";
			exit(0);
		}
	}

	cout << ans;
	

}