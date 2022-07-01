#include <iostream>

using namespace std;

long long a, b, c;

int pov(long long a, long long b, long long mod) {
	if (b == 0) {
		return 1;
	}
	else {
		long long n = pov(a, b / 2, mod);
		long long temp = n * n % mod;
		if (b % 2 == 0) {
			return temp;
		}
		else {
			return temp * a % mod;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	cout << pov(a%c, b, c);
}