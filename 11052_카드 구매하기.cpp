#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1001];

int arr[10001];
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], arr[j] + dp[i - j]); 
		}
	}
	
	cout << dp[n];
}