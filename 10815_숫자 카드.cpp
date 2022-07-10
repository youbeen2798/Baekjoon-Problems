#include <iostream>
#include <set>
using namespace std;

int n, m, num;
int k;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	set <int> s;

	for (int i = 0; i < n; i++) {
		cin >> k;
		s.insert(k);
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> num;
		if (s.find(num) != s.end()) {
			cout << "1" << " ";
		}
		else {
			cout << "0" << " ";
		}
	}
}