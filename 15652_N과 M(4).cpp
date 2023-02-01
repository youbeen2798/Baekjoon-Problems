#include <iostream>

using namespace std;

int n, m;
int d = 1;
int arr[9];

void input() {
	cin >> n >> m;
}

void func(int k){
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = d; i <= n; i++) {
		arr[k] = i;
		d = i;
		func(k + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	func(0);
}