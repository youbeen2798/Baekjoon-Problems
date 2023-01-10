#include <iostream>

using namespace std;

int n;
int arr[1001];
int sum[1001];
int ans = 0;

void solution() {

	for (int i = 0; i < n; i++) {
		sum[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && sum[j] + arr[i] > sum[i]) {
				sum[i] = sum[j] + arr[i];
			}
		}
		ans = max(ans, sum[i]);
	}

	cout << ans;
}
void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}
int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}