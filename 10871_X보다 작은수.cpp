#include <iostream>

using namespace std;

int main() {
	int n, a;
	cin >> n >> a;
	int input[10000];
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < n; i++) {
		if (input[i] < a) {
			cout << input[i] << " ";
		}
	}

	return 0;

}