#include <iostream>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int left = 1;
	int right = 1;
	int answer = 0;

	cin >> n;

	int sum = 0;
	
	while (left <= right && right <= n+1) {
		if (sum > n) {
			sum -= left;
			left++;
		}
		else if (sum < n) {
			sum += right;
			right++;
		}
		else if (sum == n) {
			answer++;

			sum += right;
			right++;
		}	
	}

	cout << answer;
		
	return 0;

}