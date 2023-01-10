#include <iostream>

using namespace std;

int t;
int arr[2][100001];
int dp[2][100001];
int ans = 0;

void solution(int n) {

	if (n == 1) {
		ans = max(arr[0][0], arr[1][0]);
		return;
	}

	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];

	dp[0][1] = dp[1][0] + arr[0][1];
	dp[1][1] = dp[0][0] + arr[1][1];

	for (int i = 2; i < n; i++) {
//		cout << "i: " << i << " n: " << n << "\n";
		dp[0][i] = max(dp[1][i - 1], dp[1][i-2]) + arr[0][i];
		dp[1][i] = max(dp[0][i-1], dp[0][i-2]) +  arr[1][i];
	//	cout << "dp[0][i]: " << dp[0][i] << "\n";
	//	cout << "dp[1][i]: " << dp[1][i] << "\n";
	}
	
	ans = max(dp[0][n - 1], dp[1][ n - 1]);
//	cout << "solution" << "\n";
}

void input() {
	cin >> t;

	for (int test_case = 0; test_case < t; test_case++) {
//		cout << "test_case: " << test_case << "\n";
		
		int n;
		cin >> n;
		
		ans = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
//				cout << "i: " << i << " j: " << j << "\n";
				cin >> arr[i][j];
			}
		}
		
		solution(n);
		cout << ans << "\n";
		
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}