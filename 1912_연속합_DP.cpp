//DP의 정석으로 푼 문제

#include <iostream>
#include <algorithm>
using namespace std;

int n;

int maxElement(int arr[], int size) { //배열의 최대원소 구하기
	int mx = arr[0];
	for (int i = 0; i < size; i++) {
		if (mx <= arr[i]) {
			mx = arr[i];
		}
	}
	return mx;
}

int maxPartSum(int arr[], int size) {
	int* dp = new int[size];

	dp[0] = arr[0];
	int tmp = arr[0];
	for (int i = 0; i < size; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		cout << dp[i] << ' ';
		tmp = max(tmp, dp[i]);
	}
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int* input = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> input[i]; //배열 입력받기
	}

	//	int size = _msize(input) / sizeof(*input);

	int mx = maxElement(input, n);

	if (mx < 0) {
		cout << mx;
		return 0;
	}
	else {
		cout << maxPartSum(input, n);
		return 0;
	}
}