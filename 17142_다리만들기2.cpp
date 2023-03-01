#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n, m;
int arr[11][11];
bool visited[11][11];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int land_num = 0;
int ans = 987654321;

int parent[7];

struct connect_info {

	//육지1과 육지2를 dist로 연결 가능하다.
	int land_num1;
	int land_num2;
	int dist;
};

vector<connect_info> connect_land_infos;

void bfs(int x, int y) {


	land_num += 1;

	vector<pair<int, int>> lands;

	lands.push_back({ x,y });
	queue<pair<int, int>> q;
	visited[x][y] = true;

	q.push({ x,y });

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !visited[nx][ny] && arr[nx][ny] == 1) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				lands.push_back({ nx,ny });
			}
		}
	}

	for (int i = 0; i < lands.size(); i++) {
		arr[lands[i].first][lands[i].second] = land_num;
	}
}

int check_right(int x, int y, int land_num2) {

	for (int j = y + 1; j <= m; j++) {
		if (arr[x][j] == 0) {
			//바다이면 넘어감
			continue;
		}
		else if (arr[x][j] == land_num2) {
			int dist = j - y;
			return dist;
		}
		return -1;
	}

	return -1;
}

int check_left(int x, int y, int land_num2) {

	for (int j = y - 1; j >= 1; j--) {
		if (arr[x][j] == 0) {
			//바다이면 넘어감
			continue;
		}
		else if (arr[x][j] == land_num2) {
			int dist = y - j;
			return dist;
		}
		return -1;
	}

	return -1;
}

int check_down(int x, int y, int land_num2) {
	for (int i = x + 1; i <= n; i++) {
		if (arr[i][y] == 0) {
			//바다이면 넘어감
			continue;
		}
		else if (arr[i][y] == land_num2) {
			int dist = i - x;
			return dist;
		}
		return -1;
	}

	return -1;
}

int check_up(int x, int y, int land_num2) {
	for (int i = x - 1; i >= 1; i--) {
		if (arr[i][y] == 0) {
			//바다이면 넘어감
			continue;
		}
		else if (arr[i][y] == land_num2) {
			int dist = x - i;
			return dist;
		}
		return -1;
	}
	return -1;
}

int connect(int land_num1, int land_num2) {
	//육지 1과 육지 2를 연결한다.

	int tmp_min_dist = 999999999;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == land_num1) {

				//오른쪽
				int right_dist = check_right(i, j, land_num2);
				if (right_dist != -1 && right_dist >= 3) {
					tmp_min_dist = min(tmp_min_dist, right_dist);
				}
				//왼쪽
				int left_dist = check_left(i, j, land_num2);
				if (left_dist != -1 && left_dist >= 3) {
					tmp_min_dist = min(tmp_min_dist, left_dist);
				}
				//아래쪽
				int down_dist = check_down(i, j, land_num2);
				if (down_dist != -1 && down_dist >= 3) {
					tmp_min_dist = min(tmp_min_dist, down_dist);
				}
				//위쪽
				int up_dist = check_up(i, j, land_num2);
				if (up_dist != -1 && up_dist >= 3) {
					tmp_min_dist = min(tmp_min_dist, up_dist);
				}
			}
		}
	}

	tmp_min_dist -= 1;

	if (tmp_min_dist == 999999998) {
		return -1;
	}

	return tmp_min_dist;
}

int get_parent(int num) {

	if (num == parent[num]) {
		return num;
	}

	return parent[num] = get_parent(parent[num]);
}
void union_find(int x, int y) {

	x = get_parent(x);
	y = get_parent(y);

	//parent[4] = 1
	if (x == y) {
		return;
	}
	else if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

void renew_parent() {
	for (int i = 1; i <= land_num; i++) {
		parent[i] = i;
	}
}
void combination(vector<connect_info> arr, vector<connect_info> comb, int r, int idx, int depth) {

	if (r == 0) {

		long total_dist = 0;

		renew_parent();
		for (int i = 0; i < comb.size(); i++) {
			total_dist += comb[i].dist;
			union_find(comb[i].land_num1, comb[i].land_num2);
		}

		//만약에 다 연결되었다면

		for (int i = 1; i < land_num; i++) {
			if (get_parent(i) != get_parent(i+1)) {
				return;
			}
		}
		
		if (total_dist < ans) {
			ans = total_dist;
		}
		return;
	}
	else if (depth == arr.size()) {
		return;
	}
	else {
		comb[idx] = arr[depth];

		combination(arr, comb, r - 1, idx + 1, depth + 1);

		combination(arr, comb, r, idx, depth + 1);
	}
}
void solution() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] != 0 && !visited[i][j]) {
				bfs(i, j);
			}
		}
	}

	
	//land_num : 육지 개수
	for (int i = 1; i <= land_num; i++) {
		for (int j = i + 1; j <= land_num; j++) {
			int min_dist = connect(i, j);

			if (min_dist != -1) {
				//연결할 수 있다면
				connect_land_infos.push_back({ i, j, min_dist });
			}
		}
	}

	
	//다리 개수
	int bridge_num = connect_land_infos.size();

	for (int i = 1; i <= bridge_num; i++) {
		vector<connect_info> comb(i);
		combination(connect_land_infos, comb, i, 0, 0);
	}

	if (ans != 987654321) {
		cout << ans << "\n";
	}
	else {
		cout << -1;
	}	
}

void input() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
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