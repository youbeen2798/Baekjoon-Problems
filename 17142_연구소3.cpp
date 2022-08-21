#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int board[51][51];
int distances[51][51];


bool room[51][51];
bool visited[51][51];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int virus_size = 0;
int answer = 3000;

bool impossible = true;

vector <pair<int, int>> virus; //바이러스 위치 저장



void bfs(int x, int y) { //바이러스 있는 곳부터 시작


	queue <pair<int, int>> q; //0 0

	q.push({ x,y });
	distances[x][y] = 0;
	visited[x][y] = true;

	while (!q.empty()) {

		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (visited[nx][ny] == false && board[nx][ny] != 1) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
					distances[nx][ny] = min(distances[a][b] + 1, distances[nx][ny]);
				}
			}
		}
	}

}


void solve(vector <pair<int, int>> now_virus) {

	for (int s = 0; s < n; s++) {
		for (int t = 0; t < n; t++) {
			distances[s][t] = 999999;
		}
	}

	for (auto i : now_virus) {
		memset(visited, false, sizeof(visited));

		bfs(i.first, i.second);


	}

	int tmp_answer = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (distances[i][j] == 999999 && board[i][j] == 0) {
				impossible = true;
				return;
			}

			if (distances[i][j] != 999999 && board[i][j] == 0) {
				if (tmp_answer < distances[i][j]) {
					tmp_answer = distances[i][j];
				}
			}


		}
	}

	impossible = false;
	answer = min(answer, tmp_answer);




}

void combination(vector <int> arr, vector <int> comb, int r, int index, int depth) {
	if (r == 0) {

		vector <pair<int, int>> now_virus;

		for (int i = 0; i < comb.size(); i++) { // 0 3 4
			now_virus.push_back({ virus[comb[i]].first, virus[comb[i]].second });
		}
		solve(now_virus);
	}
	else if (depth == arr.size()) {
		return;
	}
	else {

		//arr[depth]를 뽑는 경우
		comb[index] = arr[depth];
		combination(arr, comb, r - 1, index + 1, depth + 1);

		//arr[depth]를 뽑지 않는 경우
		combination(arr, comb, r, index, depth + 1);
	}
}

void input() {

	cin >> n >> m;

	bool zerocontain = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virus_size++; //5
				virus.push_back({ i,j }); //바이러스 위치 저장
			}
			if (board[i][j] == 0) {
				zerocontain = true;
			}
		}
	}

	if (!zerocontain) { //만약 빈방이 없으면
		cout << 0;
		exit(0);
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	vector <int> arr;

	for (int i = 0; i < virus_size; i++) {
		arr.push_back(i); //0 1 2 3 4
	}

	vector <int> comb(m);
	combination(arr, comb, m, 0, 0);

	if (answer == 3000) {
		cout << -1;
	}
	else {
		cout << answer;
	}
}

