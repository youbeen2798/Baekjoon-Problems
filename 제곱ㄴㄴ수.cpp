#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;;

long long mini, maxi;

long long arr[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> mini >> maxi; //1 100


	for (int i = 0; i < 1000001; i++) {
		arr[i] = false;
	}

	for (long long i = 2; i * i <= maxi; i++) {

		long long n = mini / (i * i);

		if (mini % (i * i) != 0) {
			n++;
		}

		while (n * i * i <= maxi) {
			arr[n * i * i - mini] = true;
			n++;
		}
	}

	int cnt = 0;

	for (int i = 0; i <= maxi - mini; i++) {
		if (arr[i]) {

		}
		else {
			cnt++;
		}
	}

	cout << cnt;
}