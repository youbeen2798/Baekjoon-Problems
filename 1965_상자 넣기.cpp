#include <iostream>

using namespace std;

int n;
int input[1001];
int dp[1001];
int ans = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	dp[0] = 1;

	for (int i = 1; i < n; i++) {
		int maxi = 0;
		for (int j = 0; j < i; j++) {
			if (input[j] < input[i]) {
				maxi = max(dp[j], maxi);
			}
		}
		dp[i] = maxi + 1;
		ans = max(dp[i], ans);
	}

//	for (int i = 0; i < n; i++) {
//		cout << dp[i] << " ";
//	}

	cout << ans;
}