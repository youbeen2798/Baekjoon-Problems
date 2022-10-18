#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long n;
long long board[101][101];
long long dp[101][101];

int ans = 0;

void solution() {


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			for (int k = 0; k < i; k++) {
				if (k + board[k][j] == i) {
					dp[i][j] += dp[k][j];
				}
			}

			for (int k = 0; k < j; k++) {
				if (k + board[i][k] == j) {
					dp[i][j] += dp[i][k];
				}
			}
		}
	}
}
void input() {
	cin >> n;

	dp[0][0] = 1;
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
	solution();

	cout << dp[n - 1][n - 1];

}
