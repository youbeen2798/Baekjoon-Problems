#include <iostream>

using namespace std;
int coin[101];
int dp[100001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	fill(dp, dp + 100001, 100001);
	dp[0] = 0;

	for (int i = 1; i <= n; i++)
		cin >> coin[i];
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j- coin[i]] + 1);
		}
	}
	if (dp[k] == 100001)
		cout << "-1";
	else
		cout << dp[k];
	
}
