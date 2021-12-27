#include <iostream>

using namespace std;

int main() {

	int a;
	int sum = 0;
	cin >> a;
	for (int i = 1; i < a+1; i++) {
		sum += i;
	}
	cout << sum;

	return 0;
}