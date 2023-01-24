#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int n, m; // ¼¼·Î Å©±â, °¡·Î Å©±â
int arr[9][9];
bool visited[9][9];
int real_ans = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int original_empty_room_size = 0;

vector<pair<int, int>> empty_room;

void input() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) { //ºóÄ­
				empty_room.push_back({ i,j });
			}
		}
	}

	original_empty_room_size = empty_room.size();
}

 int bfs(int x, int y) {
	queue<pair<int, int>> q;

	q.push({ x,y });
	visited[x][y] = true;
	int tmp_ans = 0;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && arr[nx][ny] != 1) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				if (arr[nx][ny] == 0) { //ºóÄ­ÀÌ¸é
					tmp_ans++;
				}
			}
		}
	}

	return tmp_ans;
}
void check(vector<pair<int,int>> comb) {

	for (int i = 0; i < comb.size(); i++) {
		arr[comb[i].first][comb[i].second] = 1; //ºó Ä­ º®À¸·Î ¸¸µé±â
	}

	memset(visited, false, sizeof(visited));

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2 && !visited[i][j]) {
				ans += bfs(i, j);
			}
		}
	}
	
	int safe_zone_num = original_empty_room_size - ans - 3;
	 
	real_ans = max(real_ans, safe_zone_num);

	for (int i = 0; i < comb.size(); i++) {
		arr[comb[i].first][comb[i].second] = 0; //º® ´Ù½Ã ºóÄ­ ¸¸µé±â
	}

}
void Combination(vector<pair<int, int>> arr, vector<pair<int, int>> comb, int r, int idx, int depth) {

	if (r == 0) {
		check(comb);
	}
	else if (arr.size() == depth) {
		return;
	}
	else {
		comb[idx] = arr[depth];

		Combination(arr, comb, r - 1, idx + 1, depth + 1);
		Combination(arr, comb, r, idx, depth + 1);
	}
}
void solution() {

	vector<pair<int, int>> comb(3);

	Combination(empty_room, comb, 3, 0, 0); 
	cout << real_ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}