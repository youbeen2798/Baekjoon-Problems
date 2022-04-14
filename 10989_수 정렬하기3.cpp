#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cnt[10001] = { 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cnt[num]++;
	}

	for (int i = 1; i <= 10000; i++) {
		while (cnt[i] > 0) {
			cout << i << "\n";
			cnt[i]--;
		}
	}
}