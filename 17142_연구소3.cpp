#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int n; //연구소의 크기
int m; //놓을 수 있는 바이러스 개수
int arr[51][51];
int dist[51][51];
bool visited[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int real_ans = 999999999;
int tmp_ans = 0;
set<pair<int, int>> now_virus;

vector<pair<int, int>> virus;

void bfs(int x, int y) {
	
	memset(visited, false, sizeof(visited));

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

			if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && ((arr[nx][ny] == 0 )|| (arr[nx][ny] == 2 && now_virus.find({nx,ny}) == now_virus.end()))) {
				visited[nx][ny] = true;

				if (dist[nx][ny] == 0) {
					dist[nx][ny] = dist[a][b] + 1;
				}
				else {
					dist[nx][ny] = min(dist[nx][ny], dist[a][b] + 1);
				}
				q.push({ nx,ny });
			}
		}
	}
}

bool check_all_virus(){

	tmp_ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			//바이러스이면서 비활성바이러스면
			if (arr[i][j] == 2 && now_virus.find({ i,j }) == now_virus.end()) {
				continue;
			}
			tmp_ans = max(dist[i][j], tmp_ans);
			if (arr[i][j] == 2 || arr[i][j] == 1 || dist[i][j] != 0) {
			}
			else {
				return false;
			}
		}
	}
	return true;
}

void mini_solution(vector<pair<int, int>> comb) {

	memset(dist, 0, sizeof(dist));

	for (int i = 0; i < comb.size(); i++) {
		bfs(comb[i].first, comb[i].second);
	}

	if (check_all_virus()) {
		real_ans = min(real_ans, tmp_ans);
	}
}

void Combination(vector<pair<int, int>> arr, vector<pair<int, int>> comb, int r, int idx, int depth) {
	if (r == 0) {
	//	cout << "###comb" << "\n";
		now_virus.clear();
		for (int i = 0; i < comb.size(); i++) {
			now_virus.insert({ comb[i].first, comb[i].second });
	//		cout << comb[i].first << " , " << comb[i].second << "\n";
		}
		tmp_ans = 0;
		mini_solution(comb);

		if (check_all_virus()) {
			real_ans = min(tmp_ans, real_ans);
		}
	}
	else if (depth == arr.size()) {
		return;
	}
	else {
		comb[idx] = arr[depth];

		Combination(arr, comb, r - 1, idx + 1, depth + 1);

		Combination(arr, comb, r, idx, depth + 1);
	}
}
void solution() {

	vector<pair<int, int>> comb(m);

	Combination(virus, comb, m, 0, 0);
	
	if (real_ans == 999999999) {
		cout << -1;
		exit(0);
	}
	cout << real_ans;
}

void input() {

	cin >> n >> m; //연구소 크기, 놓을 수 있는 바이러스 개수

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
			}
			//0은 빈칸
			//1은 벽
			//2는 바이러스를 놓을 수 있는 위치
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
/*
8 3
2 0 0 0 1 1 0 0
0 0 1 0 1 2 0 0
0 1 1 0 1 0 0 0
0 1 0 0 0 0 0 0
0 0 0 2 0 1 1 0
0 1 0 0 0 0 0 0
2 1 0 0 0 0 2 0
0 0 0 0 0 0 0 0
*/