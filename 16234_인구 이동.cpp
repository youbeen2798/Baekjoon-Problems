#include <iostream>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

int n, l, r;

int arr[51][51];
int tmp[51][51];
bool visited[51][51];
int times = 0;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool changed = false;

void bfs(int x, int y) {

	set<pair<int, int>> s;

	queue <pair<int, int>> q;
	visited[x][y] = true;

	int total_num = 0;

	q.push({ x,y });
	s.insert({ x,y });
	total_num += arr[x][y];

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		int num1 = arr[a][b];

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			int diff = abs(num1 - arr[nx][ny]); 

			if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && l <= diff && diff <= r) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				s.insert({ nx,ny });
				total_num += arr[nx][ny];
			}
		}
	}

	int average = total_num / s.size();
	
	for (auto p : s) {
		tmp[p.first][p.second] = average;
	}

}

bool is_changed() {
	//복사하면서 바뀌었는지 확인

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp[i][j] != arr[i][j]) {
				arr[i][j] = tmp[i][j];
				changed = true;
			}
		}
	}
	return changed;
}
void solution() {
	//두 나라의 인구 차이가 L명 이상 R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루동안 염


	while (true) {
		times++;
		changed = false;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					bfs(i, j);
				}
			}
		}

		if (!is_changed()) {
			//바뀌지 않았으면
			break;
		}
	}
	cout <<  times - 1;
		

}

void input() {
	cin >> n >> l >> r; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
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