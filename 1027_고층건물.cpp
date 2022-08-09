#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int building[51];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector <int> cnt(n);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		building[i] = k;
	}

	/*
	for (int i = 0; i < n; i++) {
		cout << building[i] << " ";
	}
	cout << "\n"; */

	for (int i = 0; i < n; i++) {
		cout << "i: " << i << "\n";
		double mini = -1000000001;

		for (int j = i + 1; j < n; j++) {
			int height = building[j] - building[i];
			int width = j - i;
			double k = height * 1.0 / width;

			if (k > mini) {
//				cout << "k: " << k << "\n";
				mini = k;
				cnt[i]++;
				cnt[j]++;
			}
		}
	}

	cout << *max_element(cnt.begin(), cnt.end());
}