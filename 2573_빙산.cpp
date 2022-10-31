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

	memset(icecnt, 0, sizeof(icecnt)); //0으로 초기화
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			if (arr[i][j]) { //0이 아니면	
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k]; //위 아래 왼쪽 오른쪽
					int ny = j + dy[k]; //위 아래 왼쪽 오른쪽
					
					//해당 방향이 범위를 유지하면서 얼음이라면
					if (0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] != 0) {
						cnt++;
					}
				}
				icecnt[i][j] = 4 - cnt; //cnt란 주변 얼음이 없는 개수
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

//모두 다 녹았는지 확인하는 메소드
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
	cin >> n >> m; //행의 개수와 열의 개수

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

		//다 녹은 다음에 확인
		memset(visited, false, sizeof(visited)); //방문 안한걸로 모두 처리

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0 && !visited[i][j]) { //방문하지 않았고 얼음이 있다면
					bfsCnt++; //bfs가 불린 횟수
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

		//	cout << "현재 bfsCnt: " << bfsCnt << " ans: " << ans << "\n";

		if (bfsCnt >= 2) {
			break;
		}
		else if (allmelted()) { //다 녹았는데 분리되지 않았
			cout << "0";
			exit(0);
		}
	}

	cout << ans;
	

}