#include <iostream>

using namespace std;

int n;
int dp[100001][3];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	dp[1][0] = 1; //왼쪽 별
	dp[1][1] = 1; //오른쪽 별
	dp[1][2] = 1; //빈칸 2개

	for (int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i-1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
	}

	int ans = (dp[n][0] + dp[n][1] + dp[n][2]) %9901;
	cout << ans;
}