#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];
int n;

int idx;
int dp_max;
int mx = 0;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = 1;

	for (int j = 2; j <= n; j++) { // j = 5
		idx = 0;
		dp_max = 0;
		for (int i = 1; i < j; i++) {
			if (arr[i] < arr[j] && dp_max < dp[i]) {
				idx = i; //idx = 4
				dp_max = dp[i]; //dp_max = 2
			}
		}
		if (idx == 0) {
			dp[j] = 1;
		}
		else {
			dp[j] = dp[idx] + 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}

	cout << "\n";

	for (int i = 1; i <= n; i++) {
		if (mx < dp[i])
			mx = dp[i];
	}

	cout << mx;
}