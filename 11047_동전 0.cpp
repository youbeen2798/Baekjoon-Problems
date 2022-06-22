#include <iostream>

using namespace std;

int n, money;
int cnt = 0;
int main() {

	cin >> n >> money;

	int* coin = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		int k = money / coin[i]; 
		cnt += k;
		money = money % coin[i]; 
	}

	cout << cnt;
}
