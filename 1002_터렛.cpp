#include <iostream>

using namespace std;

int x_1, y_1, r1, x_2, y_2, r2;
int t;

int main(void) {

	cin >> t;
	for (int test_case = 0; test_case < t; test_case++) {
		cin >> x_1 >> y_1 >> r1 >> x_2 >> y_2 >> r2;

		int dist = (x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2);

		int cond1 = (r1 - r2)* (r1 - r2);
		int cond2 = (r1 + r2) * (r1 + r2);

		if (x_1 == x_2 && y_1 == y_2) {
			if (cond1 == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (dist == cond1 || dist == cond2) {
			cout << 1 << "\n";
		}
		else if (cond1 < dist && dist < cond2) {
			cout << 2 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}