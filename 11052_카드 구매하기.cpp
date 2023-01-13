#include <iostream>

using namespace std;

int n;
int price[10001];
int dp[10001];

void solution() {

	for (int i = 1; i <= n; i++) {
		dp[i] = price[i]; //dp[3] = price[3]
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}

	cout << dp[n];
}

void input() {
	cin >> n; //4

	for (int i = 1; i <= n; i++) {
		cin >> price[i]; //1 5 6 7
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}