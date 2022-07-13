#include <iostream>
#include <algorithm>
using namespace std;

int n;
int k;
int result = 0;
int arr[2000];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);



	for (int i = 0; i < n; i++) {
		int val = arr[i];

		int l = 0;
		int r = n - 1;

		while (l < r) {
			int sum = arr[l] + arr[r];

			if (sum == val) {
				if (l != i && r != i) {
					result++;
					break;
				}
				else if (l == i) {
					l++;
				}
				else if (r == i) {
					r--;
				}
			}
			else if (sum < val) {
				l++;
			}
			else if (sum > val) {
				r--;
			}
		}
	}

	cout << result;
}