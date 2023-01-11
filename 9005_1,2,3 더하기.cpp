#include <iostream>

using namespace std;

int t, n;
int arr[11]; 
int dp[11];
void solution() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
}

void input() {
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	input();
}