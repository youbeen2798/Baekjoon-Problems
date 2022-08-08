#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector <int> v;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}

	sort(v.begin(), v.end());

	long long answer = 0;

	for (int i = 1; i <= n; i++) {
		answer += abs(i - v[i - 1]);
	}

	cout << answer;
}