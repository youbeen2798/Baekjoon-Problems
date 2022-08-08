#include <iostream>

using namespace std;

int t;
int x_1, y_1, x_2, y_2;
int n;
int cx, cy, r;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;


	for (int test_case = 0; test_case < t; test_case++) {
		int answer = 0;
		cin >> x_1 >> y_1 >> x_2 >> y_2;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> cx >> cy >> r;

			int dist1 = (x_1 - cx) * (x_1 - cx) + (y_1 - cy) * (y_1 - cy);
			int dist2 = (x_2 - cx) * (x_2 - cx) + (y_2 - cy) * (y_2 - cy);
			int radius = r * r;

			if (dist1 <= radius && dist2 > radius) {
				answer++;
			}
			if (dist1 > radius && dist2 <= radius) {
				answer++;
			}
		}			
		cout << answer << "\n";
	}
}