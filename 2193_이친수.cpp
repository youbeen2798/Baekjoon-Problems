#include <iostream>
#include <vector>
using namespace std;

int n;
long dp[100][2];

void solution() {

	dp[0][0] = 0;
	dp[0][1] = 1;

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[n - 1][0] + dp[n - 1][1];
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