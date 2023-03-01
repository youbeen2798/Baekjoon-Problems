#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

int r, c, t;
int arr[51][51];
int plus_dust[51][51];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

pair<int, int> air_fresh1; //공기 청정기 윗 몸통
pair<int, int> air_fresh2; //공기 청정기 아래 몸통

void real_spread(int x, int y) {

	int dust_amount = arr[x][y]; //원래 있던 먼지 양

	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		//범위를 넘지 않으면서 미세먼지가 있다면
		if (1 <= nx && nx <= r && 1 <= ny && ny <= c && arr[nx][ny] != -1) {
			plus_dust[nx][ny] += dust_amount / 5;
			cnt++;
		}
	}

	//3번 뿌린 만큼 3번 - 
	plus_dust[x][y] -= cnt * (dust_amount / 5);
}
void dust_spread() {

	memset(plus_dust, 0, sizeof(plus_dust));

	//미세먼지가 확산된다.
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			//공기청정기가 아니고, 미세먼지가 있다면 확산된다.
			if (arr[i][j] != -1 && arr[i][j] != 0) {
				real_spread(i, j);
			}
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			arr[i][j] += plus_dust[i][j];
		}
	}
}

void dust_rotate1() {

	//공기청정기 바로 위에 있는 먼지 삭제
	int air_fresh_x = air_fresh1.first;
	int air_fresh_y = air_fresh1.second;

	arr[air_fresh_x - 1][air_fresh_y] = 0;


	//아래로
	for (int i = air_fresh_x - 2; i >= 0; i--) {
		arr[i + 1][air_fresh_y] = arr[i][air_fresh_y];
	}

	//왼쪽으로
	for (int j = 1; j <= c; j++) {
		arr[1][j - 1] = arr[1][j];
	}

	//위쪽으로
	for (int i = 2; i <= air_fresh_x; i++) {
		arr[i - 1][c] = arr[i][c];
	}

	//오른쪽으로
	for (int j = c - 1; j >= air_fresh_y + 1; j--) {
		arr[air_fresh_x][j + 1] = arr[air_fresh_x][j];
	}
	arr[air_fresh_x][air_fresh_y + 1] = 0;
}

void dust_rotate2() {

	//아래 청소기 순환
	int air_fresh_x = air_fresh2.first;
	int air_fresh_y = air_fresh2.second;

	//위로
	for (int i = air_fresh_x + 1; i < r; i++) {
		arr[i][1] = arr[i + 1][1];
	}

	//왼쪽으로
	for (int j = 0; j < c; j++) {
		arr[r][j] = arr[r][j + 1];
	}

	//아래로
	for (int i = r; i > air_fresh_x; i--) {
		arr[i][c] = arr[i - 1][c];
	}

	//오른쪽으로
	for (int j = c; j > air_fresh_y + 1; j--) {
		arr[air_fresh_x][j] = arr[air_fresh_x][j - 1];
	}

	arr[air_fresh_x][air_fresh_y + 1] = 0;

}
void dust_rotate() {
	//먼지가 순회한다.
	dust_rotate1();
	dust_rotate2();
}
void output() {

	long ans = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] != -1) { //공기 청정기가 아니라면
				ans += arr[i][j];
			}
		}
	}

	cout << ans;
}

void solution() {

	for (int i = 0; i < t; i++) {
		dust_spread();
		dust_rotate();
	}
	output();

}
void input() {

	vector<pair<int, int>> air_freshes;

	cin >> r >> c >> t;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == -1) { //공기 청정기라면
				air_freshes.push_back({ i,j });
			}
		}
	}

	air_fresh1 = air_freshes[0];
	air_fresh2 = air_freshes[1];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}