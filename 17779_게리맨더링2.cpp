#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[21][21];
int people_num[6];
int total_people_num = 0;
int x, y, d1, d2;
int ans = 9999999;

void one() {

	people_num[1] = 0;
	int now_x = x + d1;
	int now_y = y - d1;

	for (int i = 0; i <= d1; i++) {
		int x = now_x - i;
		int y = now_y + i;
		for (int r = x - 1; r >= 1; r--) {
			people_num[1] += arr[r][y];
		}
	}


	for (int c = 1; c < y - d1; c++) {
		for (int r = 1; r < x + d1; r++) {
			people_num[1] += arr[r][c];
		}
	}
}

void two() {

	people_num[2] = 0;

	int now_x = x;
	int now_y = y;

	for (int i = 1; i <= d2; i++) {
		int x = now_x + i;
		int y = now_y + i;
		for (int r = 1; r < x; r++) {
			people_num[2] += arr[r][y];
		}
	}

	for (int c = y + d2 + 1; c <= n; c++) {
		for (int r = 1; r <= x + d2; r++) {
			people_num[2] += arr[r][c];
		}
	}
}

void three() {

	people_num[3] = 0;

	int now_x = x + d1;
	int now_y = y - d1;

	for (int i = 0; i < d2; i++) {
		int x = now_x + i;
		int y = now_y + i;
		for (int r = x + 1; r <= n; r++) {
			people_num[3] += arr[r][y];
		}
	}

	for (int i = now_x; i <= n; i++) {
		for (int j = 1; j < now_y; j++) {
			people_num[3] += arr[i][j];
		}
	}

}

void four() {

	people_num[4] = 0;

	int now_x = x + d1 + d2;
	int now_y = y - d1 + d2;

	for (int i = 0; i <= d1; i++) {
		int x = now_x - i;
		int y = now_y + i;

		for (int r = x + 1; r <= n; r++) {
			people_num[4] += arr[r][y];
		}
	}

	
	for (int j = y + d2 + 1; j <= n; j++) {
		for (int i = x + d2 + 1; i <= n; i++) {
			people_num[4] += arr[i][j];
		}
	}
}

void five() {

	people_num[5] = total_people_num;

	for (int i = 1; i <= 4; i++) {
		people_num[5] -= people_num[i];
	}
}

void check_diff() {

	int mini = 9999999;
	int maxi = 0;

	for (int i = 1; i <= 5; i++) {
		mini = min(mini, people_num[i]);
		maxi = max(maxi, people_num[i]);
	}

	int diff = maxi - mini;

	ans = min(diff, ans);


}
void check(int x1, int y1) {

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= n - 1; j++) {
			d1 = i;
			d2 = j;
			one();
			two();
			three();
			four();
			five();
			check_diff();
		}
	}

}
void solution() {
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			x = i;
			y = j;
			check(i, j);
		}
	}

}

void input() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			total_people_num += arr[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	solution();

	cout << ans;
	
}
