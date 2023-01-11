#include <iostream>

using namespace std;

int n;
int dp[1000001];

void solution() {

	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3]);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2]);
		}
		dp[i] += 1;
	}

	cout << dp[n];

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