#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int *p;
	int arr_size;
	cin >> arr_size;
	p = new int[arr_size];
	for (int i = 0; i < arr_size; i++) {
		cin >> p[i];
	}
	int max = p[0];
	int min = p[0];
	for (int i = 0; i < arr_size; i++) {
		if(p[i] >= max){
			max = p[i];		
		}
		if (p[i] <= min) {
			min = p[i];
		}
	}
	cout << min << " " << max;
	return 0;
}