#include <iostream>

using namespace std;

int n, m;
int num;
int a;
int b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int* arr = new int[n+1];

	arr[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> num;
		arr[i] = arr[i - 1] + num;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << arr[b] - arr[a - 1] << "\n";
	}
}