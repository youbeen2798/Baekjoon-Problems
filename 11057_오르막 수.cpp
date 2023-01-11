#include <iostream>
#define N 10007

using namespace std;

int dp[1001][10];
int n;

void solution() {

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % N;
		}
	}

	long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += dp[n][i];
	}

	cout << ans % N;
}

void input() {
	cin >> n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}