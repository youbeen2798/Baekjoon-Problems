#include <iostream>
using namespace std;

int main() {
	int array[9];
	int max_value = 0;
	int max_index = 0;
	for (int i = 0; i < 9; i++) {
		cin >> array[i];
		
		if (array[i] > max_value) {
			max_value = array[i];
			max_index = i;
		}
	}
	cout << max_value << "\n" << max_index + 1;

	
	return 0;
}