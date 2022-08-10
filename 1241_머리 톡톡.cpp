#include <iostream>
#include <vector>
using namespace std;

int n;
int maxx = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector <int> arr(n);
	vector <int> res(n);
	vector <int> num;

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; // 3 3 4 5 9
		maxx = max(arr[i], maxx);
	}

	num.resize(maxx + 1);

	for (int i = 0; i < n; i++) {
		num[arr[i]]++;
	}

	cout << "***" << "\n";

	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << " ";
	}

	cout << "\n";

	for (int i = 0; i < n; i++) {
		for (int k = 1; k * k <= arr[i]; k++) {
			if (arr[i] % k == 0) {
				if (arr[i] / k != k) {
					res[i] += num[arr[i] / k] + num[k];
				}
				else if (arr[i] / k == k) {
					res[i] += num[k];
				}
			}
		}

		cout << res[i] - 1 << "\n";
	}

}