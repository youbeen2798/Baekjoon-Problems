#include <iostream>

using namespace std;

long long num, cnt;
long long result;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> num >> cnt;

	if (cnt == 0) {
		cout << num - 1;
		return 0;
	}
	else {
		if (num == 2 || num == 3 || num == 4) {
			if (cnt % 2 != 0) {
				result = 8 * ( cnt-1) / 2 + 9 - num;
			}
			else {
				result = 8 * cnt / 2 + num - 1;
			}
		}
		else {
			if (num == 1) {
				result = 8 * cnt;
			}
			else {
				result = 8 * cnt + 4;
			}
		}
	}

	cout << result;
}