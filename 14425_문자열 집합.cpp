#include <iostream>
#include <set>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	set <string> s;

	string st;

	for (int i = 0; i < n; i++) {
		cin >> st;
		s.insert(st);
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> st;
		if (s.find(st) != s.end()) {
			cnt++;
		}
	}

	cout << "cnt: " << cnt;

}