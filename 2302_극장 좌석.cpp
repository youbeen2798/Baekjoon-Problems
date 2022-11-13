#include <iostream>

using namespace std;

int n, m;
int num;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int dp[41] = { 1,1,2};

	for (int i = 3; i <= 41; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int idx = 1;
	int ans = 1;

	for (int i = 0; i < m; i++) {
		cin >> num; //7
		ans *= dp[num - idx]; //dp[2]
		idx = num + 1; //8
	}

	ans *= dp[n + 1 - idx];

	cout << ans;
}