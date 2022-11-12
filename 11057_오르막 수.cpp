#include <iostream>

using namespace std;

int dp[1001][1001];
int n;

int solution(int n) { //n = 2¶ó °¡Á¤

	for (int j = 2; j <= n; j++) {
		dp[j][0] = dp[j - 1][0];
		for (int k = 1; k <= 9; k++) {
			dp[j][k] = dp[j][k - 1] + dp[j - 1][k];
			dp[j][k] %= 10007;
		}
	}

	int sum = 0;
	for (int k = 0; k <= 9; k++) {
		sum += dp[n][k];
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);

	cin >> n;

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	if (n == 1) {
		cout << 10;
	}
	else {
		cout << solution(n) % 10007;
	}
}