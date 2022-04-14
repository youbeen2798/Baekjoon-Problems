#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;

	int* array = new int[n]; //배열 동적할당

	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	sort(array, array + n); //오름차순 정렬

	for (int i = 0; i < n; i++) {
		cout << array[i] << "\n";
	}
}