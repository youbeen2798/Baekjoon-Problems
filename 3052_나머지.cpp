#include <iostream>

using namespace std;

int main() {

	int num;
	int rm[42] = { 0 };
	int count = 0;

	for (int i = 0; i < 10; i++) {
		cin >> num;
		rm[num % 42]++;
	}

	for (int i = 0; i < 42; i++) {
		if (rm[i] != 0) {
			count++;
		}
	}

	cout << count << endl;
	return 0;

}