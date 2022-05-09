//BFS 혹은 DFS로 풀이 가능
//해당 코드는 BFS로 풀이함 

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[100][100];
bool visited[100][100];
int input[100][100];
int cnt = 0; //영역 개수
int  n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue <pair<int,int>> q;
vector <int> v; //영역 개수 저장 벡터

void BFS(int x, int y) {

	visited[x][y] = true;
	q.push(make_pair(x, y));

	while (!q.empty()) {

		x = q.front().first; 
		y = q.front().second; 
		q.pop();

		for (int k = 0; k < 4; k++) {

			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (map[nx][ny] == 1 && visited[nx][ny] == 0) {
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
			map[i][j] = 0;
		}
	}
	cnt = 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int maxheight = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
			if (input[i][j] > maxheight)
				maxheight = input[i][j];
		}
	}

	for (int h = 1; h <= maxheight; h++) { //1이상 최대이하

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (input[i][j] >= h)
					map[i][j] = 1;
				else
					map[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					BFS(i, j);
					cnt++;
				}
			}
		}

		v.push_back(cnt);
		reset(); //초기화
	}

	sort(v.begin(), v.end()); //오름차순 정렬
	cout << v[v.size() - 1]; //최댓값 출력
}