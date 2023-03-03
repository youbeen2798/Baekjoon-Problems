#include <iostream>
#include <vector>

using namespace std;

int r, c, t;
int arr[51][51];
int plus_arr[51][51];

vector<pair<int, int>> air_freshes;

pair<int, int> air_fresh1; //공기 청정기1
pair<int, int> air_fresh2; //공기 청정기2

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void real_dust_spread(int x, int y) {

	int cnt = 0;
	int total_dist = arr[x][y];

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		//공기 청정기이면
		if (0 <= nx && nx < r && 0 <= ny && ny < c && arr[nx][ny] != -1) {
			plus_arr[nx][ny] += total_dist / 5;
			cnt++;
		}
	}

	plus_arr[x][y] -= (total_dist / 5) * cnt;
}

void real_spread() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] += plus_arr[i][j];
		}
	}
}


void dust_spread() {

	memset(plus_arr, 0, sizeof(plus_arr));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			real_dust_spread(i, j);
		}
	}

	real_spread();
}

void air_fresh1_work() {

	int air_fresh1_x = air_fresh1.first;
	int air_fresh1_y = air_fresh1.second;

	//아래로
	for (int i = air_fresh1_x - 2; i >= 0; i--) {
		arr[i + 1][0] = arr[i][0];
	}


	//왼쪽으로
	for (int j = 1; j < c; j++) {
		arr[0][j - 1] = arr[0][j];
	}	


	//위쪽으로
	for (int i = 1; i <= air_fresh1_x; i++) {
		arr[i - 1][c - 1] = arr[i][c - 1];
	}

	
	//오른쪽으로
	for (int j = c - 1; j >= 2; j--) {
		arr[air_fresh1_x][j] = arr[air_fresh1_x][j - 1];
	}


	arr[air_fresh1_x][air_fresh1_y + 1] = 0;
}

void air_fresh2_work() {

	int air_fresh2_x = air_freshes[1].first;
	int air_fresh2_y = air_freshes[1].second;

	//위쪽으로
	for (int i = air_fresh2_x + 1; i < r - 1; i++) {
		arr[i][0] = arr[i + 1][0];
	}

	//왼쪽으로
	for (int j = 0; j < c - 1; j++) {
		arr[r - 1][j] = arr[r - 1][j + 1];
	}

	//아래로
	for (int i = r - 1; i > air_fresh2_x; i--) {
		arr[i][c - 1] = arr[i - 1][c - 1];
	}

	//오른쪽으로
	for (int j = c; j >= 2; j--) {
		arr[air_fresh2_x][j] = arr[air_fresh2_x][j - 1];
	}
	arr[air_fresh2_x][air_fresh2_y + 1] = 0;
}
void air_fresh_work() {
	//공기 청정기 작동

	air_fresh1_work();
	air_fresh2_work();
}

void output() {
	
	int ans = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != -1) {
				ans += arr[i][j];
			}
		}
	}

	cout << ans;
}
void solution() {

	
	for (int i = 0; i < t; i++) {
		dust_spread();
		air_fresh_work();
	}

	output();
}

void input() {
	cin >> r >> c >> t;
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				air_freshes.push_back({ i,j });
			}
		}
	}

	air_fresh1 = air_freshes[0];
	air_fresh2 = air_freshes[1];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}