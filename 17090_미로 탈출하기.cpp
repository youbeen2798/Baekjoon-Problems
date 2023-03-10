#include <iostream>
#include <set>

using namespace std;

int n;
int m;
int now_num = 0;
char arr[501][501];
int can_exit[501][501] = { 0, };
//1�̸� �湮�ߴµ� ����
//2�̸� �湮�ߴµ� �Ұ���

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool possible = false;

void dfs(int x, int y) {

	//�̵��ϴ� �߿� ���� can_exit�� ������ ĭ�� ������, �̵��� ������ ���̹Ƿ� possible = true
	if (x < 0 || n <= x || y < 0 || m <= y || can_exit[x][y] == 2) {
		possible = true;
		return;
	}

	//�湮�� �Ұ����ϸ�
	if (can_exit[x][y] == 1) {
		possible = false;
		return;
	}

	//��湮�ϰ� �Ǹ� ���ѷ����� ���� ���̹Ƿ� return
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
	//�Ųٷ� ���� dfs ����

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
			//possible : �������� Ȯ���ϴ� �÷���
			possible = false;
			//now_num : �Ź� dfs�� �� ������ �̵��߾��� (i,j)�� num��
			++now_num;
			dfs(i, j);
			
			//������ �� ����
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
