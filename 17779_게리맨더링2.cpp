#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, x, y;

int board[21][21];
bool divide[21][21];

int group1 = 0;
int group2 = 0;
int group3 = 0;
int group4 = 0;
int group5 = 0;

int answer = 9999999;

void input() {
	cin >> n; //격자 크기

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j]; //격자 값
		}
	}
}

void solve() {

	for (int i = 1; i <= n - 2; i++) {
		for (int j = 2; j <= n - 1; j++) {
			x = i;
			y = j;
			for (int d1 = 1; d1 <= y - 1; d1++) {
				for (int d2 = 1; d2 <= n - y; d2++) {
					if (d1 + d2 <= n - x) {

					}
					else {
						continue;
					}

					vector <int> v;

					memset(divide, false, sizeof(divide));
					group1 = 0;
					group2 = 0;
					group3 = 0;
					group4 = 0;
					group5 = 0;

					for (int r = x, c = y; r <= x + d1, c >= y - d1; r++, c--) {
						divide[r][c] = true;
					}

					for (int r = x, c = y; r <= x + d2, c <= y + d2; r++, c++) {
						divide[r][c] = true;
					}

					for (int r = x + d1, c = y - d1; r <= x + d1 + d2, c <= y - d1 + d2; r++, c++) {
						divide[r][c] = true;
					}

					for (int r = x + d2, c = y + d2; r <= x + d1 + d2, c >= y + d2 - d1; r++, c--) {
						divide[r][c] = true;
					}

					int start_x = x + d1 - 1;
					int start_y = y - d1 + 1;

					int end_x = x + d2 - 1;
					int end_y = y + d2 - 1;

					int mid_x = x;
					int mid_y = y;



					for (int k = mid_x, p = mid_y; k <= start_x, p >= start_y; k++, p--) {


						int tmp = k;
						while (true) {
							int s = tmp + 1; //2
							if (divide[s][p] == false) {
								divide[s][p] = true;
							}
							else {
								break;
							}
							tmp++;
						}
					}


					for (int k = mid_x, p = mid_y; k <= end_x, p <= end_y; k++, p++) {

						int tmp = k;
						while (true) {
							int s = tmp + 1; //2
							if (divide[s][p] == false) {
								divide[s][p] = true;
							}
							else {
								break;
							}
							tmp++;
						}
					}


					for (int k = 1; k <= n; k++) {
						for (int p = 1; p <= n; p++) {
							if (divide[k][p]) {
								group5 += board[k][p];
							}
						}
					}

					v.push_back(group5);

					for (int k = 1; k < x + d1; k++) {
						for (int p = 1; p <= y; p++) {
							if (!divide[k][p]) {
								group1 += board[k][p];
							}
						}
					}
					v.push_back(group1);

					for (int k = 1; k <= x + d2; k++) {
						for (int p = y + 1; p <= n; p++) {
							if (!divide[k][p]) {
								group2 += board[k][p];
							}
						}
					}
					v.push_back(group2);


					for (int k = x + d1; k <= n; k++) {
						for (int p = 1; p < y - d1 + d2; p++) {
							if (!divide[k][p]) {
								group3 += board[k][p];
							}
						}
					}
					v.push_back(group3);

					for (int k = x + d2 + 1; k <= n; k++) {
						for (int p = y - d1 + d2; p <= n; p++) {
							if (!divide[k][p]) {
								group4 += board[k][p];
							}
						}
					}
					v.push_back(group4);


					sort(v.begin(), v.end());


					answer = min(answer, v[v.size() - 1] - v[0]);
				}
			}


		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	cout << answer << "\n";


}