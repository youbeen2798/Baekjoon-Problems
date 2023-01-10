#include <iostream>

using namespace std;

int n;
int arr[1001];
int dp[1001];
int ans = 0;

void solution() {

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j <= i; j++) {
			if (arr[j] > arr[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
}

void output() {
	cout << ans;
}

void input() {
	cin >> n; //6

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; //10 30 10 20 20 10
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	output();
}