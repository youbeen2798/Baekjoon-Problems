#include <iostream>

using namespace std;

int main() {
	int a;
	cin >> a;

	for (int i = 0; i < a; i++) {
		for (int k = 1; k < a-i; k++) {
			cout << " ";
		}
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}
