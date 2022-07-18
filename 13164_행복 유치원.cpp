#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	vector <int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i]; // 1 3 5 6 10
	}

	int ans = v[v.size() - 1] - v[0]; // 9(10-1)

	vector <int> diff(n - 1);

	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		diff[i] = v[i + 1] - v[i];
		sum += diff[i];
	}

	/*
	for (int i = 0; i < diff.size(); i++) {
		cout << diff[i] << " ";
	}
	*/

	sort(diff.rbegin(), diff.rend());

	for (int i = 0; i < k-1; i++) {
		sum -= diff[i];
	}

	cout << "sum: " << sum;

	
}