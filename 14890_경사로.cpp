#include <iostream>

using namespace std;

int n, l;
int board[101][101];
bool userunway[101][101];
int answer = 0;

void row_solve() {

	memset(userunway, false, sizeof(userunway));

	for (int i = 0; i < n; i++) {
		bool possible = true;
		for (int j = 0; j < n-1; j++) {

			if (board[i][j] != board[i][j + 1]) {
				int diff = board[i][j + 1] - board[i][j];
				if (abs(diff) > 1) {
					possible = false;
					break;
				}
				else {

					if (diff == 1) { //높이가 1차이로 올라갈 때

						if (userunway[i][j]) { //차이가 다른데 해당 행렬이 경사로를 사용하면
							possible = false;
							break;
						}
						int height = board[i][j];
						for (int k = j; k >= j - l + 1; k--) {
							if (k >= 0) {
								if (board[i][k] != height || userunway[i][k] == true) { //다른 행렬이 경사로를 사용하면
									possible = false;
									break;
								}
							}
							else {
								possible = false;
								break;
							}
						}
						if (possible) {
							for (int k = j; k >= j - l + 1; k--) {
								userunway[i][k] = true;
							}
						}
						else {
							break;
						}

					}
					else if (diff == -1) { //높이가 1차이로 내려갈 때
						int height = board[i][j+1];
						for (int k = j + 1; k < j + l + 1; k++) { //등호 빼야할듯
							if (k < n) {
								if (board[i][k] != height || userunway[i][k] == true) {
									possible = false;
									break;
								}
							}
							else {
								possible = false;
								break;
							}
						}

						if (possible) {
							for (int k = j; k < j + l + 1; k++) { //등호 빼야할 듯
								userunway[i][k] = true;
							}
						}
						else {
							break;
						}
					}

					
				}
			}



		}
		if (possible) {
			answer++;
		}
	}
}

void col_solve() {

	memset(userunway, false, sizeof(userunway));

	for (int j = 0; j < n; j++) {
		bool possible = true;
		for (int i = 0; i < n - 1; i++) {
			if (board[i][j] != board[i+1][j]) {
				int diff = board[i+1][j] - board[i][j];
				if (abs(diff) > 1) {
					possible = false;
					break;
				}
				else {
					if (diff == 1) { //높이가 1차이로 올라갈 때
						
						if (userunway[i][j]) { //차이가 다른데 해당 행렬이 경사로를 사용하면
							possible = false;
							break;
						}
						int height = board[i][j];

						for (int k = i; k >= i - l + 1; k--) {
							if (k >= 0) {
								if (board[k][j] != height || userunway[k][j] == true) { //다른 행렬이 경사로를 사용하면
									possible = false;
									break;
								}
							}
							else {
								possible = false;
								break;
							}
						}

						if (possible) {
							for (int k = i; k >= i - l + 1; k--) {
								userunway[k][j] = true;
							}
						}
						else {
							break;
						}

					}
					else if (diff == -1) { //높이가 1차이로 내려갈 때
						int height = board[i+1][j];
						for (int k = i + 1; k < i + l + 1; k++) {
							if (k < n) {
								if (board[k][j] != height || userunway[k][j] == true) {
									possible = false;
									break;
								}
							}
							else {
								possible = false;
								break;
							}
						}

						if (possible) {
							for (int k = i + 1; k < i + l + 1; k++) {
								userunway[k][j] = true;
							}
						}
						else {
							break;
						}
					}

				}
			}
		}
		if (possible) {
			answer++;
		}
	}
}
void input() {
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	row_solve();
	col_solve();
	cout << answer;
}