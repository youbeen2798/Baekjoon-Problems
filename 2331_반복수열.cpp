#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int input_num, p;
vector <int> v;
int sum = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> input_num >> p;

	v.push_back(input_num);

	int hello = input_num;

	while (1) {
		sum = 0;
		while (hello != 0) {
			int k = hello % 10;
			sum += pow(k, p); 
			hello /= 10;
		}
		v.push_back(sum);
		hello = sum;

		for (int i = 0; i < v.size() - 1; i++) {
			if (sum == v[i]) {
				cout << i << "\n";
				return 0;
			}
		}
	}
}