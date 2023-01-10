#include <iostream>

using namespace std;

int n;
int arr[10001];
int dp[10001];

void solution() {

	if (n == 1) {
		cout << arr[1];
		return;
	}
	else if (n == 2) {
		cout << arr[1] + arr[2];
		return;
	}
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]), dp[i - 1]);
	}
//	cout << "##dp[1]: " << dp[1] << "\n";
//	for (int i = 0; i < n; i++) {
//		cout << "i: " << i << " dp[i]: " << dp[i] << "\n";
//	}
	cout << dp[n ];
}

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}