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

	vector <int> a(n);
	vector <int> b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());;

	/*
	for (int i = 0; i < n; i++) {
		cout <<  a[i] << " ";
	}

	cout << "\n";
	*/
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	sort(b.rbegin(), b.rend());

	/*
	for (int i = 0; i < n; i++) {
		cout << b[i];
	}
	*/

	int result = 0;

	for (int i = 0; i < n; i++) {
		result += a[i] * b[i];
	}

	cout << result;
}