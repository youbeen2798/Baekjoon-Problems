#include <iostream>
#include <vector>

using namespace std;

int T;
int n;
int dp[12] = { 0 };
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	while (T--) {
		cin >> n;

		cout << dp[n] << "\n";

	}
}