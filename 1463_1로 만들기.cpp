#include <iostream>

using namespace std;

int n;
int dp[1000000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	cin >> n;	
	
	if (0 <= n && n <= 3) {
		cout << dp[n];
		return 0;
	}
	else {
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + 1;
			if (i % 2 == 0) {
				dp[i] = min(dp[i], 1 + dp[i / 2]);
			}
			if (i % 3 == 0) {
				dp[i] = min(dp[i], 1 + dp[i / 3]);
			}
		}
	}

	cout << dp[n];


}