#include <iostream>
#include <algorithm>
using namespace std;

int temp;

int main() {
	ios_base::sync_with_stdio(0); //입출력 빠르게
	cin.tie(0);
	cout.tie(0);

	int array[5];

	for (int i = 0; i < 5; i++) {
		cin >> array[i];
	}

	while (1) {
		for (int i = 0; i < 4; i++) {
			if (array[i] > array[i + 1]) { 
				swap(array[i], array[i + 1]);

				int cnt = 0;
				for (int m = 0; m < 5; m++) {
					cout << array[m] << ' '; 
					if (array[m] == m + 1)
						cnt++;
				}
				cout << '\n';
				if (cnt == 5)
					return 0;
			}
		}
	}
		
}