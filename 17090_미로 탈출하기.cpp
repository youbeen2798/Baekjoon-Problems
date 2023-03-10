#include <iostream>
#include <set>

using namespace std;

int n;
int m;
int now_num = 0;
char arr[501][501];
int can_exit[501][501] = { 0, };
//1이면 방문했는데 가능
//2이면 방문했는데 불가능

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool possible = false;

void dfs(int x, int y) {

	//이동하던 중에 만약 can_exit가 가능한 칸을 만나면, 이동이 가능할 것이므로 possible = true
	if (x < 0 || n <= x || y < 0 || m <= y || can_exit[x][y] == 2) {
		possible = true;
		return;
	}

	//방문이 불가능하면
	if (can_exit[x][y] == 1) {
		possible = false;
		return;
	}

	//재방문하게 되면 무한루프를 도는 것이므로 return
	if (can_exit[x][y] == now_num) {
		return;
	}

	can_exit[x][y] = now_num;

	
	if (arr[x][y] == 'U') {
		dfs(x - 1, y);
	}
	else if (arr[x][y] == 'R') {
		dfs(x, y + 1);
	}
	else if (arr[x][y] == 'D') {
		dfs(x + 1, y);
	}
	else if (arr[x][y] == 'L') {
		dfs(x, y - 1);
	}
}

void reverse_dfs(int x, int y) {
	//거꾸로 가는 dfs 쓰기

	if (possible) {
		can_exit[x][y] = 2;
	}
	else {
		can_exit[x][y] = 1;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < m && can_exit[nx][ny] == now_num) {
			reverse_dfs(nx, ny);
		}
	}


}
void solution() {

	int ans = 0;

	now_num = 3;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//possible : 가능한지 확인하는 플래그
			possible = false;
			//now_num : 매번 dfs를 할 때마다 이동했었던 (i,j)를 num으
			++now_num;
			dfs(i, j);
			
			//가능한 수 갱신
			ans += possible;

			reverse_dfs(i, j);		
		}
	}

	cout << ans;
}

void input() {

	cin >> n >> m;

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
	solution();
}
