#include <iostream>
#include <cstring>
using namespace std;

int n;
int dp[100001];
int arr[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i * i <= n; i++) {
		arr[i*i] = 1;
	}


	for (int i = 1; i <= n; i++) {
		dp[i] = i;
	}

	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], arr[j*j] + dp[i - j * j]);
	//		cout << "i: " << i << " j: " << j << " dp: " << dp[i] << "\n";
		}
	//	cout << "dp[" << i << "]: " << dp[i] << "\n";
	}

	cout << dp[n];
}