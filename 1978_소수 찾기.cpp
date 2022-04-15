#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector <bool> premium(int n) {

	vector <bool> v(n + 1);

	v[0] = 1;
	v[1] = 1;

	for (int i = 2; i <= sqrt(n); i++) {
		if (v[i] == 1) {
			continue;
		}
		for (int j = 2*i; j <= n; j += i) {
			v[j] = 1;
		}
	}

	return v;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int* array = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	sort(array, array + n);

	int m = array[n - 1];
	vector <bool> vt;

	vt = premium(m);
	
	for (int i = 0; i < vt.size(); i++) {
		cout << vt[i];
	}

	cout << "\n";

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (vt[array[i]] == 0) {
			count++;
		}
	}

	cout << count;
}