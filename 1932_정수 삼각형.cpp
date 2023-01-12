#include <iostream>

using namespace std;

int n;
int arr[501][501];
int dp[501][501];
int ans = 0;
void solution() {

	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		dp[i][1] = dp[i - 1][1] + arr[i][1];

		for (int j = 2; j < i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
		dp[i][i] = dp[i - 1][i - 1] + arr[i][i];
	}

	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
}
void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		//i 
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j]; 
			//0 0
			//1 0 // 1 1
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