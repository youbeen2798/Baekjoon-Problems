#include <iostream>

using namespace std;

int n;
int arr[10001];
int dp[10001];

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}
void solution() {
	dp[0] = 0;
	dp[1] = arr[1] - arr[0];

	int max_val = max(arr[1], arr[0]);
	int min_val = min(arr[1], arr[0]);

	// 0 2 2 => a = 0, b = 0 
	for (int i = 2; i < n; i++) {
		int a = dp[i - 1];

		//기존 그룹에 합류되는 경우
		if (arr[i] > max_val) {
			a += arr[i] - max_val;
		}
		else if (arr[i] < min_val) {
			a += min_val - arr[i];
		}

		//기존 그룹에 합류되지 않는 경우
		int b = dp[i - 2] + abs(arr[i] - arr[i - 1]);
		
		//기존 그룹에 합류된다면 무조건
		if (a > b) {
			dp[i] = a;
			if (arr[i] > max_val) {
				max_val = arr[i];
			}
			else {
				min_val = arr[i];
			}
		}
		else {
			dp[i] = b;
			min_val = min(arr[i], arr[i - 1]);
			max_val = max(arr[i], arr[i - 1]);
		}
	
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	cout << dp[n - 1]; 

}