#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (1) {
		int r = a % b;
		if (r == 0) {
			return b;
		}
		a = b;
		b = r;
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int a, b, k, m;
	int gcf; //ÃÖ´ë°ø¾à¼ö
	int lcm; //ÃÖ¼Ò°ø¹è¼ö
	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		gcf = gcd(a, b);
		k = a / gcf;
		m = b / gcf;

		cout << gcf * k * m << "\n";
	}
}
