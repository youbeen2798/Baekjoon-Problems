#include <iostream>

#define mod 1000000007

using namespace std;

long long a, x;

int pow(long long a, long long x) {
	if (x == 0) {
		return 1;
	}
	else {
		long long n = pow(a, x / 2);
		long long temp = (n * n) % mod;

		if (x % 2 == 0) {
			return temp;
		}
		else {
			return (temp * a) % mod;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> x;

	cout << pow(a % mod, x);

}